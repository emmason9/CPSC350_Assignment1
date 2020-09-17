//all the implementation put together
#include "DnaStats.h"
#include <math.h>

//default constructor
DnaStats :: DnaStats(){
  TotalLines = 0;
  TotalCountA = 0; //total number of A letters ....
  TotalCountT = 0;
  TotalCountC = 0;
  TotalCountG = 0;
  TotalBigramCount = 0.0; //might be a .5*/
}


//delete before turning
int DnaStats :: GetTotalCountA(){
  return TotalCountA;
}
int DnaStats :: GetTotalCountT(){
  return TotalCountT;
}
int DnaStats :: GetTotalCountC(){
  return TotalCountC;
}
int DnaStats :: GetTotalCountG(){
  return TotalCountG;
}
double DnaStats :: GetTotalBigramCount(){
  return TotalBigramCount;
}
double DnaStats :: GetTotalLines(){
  return TotalLines;
}
double DnaStats :: GetProbOfNucleotideA(){
  return ProbOfNucleotideA;
}
double DnaStats :: GetProbOfNucleotideT(){
  return ProbOfNucleotideT;
}


//all file handling
  //reads files
  ifstream DnaStats :: OpenReader(string FileName){
    ifstream Reader;
    Reader.open(FileName);
    if (Reader.is_open()){
      return Reader;
    } else {
      cout << "Reader is not open" << endl;
    }
  }
/*  void DnaStats :: CloseReader(ifstream Reader){
    Reader.close();
    if (Reader.is_open()){
      cout << "Reader is still open" << endl;
    }
  }*/

  //writes file
  ofstream DnaStats :: OpenWriter(string FileName){
    ofstream Writer;
    Writer.open(FileName);

    if (Writer.is_open()){
      return Writer;
    } else {
      cout << "Writer is not open" << endl;
      return Writer; //returning it just to get out of the
    }
  }
/*  void DnaStats :: CloseWriter(ofstream Writer){
    Writer.close();
    if(Writer.is_open()){
      cout << "Writer is still open" << endl;
    }
  }*/

  //appends to files
  ofstream DnaStats :: OpenAppender(string FileName){
    ofstream Appender;
    Appender.open(FileName, ios::app);

    if (Appender.is_open()){
      return Appender;
    } else {
      cout << "Appender is not open" << endl;
      return Appender; //returning it just to get out of the
    }

  }
/*  void DnaStats :: CloseAppender(ofstream Appender){
    Appender.close();
    if(Appender.is_open()){
      cout << "Appender is still open" << endl;
    }
  }*/

  void DnaStats :: PrintDnaInfo(string NewFileName){
    ofstream Writer = OpenWriter(NewFileName);
    Writer << "The Sum of the length of the DNA strings is " << SumDnaLetters << endl;
    Writer << "The Mean of the length of the DNA strings is " << MeanDnaLetters << endl;
    Writer << "The Variance of the length of the DNA strings is " << VarianceDnaLetters << endl;
    Writer << "The Standard Deviation of the length of the DNA strings is " << StandardDeviationDnaLetters << endl;
    Writer << "Here is the probablity of each nucleotide:" << endl;
    Writer << "A:        " << ProbOfNucleotideA << endl;
    Writer << "T:        " << ProbOfNucleotideT << endl;
    Writer << "C:        " << ProbOfNucleotideC << endl;
    Writer << "G:        " << ProbOfNucleotideG << endl;
    Writer << "Here is the probablity of each nucleotide bigram:" << endl;
    Writer << "AA:       " << ProbOfBigramAA << endl;
    Writer << "AT:       " << ProbOfBigramAT << endl;
    Writer << "AC:       " << ProbOfBigramAC << endl;
    Writer << "AG:       " << ProbOfBigramAG << endl;
    Writer << "TA:       " << ProbOfBigramTA << endl;
    Writer << "TT:       " << ProbOfBigramTT << endl;
    Writer << "TC:       " << ProbOfBigramTC << endl;
    Writer << "TG:       " << ProbOfBigramTG << endl;
    Writer << "CA:       " << ProbOfBigramCA << endl;
    Writer << "CT:       " << ProbOfBigramCT << endl;
    Writer << "CC:       " << ProbOfBigramCC << endl;
    Writer << "CG:       " << ProbOfBigramCG << endl;
    Writer << "GA:       " << ProbOfBigramGA << endl;
    Writer << "GT:       " << ProbOfBigramGT << endl;
    Writer << "GC:       " << ProbOfBigramGC << endl;
    Writer << "GG:       " << ProbOfBigramGG << endl;
    Writer << "\n\nHere are 1000 DNA strings with the same mean and variance as above:" << endl;
    PrintGaussian();
    Writer.close();
  }

  void DnaStats :: PrintGaussian(){
    int LineLength;
    string DnaString;
    for(int i = 0; i < 10, ++i){
      LineLength = CalcGaussian();
      DnaString = "";
      for(int j = 0; j < LineLength; ++j){
        //build the string
        DnaString += 'A'
      }
    }
    //nothing yet
  }

  bool DnaStats :: RunAgain(){
    string UserInput;
    while(true){
      cout << "Would you like to scan a new file?\n'yes' or 'no'" << endl;
      cin >> UserInput;
      if (UserInput == "y") {
        return true;
      } else if (UserInput == "n"){
        return false;
      } else {
        cout << "That's not the right input, try again.\nPlease make sure it's lower case and spelled correctly!\n" << endl;
      }
    }
  }

