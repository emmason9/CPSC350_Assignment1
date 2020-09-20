/*
Emilee mason
ID# 2321064
emmason@chapman.edu
CPSC 350-01
Assignment 1: C++ Review

main.cpp
This is the main file for the DnaStats class. This runs all the implementation
created in the DnaStats.cpp class. It also contains a while loop to continue
processing through each new file name given.
*/
#include "DnaStats.h"

int main(int argc, char** argv){
  string DnaLine;             //for each individual line of DNA from the reader
  string FileName = argv[1];  //to start off the program with right file name
  DnaStats *DNAStats;         //to have a pointer to a new object each time.

//for looping through the process for each new file name
  while(DNAStats->ProcessFile){
    cout << "Let's start by grabing the " << FileName << " file." << endl;
    DNAStats = new DnaStats();
    DNAStats->RunDnaStats(DNAStats, FileName, DnaLine);
    FileName = DNAStats->GetNewFileName();
  } //end of while loop
  delete DNAStats;
  return 0;
};
