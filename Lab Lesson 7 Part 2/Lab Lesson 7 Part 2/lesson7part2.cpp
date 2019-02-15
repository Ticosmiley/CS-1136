#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
   ifstream infs; //input file stream
   ofstream outfs; //output file stream
   string filename; //variable for name of file to take input from
   double num; //variable to hold numbers read from input file
   double sum = 0; //sum of valid numbers from input file
   int invalids = 0; //number of invalid numbers from input file
   int valids = 0; //number of valid numbers from input file
   int total = 0; //total number of numbers from input file

   //set output of numbers to fixed
   cout << fixed;
   outfs << fixed;

   cin >> filename; //take input for the name of the input file

   infs.open(filename); //open input file
   if (!infs.good()) //check to make sure the file could be opened
   {
      cout << "File \"" << filename << "\" could not be opened\n";
   }
   else
   {
      outfs.open("invalid-numbers.txt"); //open output file
      //take input from the input file until reaching the end of the file
      while (!infs.eof())
      {
         infs >> num;
         //check to make sure that a value was read
         if (infs.good())
         {
            //if the number is invalid, add it to the invalid numbers file
            if (num < 0 || num > 110)
            {
               outfs << setprecision(2) << num << endl;
               invalids++;
            }
            else //otherwise add it to the sum of valid numbers
            {
               sum += num;
               valids++;
            }
            total++;
         }
      }
      //close the input and output files
      infs.close();
      outfs.close();

      //print the results
      cout << "Reading from file \"" << filename << "\"\n";
      cout << "Total values: " << total << endl;
      cout << "Invalid values: " << invalids << endl;
      cout << "Valid values: " << valids << endl;
      //if an average could not be calculated, print an error
      if (valids > 1)
      {
         cout << "Average of valid values: " << setprecision(2) << sum / valids << endl;
      }
      else
      {
         cout << "An average cannot be calculated\n";
      }
   }

   return 0;
} //end function main()