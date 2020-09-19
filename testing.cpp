// digits.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<cstdio>
#include<cstdlib>
//#include<cstring>
#include<conio.h>
#include<math.h>
#include "testing.h"

#define P 12
#define N 5  // Number of states
#define M 32 // Number of distinct observations in each state
#define T 700 // Total time or Number of observations in a sequence.


using namespace std;

string words[4][13] = { {"begin","end"},{"car","bike","end"},{"alto","ciaz","creta","jeep","end"},{"activa","apache","passion","pulsar","end"} };


long double samples[100000];  //Global array to store samples from input file.
int counter = 0;             // Global variable to store the total count of values 
long double maxx = 0;		 // Global varaiable to find absolute maximum value of amplitude present in intput file.
long double hwindow[321];    // Global array to store hamming window weights. 
long double rswindow[13];    // Global array to store raised sine window weights.
long double frame[320];      // Array to store frame under consideration for calculation.
long double ri[P + 1];		 // Array to store Ri values.
long double ai[P + 1];		 // Array to store Ai values.
long double ci[600][P + 1];	 // 2D Array to store Ci values of frames.
long double alpha[P + 1][P + 1]; // 2D array to store alpha values used to calculate Ci's. 
long double k[P + 1];			 // Array to store K values used intermediately to calculate value of Ci's.
long double energy[P + 1];	 // Array to store energy used to calculate Ci's.
long double stenergy[1000];  // Array to store energy of frames of input file.
long double codebook[33][13]; //2D array to store codebook
long double oenergy[200];
int start_frame = 0, end_frame = 0, total_frames = 0;//variables to store frame markers
long double tokhuraswght[13] = { 0.0, 1.0, 3.0, 7.0, 13.0, 19.0, 22.0, 25.0, 33.0, 42.0, 50.0, 56.0, 61.0 }; // Array to store tokhura's weight.
long double A[N + 1][N + 1];        //A Matrix to store transition Probabilities
long double AvgA[N + 1][N + 1];     //Matrix to store average A matrix
long double B[N + 1][M + 1];         //B Matrix to store observation probability distribution
long double AvgB[N + 1][M + 1];     //Matrix to store average B matrix
long double PI[N + 1];           // PI Matrix to store initial state distribution probabilities
int OBS[T + 1];                  //matrix to store observation sequence 1


long double HMMalpha[T + 1][N + 1]; // alpha matrix 
long double beta[T + 1][N + 1];  // beta natrix
long double gamma[T + 1][N + 1]; // gamma matrix
long double delta[T + 1][N + 1]; //delta matrtix
long double xi[T + 1][N + 1][N + 1]; // Xi matrix
long double abar[N + 1][N + 1];  // re-estimated A matrix
long double bbar[N + 1][M + 1];  // re-estimated B matrix
long double pibar[N + 1];      // re-estimated PI matrix
int psi[T + 1][N + 1]; // Psi matrix to store states
int qt[T + 1];  //matrix to store state sequence (based on gamma matrix)
int qtstar[T + 1]; //matrix to store state sequence (based on Viterbi Algorithm)
long double Prob_O_Given_Lamda = 0.0, Prob_O_Given_Lamda_new = 0.0; // variables to store probabilities of the observation sequence given model Lambda
long double pstar, old_pstar = 0; //variable to store the quality of the model
int qstar; //variable to store the final state in state sequence
int iterations = 1; // counter to keep a track of iterations
int accuracy = 0; // variable used to calculate recognize accuracy


//Function to read all the values from input file and also calculate absolute maximum value.

void vehicle :: testing :: readSamples(string fname) {
	counter = 0;
	maxx = 0;
	//system("Recording_Module.exe 3 input_file.wav input_file.txt");
	FILE* filepointer;
	//cout<<endl<<"file name: "<<fname<<endl;
	//printf("\n\nfile name: %s",fname);
	filepointer = fopen(fname.c_str(), "r");
	if (filepointer == NULL) printf("\nInput file could not be opened.\n");
	else {
		//printf("\nInput sample file read."); 
		long double val = 0;
		while (fscanf(filepointer, "%Lf", &val) == 1) {
			samples[counter] = val;
			counter++;
		}
	}

	fclose(filepointer);
	//printf("\ncount: %d",counter);
	//printf("\nmaximum: %Lf",maxx);
}

//Function to calculate DC shift using ambient noise text file as input.

long double vehicle :: testing :: calDCShift(string noisefile) {
	FILE* fp;
	fp = fopen(noisefile.c_str(), "r");
	long double val = 0;
	long double sum = 0;
	long double dcount = 0;
	if (fp == NULL) printf("%s noise File could not be opened.\n", noisefile.c_str());
	else {
		//printf("Ambient noise file read.\n");
		while (fscanf(fp, "%Lf", &val) == 1) {
			sum = sum + val;
			dcount++;
		}
		sum = sum / dcount;
	}
	//printf("DC_shift: %Lf\n",sum);
	fclose(fp);
	return sum;
}

//Function to perform DC shift on the array where all the sample values of yes/no input text file is stored.

