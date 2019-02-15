#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

unsigned int readFile(double&, double&, int&, ifstream&); //this function gets the present value, interest rate, and number of months from the input file
double calculateFutureValue(double, double, int); //this function calculates the future value
void writeFile(double, double, double, int, ofstream&); //this function writes the results to the output spreadsheet

int main()
{
   double futureValue; //variable for the future value
   double presentValue; //variable for the present value
   double interestRate; //variable for the interest rate
   int months; //variable for the number of months
   ifstream inFS; //input file stream
   ofstream outFS; //output file stream
   string fileName; //variable for the name of the input file
   unsigned int readState; //variable to hold return value of readFile()

   //print all double values to 2 decimal places
   cout << fixed << setprecision(2);
   outFS << fixed << setprecision(2);

   //get the name of the input file from the user
   cin >> fileName;

   //open the input file and make sure it's opened properly
   inFS.open(fileName);
   if (!inFS.good())
   {
      cout << "File \"" << fileName << "\" could not be opened\n";
      return 1;
   }

   //open the output file and make sure it's opened properly
   outFS.open("output.xls");
   if (!outFS.good())
   {
      inFS.close();
      cout << "File \"output.xls\" could not be opened\n";
      return 1;
   }

   //print the header to the output file
   outFS << "Future Value\tPresent Value\tMonthly Interest\tMonths" << endl;

   //while the end of the file hasn't been reached, take input from the input file and either calculate the future values and write them to the output file
   //or print an error when the input is invalid
   do
   {        
      readState = readFile(presentValue, interestRate, months, inFS);
      switch (readState)
      {
         case 1:
            interestRate /= 100;
            futureValue = calculateFutureValue(presentValue, interestRate, months);
            writeFile(futureValue, presentValue, interestRate * 100, months, outFS);
            break;
         case 2:
            cout << presentValue << " " << interestRate << " " << months << endl;
            cout << "One or more of the above values are not greater than zero\n";
            break;
      }
   } while (readState != 0);

   //close the input and output files
   inFS.close();
   outFS.close();

   return 0;
} //end function main()

unsigned int readFile(double& presentValue, double& interestRate, int& months, ifstream& inFS)
{
   //take input for present value, interest rate, and number of months
   //if the end of the file is reached, return 0
   inFS >> presentValue;
   if (inFS.eof())
   {
      return 0;
   }
   inFS >> interestRate;
   if (inFS.eof())
   {
      return 0;
   }
   inFS >> months;

   //if any values are invalid, return 2 otherwise return 1
   if (presentValue <= 0 || interestRate <= 0 || months <= 0)
   {
      return 2;
   }
   else
   {
      return 1;
   }
} //end function readFile()

double calculateFutureValue(double presentValue, double interestRate, int months)
{
   return presentValue * pow((1 + interestRate), months); //formula to calculate future value
} //end function calculateFutureValue()

void writeFile(double futureValue, double presentValue, double interestRate, int months, ofstream& outFS)
{
   //print future value, present value, interest rate, and number of months to output file
   outFS << futureValue << "	" << presentValue << "	" << interestRate << "	" << months << endl; 
   return;
} //end function writeFile()
