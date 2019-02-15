#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
   ifstream inFS; //input file stream
   ofstream outFS; //output file stream
   long long store1; //variable for the sales of store 1
   long long store2; //variable for the sales of store 2
   long long store3; //variable for the sales of store 3
   long long store4; //variable for the sales of store 4
   long long store5; //variable for the sales of store 5
   string fileName; //variable for input file name

   cin >> fileName; //take input for file name

   //open the file and check if it was opened sucessfully, if not return an error
   inFS.open(fileName);
   if (!inFS.is_open())
   {
      cout << "File \"" << fileName << "\" could not be opened\n";
      return 1;
   }

   //take input from the filee for the sales of each store
   //if the end of the file is reached before five values are found, return an error
   inFS >> store1;
   inFS >> store2;
   inFS >> store3;
   inFS >> store4;
   inFS >> store5;
   if (inFS.eof())
   {
      cout << "Your input file must contain the sales values for five stores\n";
      return 1;
   }

   //if any of the sales values are negative, return an error
   if ((store1 < 0) || (store2 < 0) || (store3 < 0) || (store4 < 0) || (store5 < 0))
   {
      cout << "One or more of the sales values are negative\n";
      return 1;
   }

   inFS.close(); //close the input file
   outFS.open("saleschart.txt"); //open the output file

   //output the chart header to the output file
   outFS << "SALES BAR CHART\n";
   outFS << "(Each X equals 1,000 dollars)\n";

   //output the sales chart to the output file, printing an "X" for every $1000 of sales
   outFS << "Store 1: ";
   for (int i = 0; i < store1 / 1000; i++)
   {
      outFS << "X";
   }
   outFS << endl << "Store 2: ";
   for (int i = 0; i < store2 / 1000; i++)
   {
      outFS << "X";
   }
   outFS << endl << "Store 3: ";
   for (int i = 0; i < store3 / 1000; i++)
   {
      outFS << "X";
   }
   outFS << endl << "Store 4: ";
   for (int i = 0; i < store4 / 1000; i++)
   {
      outFS << "X";
   }
   outFS << endl << "Store 5: ";
   for (int i = 0; i < store5 / 1000; i++)
   {
      outFS << "X";
   }
   outFS << endl;

   outFS.close(); //close the output file

   return 0;
} //end function main()