void vehicle::testing:: pDCShift(long double dcs) {
	int i;
	for (i = 0; i < counter; i++) {
		samples[i] -= dcs;
	}
	//maxx -= dcs;

}

//Function to normalize the input data stored in the array.
//Function 1st calculates a scaling factor. This scaling factor is then multiplied with each value in the array which stores the input file.

void vehicle::testing:: normalization() {
	long double val = samples[0];
	for (int i = 1; i < counter; i++) {
		val = samples[i];
		if (val < 0.0) {
			val = 0.0 - val;
		}
		if (val > maxx) {
			maxx = val;
		}
	}
	//printf("\nMaxx: %Lf\n",maxx);
	long double sf; //scaling factor
	sf = 5000 / maxx;
	//printf("SF: %Lf\n",sf);
	int i;
	for (i = 0; i < counter; i++) {
		samples[i] = samples[i] * sf;
	}

}

//Function to calculate Short Term Energy 
long double vehicle::testing:: calSTEnergy(int start, int end) {
	//printf("Start: %d End : %d\n",start,end);
	int i;
	long double energy = 0;
	long double val;
	for (i = start; i <= end; i++) {
		val = samples[i];
		//printf("%Lf\n",val);
		val = val * val;
		energy += val;
	}
	energy = energy / (end - start + 1);
	//printf("Energy: %Lf\n",energy);
	return energy;
}

//Function to Initialize Input file (reading and trimming of input)
void vehicle::testing:: initializeInput(string fname, string noiseFile) {
	readSamples(fname);
	long double dc; //variable to store dc shift value.
	int total_frames = 0; //variable to store the total number of frames(size of 320 samples) in the input file
	dc = calDCShift(noiseFile); //Function call to calculate DC shift from ambient noise text file.
	pDCShift(dc); //Function call to perform DC shift on array storing input data.
	normalization(); //Function call to normalize the input data stored in array.
	total_frames = counter / 320; // Calculating total number of frames.
	int j = 0, start, end;
	stenergy[0] = 0;
	//Loop to calculate Short Term Energy for every frame.
	for (j = 0; j < total_frames; j++) {
		start = 320 * j;
		end = start + 319;
		stenergy[j] = calSTEnergy(start, end);
		//printf("Frame No: %d    Energy: %Lf\n",j,stenergy[j]);
	}


	//trimming input
	start_frame = 0, end_frame = 0;
	for (int a = 40; a < total_frames - 1; a++) {
		//printf("rrr %Lf\n",(energy[a+1]/energy[a]));
		if (stenergy[a + 1] / stenergy[a] >= 10 && stenergy[a + 1] > 500 && stenergy[a + 2] > stenergy[a + 1])
		{
			start_frame = a + 1;
			break;
		}
	}
	for (int a = total_frames - 1; a > 0; a--) {
		if (stenergy[a] > 650 && stenergy[a - 1] > stenergy[a]) {
			//printf("\n%d\n",a);
			end_frame = a - 1;
			break;
		}
	}
	printf("\nStart: %d   End: %d\n", start_frame, end_frame);
	printf("\nTotal Frames : %d\n", end_frame - start_frame + 1);
	//getch();
}

//Function to load Hamming Window into an array.
void vehicle::testing:: loadHammingWindow() {
	int i;
	FILE* filepointer;
	filepointer = fopen("InputFiles\\hamming_window.txt", "r");
	if (filepointer == NULL) printf("Hamming window file could not be opened \n");
	//else printf("Hamming window file read \n");
	long double val = 0;
	for (i = 0; i < 320; i++) {
		fscanf(filepointer, "%Lf", &val);
		hwindow[i] = val;
	}
	fclose(filepointer);
}

//Function to load raised sine window into an array.
void vehicle::testing:: loadRSWindow() {
	int i;
	FILE* filepointer;
	filepointer = fopen("InputFiles\\raised_sine_window.txt", "r");
	if (filepointer == NULL) printf("Raised Sine Window File could not be opened \n");
	//else printf("Raised Sine Window file Opened.\n");
	long double val = 0;
	for (i = 1; i < 13; i++) {
		fscanf(filepointer, "%Lf", &val);
		rswindow[i] = val;
	}
	fclose(filepointer);
}

//Function to apply hamming window on a frame.
void vehicle::testing:: applyHammingWindow(int s) {
	int i;
	for (i = 0; i < 320; i++) {
		frame[i] = samples[s + i];
		frame[i] *= hwindow[i];
		//printf("\n hamm %Lf ",frame[i]);
	}
}



//Function to calculate values of Ri's.
void vehicle::testing:: calris() {
	int i, j;
	long double sum;
	for (i = 0; i < P + 1; i++) {
		sum = 0;
		for (j = 0; j < 320 - i; j++) {
			sum += frame[j] * frame[j + i];
		}
		ri[i] = sum;
		//printf("\n %Lf",ri[i]);
	}
	/*
	printf("\n Values of Ri's:\n");
	for(j=0;j<P+1;j++){
		printf("\n %Lf",ri[j]);
	}
	*/

}

