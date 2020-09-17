//DNA stats header
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

class DnaStats{

  public:
/*    int GetLineNumber();
    void SetLineNumber(int NewLineNumber);
    int GetLetterNumber();
    void SetLetterNumber(int NewLetterNumber);*/
    int GetTotalCountA();
    void SetTotalCountA(int NewCountA);
    int GetTotalCountT();
    void SetTotalCountT(int NewCountT);
    int GetTotalCountC();
    void SetTotalCountC(int NewCountC);
    int GetTotalCountG();
    void SetTotalCountG(int NewCountG);
    double GetTotalLines();
    int GetTotalLetterCount();
    void SetTotalLetterCount(int NewTotalLetter);
    double GetTotalBigramCount();
    void SetTotalBigramCount(double NewTotalBigram);
    double GetProbOfNucleotideA();
    void SetProbOfNucleotideA(double NewProbOfA);
    double GetProbOfNucleotideT();
    void SetProbOfNucleotideT(double NewProbOfT);
    double GetProbOfNucleotideC();
    void SetProbOfNucleotideC(double NewProbOfC);
    double GetProbOfNucleotideG();
    void SetProbOfNucleotideG(double NewProbOfG);


//methods/constructors
    DnaStats();
    void RunDnaStats(DnaStats *MyDna, string FileName, string Line);
    bool RunAgain();


  private:
//counted variables
  //  bool ProcessFile; //whether to continue through while loop again
    double TotalLines; //total lines in file
    double TotalCountA;
    double TotalCountT;
    double TotalCountC;
    double TotalCountG;

    double TotalCountBigramAA;
    double TotalCountBigramAT;
    double TotalCountBigramAC;
    double TotalCountBigramAG;
    double TotalCountBigramTA;
    double TotalCountBigramTT;
    double TotalCountBigramTC;
    double TotalCountBigramTG;
    double TotalCountBigramCA;
    double TotalCountBigramCT;
    double TotalCountBigramCC;
    double TotalCountBigramCG;
    double TotalCountBigramGA;
    double TotalCountBigramGT;
    double TotalCountBigramGC;
    double TotalCountBigramGG;

  //  int TotalLetterCount; //sum of letters in file
    double TotalBigramCount; //all bigrams in file
//caculated variables
    double SumDnaLetters;
    double MeanDnaLetters;
    double VarianceDnaLetters;
    double StandardDeviationDnaLetters;
    //guassian ????
    double ProbOfNucleotideA;
    double ProbOfNucleotideC;
    double ProbOfNucleotideG;
    double ProbOfNucleotideT;

    double ProbOfBigramAA;
    double ProbOfBigramAT;
    double ProbOfBigramAC;
    double ProbOfBigramAG;
    double ProbOfBigramTA;
    double ProbOfBigramTT;
    double ProbOfBigramTC;
    double ProbOfBigramCA;
    double ProbOfBigramTG;
    double ProbOfBigramCT;
    double ProbOfBigramCC;
    double ProbOfBigramCG;
    double ProbOfBigramGA;
    double ProbOfBigramGT;
    double ProbOfBigramGC;
    double ProbOfBigramGG;




    ifstream OpenReader(string FileName);
  //  void CloseReader(ifstream Reader);
    ofstream OpenWriter(string FileName);
    //void CloseWriter(ofstream Writer);
    ofstream OpenAppender(string FileName);
    //void CloseAppender(ofstream Appender);
    void PrintDnaInfo(string NewFileName);
    void PrintGaussian();

    double IterateFileLines(string FileName, string Line);
    double IterateLineLetters(string Line);
    void LetterCount(char DnaLetter);
    void BigramCheck(string DnaLine, int index);
    void BigramCount(char CurrentLetter, char NextLetter);


//calculations
    void AllCalculations(string FileName);
    void CalcMean();
    void CalcVariance(string FileName);
    void CalcStandardDeviation();
    void CalcProbabilities();
    void CalcNucleotidesProb();
    void CalcBigramProbs();
    void CalcGaussian();







};
