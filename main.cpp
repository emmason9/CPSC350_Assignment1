//main file for Dnastats
#include "DnaStats.h"

int main(int argc, char** argv){
  string DnaLine; //for each individual line of DNA from the reader
  int LineNumber = 0;
  string FileName = argv[1];
  bool ProcessFile = true;
  DnaStats *DNAStats;
  string UserInput;

//while(ProcessFile){
  cout << "Let's start by grabing the " << FileName << " file." << endl;
  DNAStats = new DnaStats();
  DNAStats->RunDnaStats(DNAStats, FileName, DnaLine);


  cout << "Total Lines: " << DNAStats->GetTotalLines() << endl;
  cout << "Total bigram: " << DNAStats->GetTotalBigramCount() << endl;
  cout << "Prob A: " << DNAStats->GetProbOfNucleotideA() << endl;
  cout << "Prob T: " << DNAStats->GetProbOfNucleotideT() << endl;

/* //test if you want to do through file again
  ProcessFile = RunAgain();
*/
//} //end of while loop

  delete DNAStats;
  return 0;
};