//Function to calculate values of Ai's.
void vehicle::testing:: calais() {
	int i, j;
	energy[0] = ri[0];
	k[0] = ri[0];
	alpha[0][0] = k[0];
	long double sum;
	for (i = 1; i <= P; i++) {
		sum = 0.0;
		for (j = 1; j < i; j++) {
			sum = sum + (alpha[j][i - 1] * ri[i - j]);
		}
		k[i] = (ri[i] - sum) / energy[i - 1];
		alpha[i][i] = k[i];
		energy[i] = (1 - k[i] * k[i]) * energy[i - 1];
		for (j = 1; j < i; j++) {
			alpha[j][i] = alpha[j][i - 1] - (k[i] * alpha[i - j][i - 1]);
		}
	}
	//printf("\n\n Values of Ai's\n");
	for (j = 1; j <= P; j++) {
		ai[j] = alpha[j][P];
		//printf("\n ai %d : %Lf",j,ai[j]);
	}

}

//Function to calculate values of Ci's.
void vehicle::testing:: calcis(int index) {
	int i, j;
	long double sum;
	for (i = 1; i < P + 1; i++) {
		sum = 0.0;
		for (j = 1; j < i; j++) {
			sum += ((double)j / i) * ci[index][j] * ai[i - j];
		}
		ci[index][i] = ai[i] + sum;
		//printf("\n ci %d : %Lf",i,ci[index][i]);
	}
	/*printf("\n\n Values of Ci's\n");
	for(j=1;j<P+1;j++){
		printf("\n ci %d : %Lf",j,ci[inx][j]);
	}
	*/
}


//Function to apply raised sine window on Ci's.
void vehicle::testing:: applyRSWindow(int index) {
	//printf("\nIndex: %d\n",index);
	int i;
	FILE* fp;
	fp = fopen("Ci_temp.txt", "a");
	for (i = 1; i < 13; i++) {
		ci[index][i] *= rswindow[i];
		fprintf(fp, "%Lf\t", ci[index][i]);
		//printf("ci %d : %Lf\n",i,ci[index][i]);
	}
	fprintf(fp, "\n");
	fclose(fp);
}


//Function to calculate overlapped frames and calculate Cis of respective frames
void vehicle::testing:: calculateCis() {
	int start, end, end_sample = (end_frame * 320) + 319;
	start = 320 * start_frame;
	end = start + 319;
	total_frames = 1;
	int j = 0;
	int index = 1, obs;
	//stenergy[j] = calSTEnergy(start,end);
	//printf("\nStart: %d\n",start);
	//printf("End: %d\n",end_sample);
	while (end <= end_sample)
	{
		//printf("Start: %d    End: %d\n",start,end);
		total_frames++;
		applyHammingWindow(start);
		calris();
		calais();
		calcis(index);
		applyRSWindow(index);
		//obs = findTokhuraDist(index);
		//printf("\n %d %d ",index,obs);
		index++;
		//oenergy[j] = calSTEnergy(start,end);
		//printf("Frame No: %d    Energy: %Lf\n",j,oenergy[j]);
		j++;
		start = end - 239; //overlapping of frames by 240 samples
		end = start + 319;
		//printf("Index %d Start: %d    End: %d\n",index,start,end);
	}
	total_frames--;
	/*if (total_frames>150){
		total_frames = 150;
	}*/
	printf("\nTotal overlapped frames: %d", total_frames);
	//getch();
	/*
	for(int f=1;f<=total_frames;f++){
		printf("\n");
		for(int r=1;r<=12;r++){
			printf("%Lf\t",ci[f][r]);
		}
	}
	*/
	//printf("\n\n\nIndex: %d\n\n\n",index-1);
}

//Function to load codebook into 2D array
void vehicle::testing:: loadCodebook() {
	FILE* filepointer;
	//printf("\n\nfile name: %s",fname);
	filepointer = fopen("InputFiles\\codebook.txt", "r");
	if (filepointer == NULL) printf("\nInput file could not be opened.\n");
	else {
		//printf("\nCodebook file read."); 
		long double val = 0;
		int row = 1, col = 1;
		while (fscanf(filepointer, "%Lf", &val) == 1) {
			codebook[row][col] = val;
			//printf("%Lf ",codebook[row][col]);
			col++;
			if (col == 13) {
				//printf("\n");
				row++;
				col = 1;
			}
		}
	}
}

//Function to generate observation sequence
void vehicle::testing:: generateObservationSequence() {
	int i, m, minIndex, index;
	long double dsum, diff, mindist;
	FILE* fp;
	fp = fopen("Models\\obs_seq.txt", "w");
	for (index = 1; index <= total_frames; index++) {
		minIndex = 1;
		mindist = 100000000.0;
		for (i = 1; i <= 32; i++) {
			diff = 0.0;
			dsum = 0.0;
			for (m = 1; m <= P; m++) {
				diff = ci[index][m] - codebook[i][m];
				diff = diff * diff;
				dsum += tokhuraswght[m] * diff;
			}
			if (dsum < mindist) {
				mindist = dsum;
				minIndex = i;
			}

		}
		//printf("\n %d  %d",index,minIndex);
		fprintf(fp, "%d\n", minIndex);
	}
	fclose(fp);
}