//will call all the methods and run the calculations
 void DnaStats :: RunDnaStats(DnaStats *MyDna, string FileName, string Line){
    cout << "...going through the lines..." << endl;
    TotalLines = MyDna->IterateFileLines(FileName, Line);
    //do something to calculate alll probs
    cout << "...making calculations..." << endl;
    AllCalculations(FileName);
    //cout << "...printing to file..." << endl;

    //cout << "Done!" << endl;

  }


//ALL OF THE COUNTING METHODS
  //Iterate through string lines, returns number of lines iterated
  double DnaStats :: IterateFileLines(string FileName, string Line){
    ifstream Reader = OpenReader(FileName);
    double LineNumber = 0.0;
    while (getline(Reader, Line)){
      LineNumber++;
      SumDnaLetters += IterateLineLetters(Line);
    }
    Reader.close();
    return LineNumber;
  }

//iterating through the DNA strain/line and calls methods that count what needs to be counted
  double DnaStats :: IterateLineLetters(string Line){
    int TotalLettersInLine = 0;
    //letter check forloop
    for(int i=0; i < Line.length(); ++i){
      LetterCount(Line[i]);
      if(i%2 == 0){
        BigramCheck(Line, i);
      }
      if(isalpha(Line[i])){
        TotalLettersInLine++;
      }
    }
    return TotalLettersInLine;
  }

//counts the complete total of all the letters in the entire file
  void DnaStats :: LetterCount(char DnaLetter){
    if(DnaLetter == 'a' || DnaLetter == 'A'){
      TotalCountA++;
    } else if(DnaLetter == 't' || DnaLetter == 'T'){
      TotalCountT++;
    } else if(DnaLetter == 'c' || DnaLetter == 'C'){
      TotalCountC++;
    } else if(DnaLetter == 'g' || DnaLetter == 'G'){
      TotalCountG++;
    } //if it's anything else, it'll just skip over it
  }

//checks that the correct Bigram is counted
  void DnaStats :: BigramCheck(string Line, int index){
    if ((index == (Line.length()-1))){
      BigramCount(Line[index],Line[0]);
      TotalBigramCount++;
    } else {
      BigramCount(Line[index], Line[index+1]);
      TotalBigramCount++;
    } //anything else woundn't count as a bigram
  }

//checks which bigram to count towards
  void DnaStats :: BigramCount(char CurrentLetter, char NextLetter){
    string Bigram = "";
    Bigram += CurrentLetter;
    Bigram += NextLetter;
    transform(Bigram.begin(), Bigram.end(), Bigram.begin(), :: tolower);
//disgusting if else statement for bigram check :<
    if (Bigram == "AA" || Bigram == "aa"){
      TotalCountBigramAA++;
    } else if (Bigram == "AT" || Bigram == "at"){     /// tolower(Bigram)
      TotalCountBigramAT++;
    } else if (Bigram == "ac"){
      TotalCountBigramAC++;
    } else if (Bigram == "ag"){
      TotalCountBigramAG++;
    } else if (Bigram == "ta"){
      TotalCountBigramTA++;
    } else if (Bigram == "tt"){
      TotalCountBigramTT++;
    } else if (Bigram == "tc"){
      TotalCountBigramTC++;
    } else if (Bigram == "tg"){
      TotalCountBigramAG++;
    } else if (Bigram == "ca"){
      TotalCountBigramCA++;
    } else if (Bigram == "ct"){
      TotalCountBigramCT++;
    } else if (Bigram == "cc"){
      TotalCountBigramCC++;
    } else if (Bigram == "cg"){
      TotalCountBigramCG++;
    } else if (Bigram == "ga"){
      TotalCountBigramGA++;
    } else if (Bigram == "gt"){
      TotalCountBigramGT++;
    } else if (Bigram == "gc"){
      TotalCountBigramGC++;
    } else if (Bigram == "gg"){
      TotalCountBigramGG++;
    } //if anything else, will naturally skip over it and not count it
  }


