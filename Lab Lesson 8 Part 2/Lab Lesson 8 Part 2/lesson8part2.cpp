#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double getFutureValue();
double getInterestRate();
int getYears();
double calculatePresentValue(double, double, int);
void displayResults(double, double, int, double);

int main()
{
   double futureValue; //the amount of money to be in the account in the future
   double interestRate; //the annual interest rate for the account
   int years; //the number of years the money will be in the account
   double presentValue; //the amount of money needed to be put in to get the future value

   //get the future value, interest rate, and number of years from the user
   futureValue = getFutureValue();
   interestRate = getInterestRate();
   years = getYears();
   presentValue = calculatePresentValue(futureValue, interestRate, years); //calculate the present value

   //display the results
   displayResults(futureValue, interestRate, years, presentValue);

   return 0;
} //end function main()

//this function takes a double input from the user and verifies that it is greater than zero
double getFutureValue()
{
   double futureValue;

   cout << "Enter future value\n";
   cin >> futureValue;
   while (futureValue <= 0)
   {
      cout << "The future value must be greater than zero\n";
      cout << "Enter future value\n";
      cin >> futureValue;
   }

   return futureValue;
} //end function getFutureValue()

//This function takes a double input from the user and verifies that it is greater than zero. Since the value is entered as a percentage,
//the value is first divided by 100 before being returned.
double getInterestRate()
{
   double interestRate;

   cout << "Enter annual interest rate\n";
   cin >> interestRate;
   while (interestRate <= 0)
   {
      cout << "The annual interest rate must be greater than zero\n";
      cout << "Enter annual interest rate\n";
      cin >> interestRate;
   }
   interestRate /= 100;

   return interestRate;
} //end function getInterestRate()

//this function takes an integer input from the user and verifies that it is greater than zero
int getYears()
{
   int years;

   cout << "Enter number of years\n";
   cin >> years;
   while (years <= 0)
   {
      cout << "The number of years must be greater than zero\n";
      cout << "Enter number of years\n";
      cin >> years;
   }

   return years;
} //end function getYears()

//this function uses the input future value, interest rate, and number of years to calculate the present value
double calculatePresentValue(double futureValue, double interestRate, int numberYears)
{
   double presentValue;

   presentValue = futureValue / (pow(1 + interestRate, numberYears));

   return presentValue;
} //end function present value

//this function prints the present value, future value, interest rate, and number of years
void displayResults(double futureValue, double interestRate, int numberYears, double presentValue)
{
   cout << fixed << setprecision(2) << "Present value: $" << presentValue << endl;
   cout << "Future value: $" << futureValue << endl;
   cout << setprecision(1) << "Annual interest rate: " << interestRate * 100 << "%\n";
   cout << setprecision(0) << "Years: " << numberYears << endl;

   return;
} //end function displayResults()