//Function to read initial HMM models
void vehicle::testing:: readInitialModels(string fname1, string fname2, char* fname3, char* fname4) {
	int row = 1;
	int col = 1;
	int i = 1;
	FILE* filepointer;
	printf("\nFile name: %s",fname1.c_str());
	filepointer = fopen(fname1.c_str(), "r");
	if (filepointer == NULL) printf("\n%s could not be opened.\n", fname1);
	else {
		printf("\n %s read.",fname1.c_str()); 
		long double val = 0;
		for (row = 1; row <= N; row++) {
			for (col = 1; col <= N; col++) {
				fscanf(filepointer, "%Lf", &val);
				//printf("%Lf\n",val);
				A[row][col] = val;
			}
		}
	}
	fclose(filepointer);

	//printf("\nFile name: %s",fname2.c_str());
	filepointer = fopen(fname2.c_str(), "r");
	if (filepointer == NULL) printf("\n %s could not be opened.\n", fname2);
	else {
		//printf("\n %s read.",fname2); 
		long double val = 0;
		for (row = 1; row <= N; row++) {
			for (col = 1; col <= M; col++) {
				fscanf(filepointer, "%Lf", &val);
				B[row][col] = val;
			}
		}
	}
	fclose(filepointer);

	//printf("\nFile name: %s",fname3);
	filepointer = fopen(fname3, "r");
	if (filepointer == NULL) printf("\n %s could not be opened.\n", fname3);
	else {
		//printf("\n %s read.",fname3); 
		long double val = 0;
		for (row = 1; row <= N; row++) {
			fscanf(filepointer, "%Lf", &val);
			PI[row] = val;
		}
	}
	fclose(filepointer);

	//printf("\nFile name: %s",fname4);
	filepointer = fopen(fname4, "r");
	if (filepointer == NULL) printf("\n %s could not be opened.\n", fname4);
	else {
		//printf("\n %s read.",fname4); 
		int val = 0;
		for (row = 1; row <= total_frames; row++) {
			fscanf(filepointer, "%d", &val);
			OBS[row] = val;
		}
	}
	fclose(filepointer);
	//printf("\nInitial Model Read.\n");
}

//--------------------------------------- ----------------------------Solution to Problem 1--------------------------------------------------------------------------------

//Forward Procedure
//function to calculate the alpha matrix
long double vehicle::testing:: calculatingAlpha(long double a[6][6], long double b[6][33], long double p[]) {
	int i, t, j;
	//printf("here\n");
	//printf("\nA Matrix\n");
	/*
	for(i=1;i<=N;i++){
		printf("\n");
		for(j=1;j<=N;j++){
			printf("%0.150Lf\n",a[i][j]);
		}
	}
	printf("\nB Matrix\n");
	for(i=1;i<=N;i++){
		printf("\n");
		for(j=1;j<=M;j++){
			printf("%0.150Lf\n",b[i][j]);
		}
	}
	*/
	long double sum = 0.0, ret_val = 0.0;
	//Initialization
	for (i = 1; i <= N; i++) {
		HMMalpha[1][i] = p[i] * b[i][OBS[1]];
		//printf("\n %Lf",alpha[1][i]);
	}
	//Induction
	for (t = 1; t <= total_frames - 1; t++) {
		for (j = 1; j <= N; j++) {
			sum = 0.0;
			for (i = 1; i <= N; i++) {
				sum += HMMalpha[t][i] * a[i][j];
			}
			//printf("\n %Lf",sum);
			HMMalpha[t + 1][j] = sum * b[j][OBS[t + 1]];
			//printf("\n    %Lf",alpha[t][j]);
		}
	}
	//Calculation of Probability of observation sequence given the model Lambda
	for (i = 1; i <= N; i++) {
		//printf("\n%0.300Lf",alpha[T-1][i]);
		ret_val += HMMalpha[total_frames][i];
	}
	//printf("P:%0.150Lf",Prob_O_Given_Lamda);
	return ret_val;
}

//Backward Procedure
//Function to calculate Beta Matrix
void vehicle::testing:: calculatingBeta(long double a[6][6], long double b[6][33], long double p[]) {
	int i, t, j;
	//int temp = T;
	long double sum = 0.0;
	//Initialization
	for (i = 1; i <= N; i++) {
		beta[total_frames][i] = 1;
	}
	//Induction
	for (t = total_frames - 1; t >= 1; t--) {
		for (i = 1; i <= N; i++) {
			sum = 0.0;
			for (j = 1; j <= N; j++) {
				sum += a[i][j] * b[j][OBS[t + 1]] * beta[t + 1][j];
			}
			beta[t][i] = sum;
		}
	}
}

//-------------------------------------------------------------------Solution to Problem 2--------------------------------------------------------------------------------

