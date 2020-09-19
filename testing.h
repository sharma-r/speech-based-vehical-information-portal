#include<iostream>
namespace vehicle {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	/// <summary>
	/// Summary for Form1
	/// </summary>
	public class testing{

	public:
		string Test(int , string , string );
		
		void readSamples(string );
		long double calDCShift(string );
		void pDCShift(long double dcs);
		void normalization();
		long double calSTEnergy(int start, int end);
		void initializeInput(string fname, string noiseFile);
		void loadHammingWindow();
		void loadRSWindow();
		void applyHammingWindow(int s);
		void calris();
		void calais();
		void calcis(int index);
		void applyRSWindow(int index);
		void calculateCis();
		void loadCodebook();
		void generateObservationSequence();
		void readInitialModels(string fname1, string fname2, char* fname3, char* fname4);
		long double calculatingAlpha(long double a[6][6], long double b[6][33], long double p[]);
		void calculatingBeta(long double a[6][6], long double b[6][33], long double p[]);
		void calculatingGamma();
		void calculating_qt();
		void viterbiAlgorithm(long double a[6][6], long double b[6][33], long double p[]);
		void calculatingQtstar();
		void calculatingXi();
		void calculatingPibar();
		void calculatingAbar();
		void calculatingBbar();
		void updateMatrices();
		void fixBbarMatrix();
		void solution1(long double a[6][6], long double b[6][33], long double p[]);
		void solution2(long double a[6][6], long double b[6][33], long double p[]);
		void solution3();
		void training(string , string , string , string );
		int find_index(int set, string );
		string recognize(string, string, int setNumber, string, string);
		void startTraining(string , string , int utteranceCount);
		int findSet(string );
		int preprocessing(string , string );
		void liveTraining(string, string, string);





















	};


}