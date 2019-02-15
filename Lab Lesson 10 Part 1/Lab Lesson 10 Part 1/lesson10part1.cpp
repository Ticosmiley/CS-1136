#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool readFile(char[], ifstream&, string);
void displayResults(char[], char[]);

int main()
{
   ifstream inFS; //input file stream
   char studentAnswers[20]; //array of student answers
   char answerKey[20]; //array of correct answers
   string studentFile; //file name of student answers
   string answerFile; //file name of answer key

   //get file names from user
   cin >> studentFile;
   cin >> answerFile;

   //if both files are opened correctly, process the scores and display the results
   //print an error if the files could not be opened
   if (readFile(studentAnswers, inFS, studentFile))
   {
      if (readFile(answerKey, inFS, answerFile))
      {
         displayResults(studentAnswers, answerKey);
      }
      else
      {
         cout << "File \"" << answerFile << "\" could not be opened\n";
      }
   }
   else
   {
      cout << "File \"" << studentFile << "\" could not be opened\n";
   }

   return 0;
} //end function main()

//this function reads values from a file and puts them into an array
bool readFile(char fileArray[], ifstream& inFS, string filename)
{
   inFS.open(filename);
   if (!inFS.good())
   {
      return false;
   }
   for (int i = 0; i < 20; i++)
   {
      inFS >> fileArray[i];
   }
   inFS.close();
   return true;
} //end function readFile()

//this function takes the array of student answers and compares it to the answer key
//it reports which questions were missed, how many weere missed, and whether the student passed
void displayResults(char studentAnswers[], char answerKey[])
{
   int missed = 0; //keeps track of how many questions missed
   double percentage; //calculated percentage score 
   for (int i = 0; i < 20; i++)
   {
      if (studentAnswers[i] != answerKey[i])
      {
         cout << "Question " << i + 1 << " has incorrect answer \'" << studentAnswers[i] << "\', the correct answer is \'" << answerKey[i] << "\'\n";
         missed++;
      }
   }
   cout << missed << " questions were missed\n";
   percentage = ((double)(20 - missed) / 20) * 100;
   if (percentage >= 70)
   {
      cout << "The student passed\n";
   }
   else
   {
      cout << "The student failed\n";
   }
   return;
} //end function displayResults()