//Function to calculate Gamma Matrix
void vehicle::testing:: calculatingGamma() {
	int t, i, j;
	//long double sum;
	for (t = 1; t <= total_frames; t++) {
		for (i = 1; i <= N; i++) {
			//sum = 0.0;
			//for(j=1;j<=N;j++){
				//sum += alpha[t][j] * beta[t][j];
			//}
			//printf("\nGamma Sum: %0.150Lf ",sum);
			gamma[t][i] = (HMMalpha[t][i] * beta[t][i]) / Prob_O_Given_Lamda;
		}
	}
}



//Function to calculate the state sequence based using the calculated gamma Matrix
void vehicle::testing:: calculating_qt() {
	int t, i, maxidx;
	long double max;
	for (t = 1; t <= total_frames; t++) {
		max = gamma[t][1];
		maxidx = 1;
		for (i = 2; i <= N; i++) {
			if (max < gamma[t][i]) {
				max = gamma[t][i];
				maxidx = i;
			}
		}
		qt[t] = maxidx;
	}
}

//Function to implement the Viterbi Algorithm
void vehicle::testing:: viterbiAlgorithm(long double a[6][6], long double b[6][33], long double p[]) {
	int i, j, t;
	long double max, temp;
	int maxidx;
	//Initialization
	for (i = 1; i <= N; i++) {
		delta[1][i] = p[i] * b[i][OBS[1]];
		psi[1][i] = 0;
	}
	//Recursion
	for (t = 2; t <= total_frames; t++) {
		for (j = 1; j <= N; j++) {
			max = delta[t - 1][1] * a[1][j];
			maxidx = 1;
			for (i = 2; i <= N; i++) {
				temp = delta[t - 1][i] * a[i][j];
				if (temp > max) {
					max = temp;
					maxidx = i;
					//printf("max index updated: %d\n",maxidx);
				}
			}
			delta[t][j] = max * b[j][OBS[t]];
			//printf("\nmax index: %d\n",maxidx);
			psi[t][j] = maxidx;
		}
	}
	//Termination
	//Calculation of P*(parameter to judge how good the given Lamba is) and q*
	pstar = delta[total_frames][1];
	qstar = 1;
	for (i = 2; i <= N; i++) {
		temp = delta[total_frames][i];
		if (temp > pstar) {
			pstar = temp;
			qstar = i;
		}
	}
	//printf("\npstar: %0.150Lf\nqstar: %d\n",pstar,qstar);
}

//Function to calculate the state sequence using Matrices calculated in Viterbi Algorithm
void vehicle::testing:: calculatingQtstar() {
	int t;
	int temp = qstar;
	//printf("\ntemp: %d",temp);
	qtstar[total_frames] = temp;
	for (t = total_frames - 1; t >= 1; t--) {
		qtstar[t] = psi[t + 1][qtstar[t + 1]];
		//temp = qtstar[t];
	}
	//printf("\n");
	//for(t=1;t<=T;t++){
		//printf("%d ",qtstar[t]);
		//temp = qtstar[t];
	//}
	//printf("\n");
}

//-------------------------------------------------------------------Solution to Problem 3--------------------------------------------------------------------------------

//Function to calculate Xi Matrix
void vehicle::testing:: calculatingXi() {
	int t, i, j;
	long double temp;
	for (t = 1; t < total_frames; t++) {
		for (i = 1; i <= N; i++) {
			for (j = 1; j <= N; j++) {
				temp = HMMalpha[t][i] * A[i][j] * B[j][OBS[t + 1]] * beta[t + 1][j];
				//printf("\n temp:%0.150Lf",temp);
				xi[t][i][j] = temp / Prob_O_Given_Lamda;
			}
		}
	}
}

//Function to re-estimate PI Matrix
void vehicle::testing:: calculatingPibar() {
	int i;
	for (i = 1; i <= N; i++) {
		pibar[i] = gamma[1][i];
	}

}

//Function to re-estimate A Matrix
void vehicle::testing:: calculatingAbar() {
	int i, j, t;
	long double sum1, sum2;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			sum1 = 0.0;
			sum2 = 0.0;
			for (t = 1; t < total_frames; t++) {
				sum1 += xi[t][i][j];
				sum2 += gamma[t][i];
			}
			abar[i][j] = sum1 / sum2;
		}
	}
}

//Function to re-estimate B Matrix
void vehicle::testing:: calculatingBbar() {
	int j, k, t;
	long double sum1, sum2;
	for (j = 1; j <= N; j++) {
		for (k = 1; k <= M; k++) {
			sum1 = 0.0;
			sum2 = 0.0;
			for (t = 1; t <= total_frames; t++) {
				if (k == OBS[t]) {
					sum1 += gamma[t][j];
				}
				//sum1 += gamma[t][j] * B[j][k];
				sum2 += gamma[t][j];
			}
			bbar[j][k] = sum1 / sum2;
		}
	}
}


//Function to update the PI matrix with PIbar Matrix, A matrix with Abar Matrix and B matrix with Bbar Matrix
void vehicle::testing:: updateMatrices() {
	int i, j;

	//for (i=1;i<=N;i++){
	//	PI[i] = pibar[i];
	//}

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			A[i][j] = abar[i][j];
		}
	}

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			B[i][j] = bbar[i][j];
		}
	}

}

