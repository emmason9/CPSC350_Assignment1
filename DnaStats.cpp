/*
Emilee mason
ID# 2321064
emmason@chapman.edu
CPSC 350-01
Assignment 1: C++ Review

DnaStats.cpp
This is the implementation file with all of the methods and functionality to run
the DnaStats class. There are methods that not only calculate the DNA sequencing
calculations, but also methods that will open fstream objects, as well as print
out the appropriate information of the DNA sequences to a file named mason.out.
*/
#include "DnaStats.h"

//default constructor
DnaStats :: DnaStats(){
  ProcessFile = true;
  TotalLines = 0;
  TotalCountA = 0;
  TotalCountT = 0;
  TotalCountC = 0;
  TotalCountG = 0;
  TotalBigramCount = 0.0;
}

//all file handling
//he close methods wouldn't work, so i just manually close the fstream stuff with Name.close() (explained more in README)
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
  //writes file
  ofstream DnaStats :: OpenWriter(string FileName){
    ofstream Writer;
    Writer.open(FileName);
    if (Writer.is_open()){
      return Writer;
    } else {
      cout << "Writer is not open" << endl;
    }
  }
  //appends to files
  ofstream DnaStats :: OpenAppender(string FileName){
    ofstream Appender;
    Appender.open(FileName, ios::app);
    if (Appender.is_open()){
      return Appender;
    } else {
      cout << "Appender is not open" << endl;
    }
  }


  //prints info onto new file
  void DnaStats :: PrintDnaInfo(string NewFileName){
    PrintCalculations(NewFileName);
    PrintGaussian(NewFileName);
  }
  //create new file and write calc into it
  void DnaStats :: PrintCalculations(string NewFileName){
    ofstream Writer = OpenWriter(NewFileName);
    //all my personal info
    Writer << "Emilee Mason\nID#2321064\nemmason@chapman.edu\nCPSC 350-01\nAssignment 1: C++ Review\n" << endl;
    //all calcuations
    Writer << "The Sum of the length of the DNA strings is " << SumDnaLetters << endl;
    Writer << "The Mean of the length of the DNA strings is " << MeanDnaLetters << endl;
    Writer << "The Variance of the length of the DNA strings is " << VarianceDnaLetters << endl;
    Writer << "The Standard Deviation of the length of the DNA strings is " << StandardDeviationDnaLetters << endl;
    Writer << "Here is the probability of each nucleotide:" << endl;
    Writer << "A:        " << ProbOfNucleotideA << endl;
    Writer << "T:        " << ProbOfNucleotideT << endl;
    Writer << "C:        " << ProbOfNucleotideC << endl;
    Writer << "G:        " << ProbOfNucleotideG << endl;
    Writer << "Here is the probability of each nucleotide bigram:" << endl;
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
    Writer.close();
  }
  //append all 1000 new dna strings to the same new file
  void DnaStats :: PrintGaussian(string NewFileName){
    ofstream Appender = OpenAppender(NewFileName);
    Appender << "\n\nHere are 1000 DNA strings with the same mean and variance as above:" << endl;
    int LineLength;
    string DnaString;
    for(int i = 0; i < 1000; ++i){
      //setting up empty string with right length
      DnaString = "";
      LineLength = CalcGaussian();
      //building Dna string
      for(int j = 0; j < LineLength; ++j){
        DnaString += LetterGivenProbs();
      }
      //appending string to file
      Appender << DnaString << endl;
    }
    Appender.close();
  }
  //compares all probablities of the nucleotides and generates a random number that'll pick one of the nucleotides
  char DnaStats :: LetterGivenProbs(){
    //translate probs into numbers
    //if A = .50, then 1-50 is A, if T = .25, then T is 51-75...
    //have random number choosen, and then compare
    int ProbA = ProbOfNucleotideA * 100;
    int ProbT = (ProbOfNucleotideT * 100) + ProbA; //moving it over to the correct letters
    int ProbC = (ProbOfNucleotideC * 100) + ProbT;
    int ProbG = (ProbOfNucleotideG * 100) + ProbC;
    int letterChoice = rand() % ProbG;
    if (letterChoice <= ProbA){
      return 'A';
    } else if (letterChoice <= ProbT){
      return 'T';
    } else if (letterChoice <= ProbC){
      return 'C';
    } else if (letterChoice <= ProbG){
      return 'G';
    }
  }


  //will call all the methods and run the calculations
  void DnaStats :: RunDnaStats(DnaStats *MyDna, string FileName, string Line){
    cout << "...going through the lines..." << endl;
    TotalLines = MyDna->IterateFileLines(FileName, Line);
    cout << "...making calculations..." << endl;
    AllCalculations(FileName);
    cout << "...printing to file..." << endl;
    PrintDnaInfo("mason.out");
    cout << "Done!" << endl;
  }

  //while loop that sets processFile in main
  void DnaStats :: RunAgain(){
    string UserInput;
    while(true){
      cout << "Would you like to scan a new file?\n'yes' or 'no'" << endl;
      cin >> UserInput;
      if (UserInput == "yes") {
        ProcessFile = true;
        break;
      } else if (UserInput == "no"){
        ProcessFile = false;
        break;
      } else {
        cout << "That's not the right input, try again.\nPlease make sure it's lower case and spelled correctly!\n" << endl;
      }
    }
  }
  //will output new filename if process file is true
  string DnaStats :: GetNewFileName(){
    RunAgain();
    string UserInput = "";
    while(ProcessFile){
      cout << "What the new file name? Please include extention!\n(you can also'quit')" << endl;
      cin >> UserInput;
      //if the user wants to quit/not put in a file name anymore
      if(UserInput == "quit"){
        ProcessFile = false;
        break;
      }
      //checking if the name giving is a file in the folder
      ifstream Reader;
      Reader.open(UserInput);
      if(Reader.is_open()){
        Reader.close();
        break;
      } else {
        cout << "Invalid file name, try again!\n" << endl;
      }
    }
    return UserInput;
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
      if(isalpha(Line[i])){ //there is a \n at the end of each line, so we only want to count the right letters
        LetterCount(Line[i]);
        TotalLettersInLine++;
      }
      if(i%2 == 0){ //grabs the even number indexes, so it count the bigrams correctly
        BigramCheck(Line, i);
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
    if((index == (Line.length()-1)) && (isalpha(Line[index]))){ //at the end of a file, without a \n
      BigramCount(Line[index], Line[0]);
      TotalBigramCount++;
    } else if ((index == (Line.length()-2)) && not(isalpha(Line[Line.length()-1]))){ //almost at the end of a file, but the last index isn't alpha
      BigramCount(Line[index], Line[0]);
      TotalBigramCount++;
    } else if (isalpha(Line[index])){
      BigramCount(Line[index],Line[index+1]);
      TotalBigramCount++;
    }
  }
  //checks which bigram to count towards
  void DnaStats :: BigramCount(char CurrentLetter, char NextLetter){
    string Bigram = "";
    Bigram += CurrentLetter;
    Bigram += NextLetter;
    transform(Bigram.begin(), Bigram.end(), Bigram.begin(), :: tolower);
    //disgusting if else statement for bigram check :<
    if (Bigram == "aa"){
      TotalCountBigramAA++;
    } else if (Bigram == "at"){
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
  //variance
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
  //nucleotide probablities
  void DnaStats :: CalcNucleotidesProb(){
    ProbOfNucleotideA = (TotalCountA/SumDnaLetters);
    ProbOfNucleotideT = (TotalCountT/SumDnaLetters);
    ProbOfNucleotideC = (TotalCountC/SumDnaLetters);
    ProbOfNucleotideG = (TotalCountG/SumDnaLetters);
  }
  //bigram probablities
  void DnaStats :: CalcBigramProbs(){
    ProbOfBigramAA = (TotalCountBigramAA/TotalBigramCount);
    ProbOfBigramAT = (TotalCountBigramAT/TotalBigramCount);
    ProbOfBigramAC = (TotalCountBigramAC/TotalBigramCount);
    ProbOfBigramAG = (TotalCountBigramAG/TotalBigramCount);
    ProbOfBigramTA = (TotalCountBigramTA/TotalBigramCount);
    ProbOfBigramTT = (TotalCountBigramTT/TotalBigramCount);
    ProbOfBigramTC = (TotalCountBigramTC/TotalBigramCount);
    ProbOfBigramTG = (TotalCountBigramTG/TotalBigramCount);
    ProbOfBigramCA = (TotalCountBigramCA/TotalBigramCount);
    ProbOfBigramCT = (TotalCountBigramCT/TotalBigramCount);
    ProbOfBigramCC = (TotalCountBigramCC/TotalBigramCount);
    ProbOfBigramCG = (TotalCountBigramCG/TotalBigramCount);
    ProbOfBigramGA = (TotalCountBigramGA/TotalBigramCount);
    ProbOfBigramGT = (TotalCountBigramGT/TotalBigramCount);
    ProbOfBigramGC = (TotalCountBigramGC/TotalBigramCount);
    ProbOfBigramGG = (TotalCountBigramGG/TotalBigramCount);
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

    BigC = (sqrt(-2 * log(a))  * cos(2 * pi * b));
    BigD = (StandardDeviationDnaLetters * BigC) + MeanDnaLetters; 
    return BigD;
  }
