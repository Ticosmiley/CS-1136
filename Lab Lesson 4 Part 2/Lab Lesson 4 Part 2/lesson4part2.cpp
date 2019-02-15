#include <iostream>

using namespace std;

int main()
{
   long long seconds; //variable for input total seconds
   long long days = 0; //variable for calculated number of days
   long long hours = 0; // variable for calculated number of hours
   long long minutes = 0; //variable for calculated number of minutes

   //take input for total seconds and print it out
   cin >> seconds;
   cout << "Total seconds: " << seconds << endl << endl;

   //if the total seconds are less than or equal to zero, print a message saying it must be greater than zero
   if (seconds <= 0)
   {
      cout << "Total seconds must be greater than zero\n";
   }
   else
   {
      if (seconds >= 86400) //if there is at least one day, calculate the total number of days and print it
      {
         days = seconds / 86400;
         cout << days << " day(s)\n";
      }
      if (seconds - days * 86400 >= 3600) //if there is at least one hour remaining, calculate the total hours remaining and print it
      {
         hours = (seconds - days * 86400) / 3600;
         cout << hours << " hour(s)\n";
      }
      if (seconds - days * 86400 - hours * 3600 >= 60) //if there is at least one minute remaining, calculate the total minutes remaining and print it
      {
         minutes = (seconds - days * 86400 - hours * 3600) / 60;
         cout << minutes << " minute(s)\n";
      }
      if (seconds - days * 86400 - hours * 3600 - minutes * 60 > 0) //if there is at least 1 second remaining, calculate the total remaining seconds and print it
      {
         cout << seconds - days * 86400 - hours * 3600 - minutes * 60 << " second(s)\n";
      }
   }

   return 0;
} //end function main()