//Function to fix Bbar Matrix
void vehicle::testing:: fixBbarMatrix() {
	long double threshold = powl(10, -30);
	long double difference = 0;
	int i, j, max_index;
	for (i = 1; i <= N; i++) {
		max_index = 1;
		difference = 0.0;
		for (j = 1; j <= M; j++) {
			if (bbar[i][j] > bbar[i][max_index]) {
				max_index = j;
			}
			if (bbar[i][j] < threshold) {
				difference += (threshold - bbar[i][j]);
				bbar[i][j] += threshold;
			}
		}
		bbar[i][max_index] = bbar[i][max_index] - difference;
	}
}


//Function to call solution to problem # 1 of HMM
void vehicle::testing:: solution1(long double a[6][6], long double b[6][33], long double p[]) {
	Prob_O_Given_Lamda = calculatingAlpha(a, b, p);
	calculatingBeta(a, b, p);
}

//Function to call solution to problem # 2 of HMM
void vehicle::testing:: solution2(long double a[6][6], long double b[6][33], long double p[]) {
	calculatingGamma();
	//calculating_qt();
	viterbiAlgorithm(a, b, p);
	calculatingQtstar();
}

//Function to call solution to problem # 3 of HMM
void vehicle::testing:: solution3() {
	calculatingXi();
	//calculatingPibar();
	calculatingAbar();
	calculatingBbar();
	fixBbarMatrix();

}



//Function to train the HMM model 
void vehicle::testing:: training(string fname, string noiseFile, string file1, string file2) {
	iterations = 1;
	//remove("Ci_temp.txt");
	initializeInput(fname, noiseFile);
	loadHammingWindow();
	loadRSWindow();
	loadCodebook();
	calculateCis();
	generateObservationSequence();
	readInitialModels(file1, file2, "Models\\Initial_PI_Matrix.txt", "Models\\obs_seq.txt");
	/*for(i=1;i<=N;i++){
		printf("\n");
		for(j=1;j<=N;j++){
			printf("%e\t",A[i][j]);
		}
	}
	*/
	solution1(A, B, PI);
	solution2(A, B, PI);
	solution3();
	printf("\n\nIteration Number : %d\n", iterations);
	printf("\nProbability[O/Lambda]: %e", Prob_O_Given_Lamda);
	printf("\nP*: %e", pstar);
	//printf("\nObservation Sequence: ");
	//for(i=1;i<=total_frames;i++){
	//fprintf(filepointer,"%d ",OBS[i]);
	//printf("%d ",OBS[i]);
	//}
	//fprintf(filepointer,"\nState Sequence: ");
	//printf("\nState Sequence: ");
	//for(i=1;i<=total_frames;i++){
		//fprintf(filepointer,"%d ",qtstar[i]);
	//	printf("%d ",qtstar[i]);
	//}
	//fprintf(filepointer,"\nP*: %e",pstar);
	old_pstar = pstar;
	solution1(abar, bbar, PI);
	solution2(abar, bbar, PI);
	while (pstar - old_pstar > 0 && iterations < 20) {
		iterations++;
		printf("\n\nIteration Number : %d\n", iterations);
		printf("\nProbability[O/Lambda]: %e", Prob_O_Given_Lamda);
		printf("\nP*: %e", pstar);
		//printf("\nObservation Sequence: ");
		//for(i=1;i<=total_frames;i++){
		//fprintf(filepointer,"%d ",OBS[i]);
		//printf("%d ",OBS[i]);
		//}
		//fprintf(filepointer,"\nState Sequence: ");
		//printf("\nState Sequence: ");
		//for(i=1;i<=total_frames;i++){
			//fprintf(filepointer,"%d ",qtstar[i]);
		//	printf("%d ",qtstar[i]);
		//}
		//fprintf(filepointer,"\nP*: %e",pstar);
		updateMatrices();
		solution3();
		old_pstar = pstar;
		solution1(abar, bbar, PI);
		solution2(abar, bbar, PI);
	}

	printf("\n Decreased P*: %e\n\n", pstar);
}


int vehicle::testing:: find_index(int set, string word) {

	int size = 0;
	int index = -1;
	//classifing the word to be tested
	size = 2;
	if (set > 1) {
		size = 4;
	}
	for (int col = 0; col < size; col++) {
		if (strcmp(word.c_str(), words[set][col].c_str()) == 0) {
			index = col;
			return index;
		}
	}
	return index;
}



