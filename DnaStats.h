/*
Emilee mason
ID# 2321064
emmason@chapman.edu
CPSC 350-01
Assignment 1: C++ Review

DnaStats.h
This is the header file of the DnaStats class. This file defines all of the methods,
member variables, as well as call of the the right libraries that will be needed
for the implementation file.
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
using namespace std;

class DnaStats{

  public:
    bool ProcessFile;

    DnaStats();
    void RunDnaStats(DnaStats *MyDna, string FileName, string Line);
    string GetNewFileName();

  private:
//counted variables
    double TotalLines;
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
    double TotalBigramCount; //all bigrams in file

//caculated variables
    double SumDnaLetters;
    double MeanDnaLetters;
    double VarianceDnaLetters;
    double StandardDeviationDnaLetters;

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
    ofstream OpenWriter(string FileName);
    ofstream OpenAppender(string FileName);

    void RunAgain();

    void PrintDnaInfo(string NewFileName);
    void PrintCalculations(string NewFileName);
    void PrintGaussian(string NewFileName);
    char LetterGivenProbs();

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
    int CalcGaussian();

};