//ALL CALCULATION METHODS
  void DnaStats :: AllCalculations(string FileName){
    CalcMean();
    CalcVariance(FileName);
    CalcStandardDeviation();
    CalcProbabilities();
  }

//mean
  void DnaStats :: CalcMean(){
    MeanDnaLetters = (SumDnaLetters/TotalLines);
  }
//variance FIX
  void DnaStats :: CalcVariance(string FileName){
    ifstream Reader = OpenReader(FileName);
    string Line;
    int VarianceSum = 0;

    while (getline(Reader, Line)){
      if (isalpha(Line[Line.length()-1])){    //checking for the \n at the end of the line
        VarianceSum += pow((Line.length() - MeanDnaLetters),2);
      } else {
        VarianceSum += pow(((Line.length()-1)- MeanDnaLetters),2);
      }
    }
    Reader.close();
    VarianceDnaLetters = VarianceSum/TotalLines;
  }
//SD
  void DnaStats :: CalcStandardDeviation(){
    StandardDeviationDnaLetters = sqrt(VarianceDnaLetters);
  }

//all probablities
  void DnaStats :: CalcProbabilities(){
    CalcNucleotidesProb();
    CalcBigramProbs();
  }

  void DnaStats :: CalcNucleotidesProb(){
    ProbOfNucleotideA = (TotalCountA/SumDnaLetters)/TotalLines;
    ProbOfNucleotideT = (TotalCountT/SumDnaLetters)/TotalLines;
    ProbOfNucleotideC = (TotalCountC/SumDnaLetters)/TotalLines;
    ProbOfNucleotideG = (TotalCountG/SumDnaLetters)/TotalLines;
  }

  void DnaStats :: CalcBigramProbs(){
    ProbOfBigramAA = (TotalCountBigramAA/TotalBigramCount)/TotalLines;
    ProbOfBigramAT = (TotalCountBigramAT/TotalBigramCount)/TotalLines;
    ProbOfBigramAC = (TotalCountBigramAC/TotalBigramCount)/TotalLines;
    ProbOfBigramAG = (TotalCountBigramAG/TotalBigramCount)/TotalLines;
    ProbOfBigramTA = (TotalCountBigramTA/TotalBigramCount)/TotalLines;
    ProbOfBigramTT = (TotalCountBigramTT/TotalBigramCount)/TotalLines;
    ProbOfBigramTC = (TotalCountBigramTC/TotalBigramCount)/TotalLines;
    ProbOfBigramTG = (TotalCountBigramTG/TotalBigramCount)/TotalLines;
    ProbOfBigramCA = (TotalCountBigramCA/TotalBigramCount)/TotalLines;
    ProbOfBigramCT = (TotalCountBigramCT/TotalBigramCount)/TotalLines;
    ProbOfBigramCC = (TotalCountBigramCC/TotalBigramCount)/TotalLines;
    ProbOfBigramCG = (TotalCountBigramCG/TotalBigramCount)/TotalLines;
    ProbOfBigramGA = (TotalCountBigramGA/TotalBigramCount)/TotalLines;
    ProbOfBigramGT = (TotalCountBigramGT/TotalBigramCount)/TotalLines;
    ProbOfBigramGC = (TotalCountBigramGC/TotalBigramCount)/TotalLines;
    ProbOfBigramGG = (TotalCountBigramGG/TotalBigramCount)/TotalLines;
  }

//returns line length for next line
  int DnaStats :: CalcGaussian(){
    double a;
    double b;
    double BigC;
    int BigD;   //for length of lines
    double pi = 3.1415926535897;

    a = rand()/(RAND_MAX + 1.0); //random numbers [0,1)
    b = rand()/(RAND_MAX + 1.0);

    BigC = (sqrt(-2 * log(a))  * cos(2 * pi * b));  //general gaussian distribution?
    BigD = (StandardDeviationDnaLetters * BigC) + MeanDnaLetters;  //gaussian distribution for given SD/mean
    return BigD;
  }