//Function to test the input files
string vehicle::testing:: recognize(string fname, string noiseFile, int setNumber, string word_tested, string speakerName) {
	//remove("Ci_temp.txt");
	initializeInput(fname, noiseFile);
	loadHammingWindow();
	loadRSWindow();
	loadCodebook();
	calculateCis();
	generateObservationSequence();


	string folder = "Dataset\\";
	string txt = ".txt";
	//string modelsFolder = "Models\\";
	string Amatrix = "Models\\Avg_A_Matrix_";
	string Bmatrix = "Models\\Avg_B_Matrix_";
	string outputA = "";
	string outputB = "";
	string noisefilename = "";
	char stw[3], str[3];
	int size = 0;
	int index = -1;
	//classifing the word to be tested
	size = 2;
	if (setNumber == 1) {
		size = 3;
	}
	if (setNumber > 1) {
		size = 5;
	}

	int predict = -1;
	long double maxprob = -1.0;
	//index = find_index(setNumber, word_tested);
	cout << endl << words[setNumber][index] << endl;

	//sprintf(stw,"%d",3);
	for (int word = 0; word < size; word++)
	{
		//outputA = Amatrix + speakerName + "_" + words[setNumber][word] + "_3" + txt;
		//outputB = Bmatrix + speakerName + "_" + words[setNumber][word] + "_3" + txt;
		outputA = Amatrix + words[setNumber][word] + txt;
		outputB = Bmatrix + words[setNumber][word] + txt;
		readInitialModels(outputA, outputB, "Models\\Initial_PI_Matrix.txt", "Models\\obs_seq.txt");
		solution1(A, B, PI);
		printf("\n P[O/Lamba] of %s : %e", words[setNumber][word].c_str(), Prob_O_Given_Lamda);

		if (Prob_O_Given_Lamda > maxprob&& Prob_O_Given_Lamda > 0) {
			maxprob = Prob_O_Given_Lamda;
			predict = word;
		}
	}
	//printf("\n");
	printf("\n Prediction: %s", words[setNumber][predict].c_str());
	if (predict == index) {
		accuracy++;
	}
	return  words[setNumber][predict];
}



//Function to start training of HMM
void vehicle::testing:: startTraining(string speakerName, string wordSpoken, int utteranceCount) {
	string filename = "";
	//string speakers[4] = {"avikash","utkarsh","cheeku","rashika"};
	//string cars[5] = {"_alto_","_ciaz_","_creta_","_jeep_"}; 
	//string bikes[5] = {"_activa_","_appache_","_bullet_","_pulsa r_"}; 
	//string extraWords[3] = {"_begin_","_end_"};
	string folder = "Dataset\\";
	string txt = ".txt";
	//string modelsFolder = "Models\\";
	string Amatrix = "Models\\Avg_A_Matrix_";
	string Bmatrix = "Models\\Avg_B_Matrix_";
	string outputA = "";
	string outputB = "";
	string noisefilename = "";
	char stw[3], str[3];
	//int g;
	//training
	//for(int speaker=0;speaker<=0;speaker++){
		//for(int extra=3;extra<4;extra++){
		//for(int bike=3;bike<4;bike++){
		//for(int car=3;car<4;car++){
	for (int k = 0; k < 3; k++) {//iteration number
		sprintf(stw, "%d", k);
		outputA = Amatrix + wordSpoken + txt;
		outputB = Bmatrix + wordSpoken + txt;

		//outputA = Amatrix + speakers[speaker] + bikes[bike] + stw + txt;
		//outputB = Bmatrix + speakers[speaker] + bikes[bike] + stw + txt;

		//outputA = Amatrix + speakers[speaker] + cars[car] + stw + txt;
		//outputB = Bmatrix + speakers[speaker] + cars[car] + stw + txt;
		//Initializing AvgA matrix to 0
		for (int row = 1; row <= N; row++) {
			for (int col = 1; col <= N; col++) {
				AvgA[row][col] = 0;
			}
		}
		//Initializing AvgB matrix to 0
		for (int row = 1; row <= N; row++) {
			for (int col = 1; col <= M; col++) {
				AvgB[row][col] = 0;
			}
		}

		for (int i = 1; i <= utteranceCount; i++) { //filenumber
			sprintf(str, "%d", i);
			filename = folder + speakerName + "_" + wordSpoken + "_" + str + txt;
			//filename = folder + speakers[speaker] + bikes[bike] + str + txt;
			//filename = folder + speakers[speaker] + cars[car] + str + txt;
			noisefilename = folder + speakerName + "_noiseFile" + txt;
			cout << endl << "Training for " << filename << endl;
			//if (k == 0) {
			//	training(filename, noisefilename, "Models\\Initial_A_Matrix.txt", "Models\\Initial_B_Matrix.txt");
			//}
			//else {
			training(filename, noisefilename, outputA, outputB);
			//}


			//Adding A matrix to AvgA
			for (int row = 1; row <= N; row++) {
				for (int col = 1; col <= N; col++) {
					AvgA[row][col] += A[row][col];
				}
			}

			//Adding B matrix to AvgB
			for (int row = 1; row <= N; row++) {
				for (int col = 1; col <= M; col++) {
					AvgB[row][col] += B[row][col];
				}
			}

		}
		//sprintf(stw, "%d", k + 1);
		//outputA = Amatrix + speakerName + "_" + wordSpoken + "_" + stw + txt;
		//outputB = Bmatrix + speakerName + "_" + wordSpoken + "_" + stw + txt;

		//outputA = Amatrix + speakers[speaker] + bikes[bike] + stw + txt;
		//outputB = Bmatrix + speakers[speaker] + bikes[bike] + stw + txt;

		//outputA = Amatrix + speakers[speaker] + cars[car] + stw + txt;
		//outputB = Bmatrix + speakers[speaker] + cars[car] + stw + txt;

		//Writing AvgA matrix to file
		FILE* fp;
		fp = fopen(outputA.c_str(), "w");
		for (int row = 1; row <= N; row++) {
			long double sum = 0;
			for (int col = 1; col <= N; col++) {
				sum += AvgA[row][col] / utteranceCount;
				fprintf(fp, "%Lf\t", (AvgA[row][col] / utteranceCount));
			}
			fprintf(fp, "\n");
			printf("\nrow sum: %Lf", sum);
		}

		fclose(fp);

		//Writing AvgB matrix to file

		fp = fopen(outputB.c_str(), "w");
		printf("\nK:%d", k);
		for (int row = 1; row <= N; row++) {
			long double  sum = 0;
			for (int col = 1; col <= M; col++) {
				sum += AvgB[row][col] / utteranceCount;
				fprintf(fp, "%0.35Lf\t", (AvgB[row][col] / utteranceCount));
			}
			printf("\nrow sum: %Lf", sum);

			fprintf(fp, "\n");
		}
		fclose(fp);

	}

	//}
//}
}

int vehicle::testing:: findSet(string word) {

	int size = 0;
	int setNumber = -1;
	//classifing the word to be tested
	for (int row = 0; row < 4; row++) {
		size = 2;
		if (row > 1) {
			size = 4;
		}
		for (int col = 0; col < size; col++) {
			if (strcmp(word.c_str(), words[row][col].c_str()) == 0) {
				setNumber = row;
				return setNumber;
			}
		}
	}

	return setNumber;

}



int vehicle::testing:: preprocessing(string filename, string noisefilenametxt) {
	int totalCutFrames = 0;
	int overlappedFrames = 0;
	initializeInput(filename, noisefilenametxt);
	totalCutFrames = end_frame - start_frame + 1;
	overlappedFrames = ((totalCutFrames * 320) - 320) / 80;
	overlappedFrames += 1;
	if (overlappedFrames >= 70 && overlappedFrames <= 170) {
		return 1;
	}
	return 0;
}

void vehicle::testing:: liveTraining(string Name, string Word, string Num) {
	string speakerName;
	string word_trained;
	string filenametxt = "";
	string filenamewav = "";
	string noisefilenametxt = "";
	string noisefilenamewav = "";
	string pre = "Recording_Module.exe 4 ";
	string final = "";
	string noise = "_noiseFile";
	string txt = ".txt";
	string wav = ".wav";
	string initialPath = "Dataset\\";
	char utteranceNumber[3];

	//int trainingCountStart =0;//utterance number start
	//int trainingCountEnd = 0;//utterance number end
	int utterances = 0;
	/*cout << endl << "Please enter the name of the speaker to be trained : ";
	cin >> speakerName;
	cout << endl << "Please enter the word to be trained : ";
	cin >> word_trained;
	//cout<<endl<<"Please enter the start index of utterance number : ";
	//cin>>trainingCountStart;
	cout << endl << "Please enter the number of utterances : ";
	cin >> utterances;
	cout << endl << "The system will first record the ambient noise of the environment to calibrate." << endl;
	*/
	speakerName = Name;
	word_trained = Word;
	utterances = atoi(Num.c_str());

	noisefilenametxt = initialPath + speakerName + noise + txt;
	noisefilenamewav = initialPath + speakerName + noise + wav;
	final = pre + noisefilenamewav + " " + noisefilenametxt;
	system(final.c_str()); //recording ambient noise
	//recording the utterances of the word
	cout << endl << "Please start speaking the word once each time when recording starts";
	for (int i = 1; i <= utterances; i++) {
		sprintf(utteranceNumber, "%d", i);
		filenametxt = initialPath + speakerName + "_" + word_trained + "_" + utteranceNumber + txt;
		filenamewav = initialPath + speakerName + "_" + word_trained + "_" + utteranceNumber + wav;
		final = pre + filenamewav + " " + filenametxt;
		cout << endl << "Recording " << word_trained << ", utterance number : " << i << endl;
		system(final.c_str());
		if (!preprocessing(filenametxt, noisefilenametxt)) {
			printf("\nThere is some problem in the recording please re-record this utterance now.");
			i--;
		}

	}
	cout << endl << "Please wait, model is being trained" << endl;
	startTraining(speakerName, word_trained, utterances);
	cout << endl << "Model has been trained." << endl;

}



string vehicle::testing::Test( int setNumber, string word_tested, string speakerName) {
	//System::Threading::Thread::Sleep(2500);
	if(setNumber == 0)
	system("Recording_Module.exe 3 noise_lab.wav noise_lab.txt");

	system("Recording_Module.exe 3 input_1.wav input_1.txt");
	//speakerName = "avikash";
	return recognize("input_1.txt", "noise_lab.txt", setNumber, word_tested, speakerName);

	printf("hi");
}

