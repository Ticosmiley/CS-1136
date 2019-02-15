#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
   unsigned int medium; //variable that stores user's choice of medium
   double seconds; //variable for input time sound travels
   const double CO2_SPEED = 258; //constant for speed of sound through carbon dioxide
   const double AIR_SPEED = 331.5; //constant for speed of sound through air
   const double HELIUM_SPEED = 972; //constant for speed of sound through helium
   const double HYDROGEN_SPEED = 1270; //constant for speed of sound through hydrogen

   cout << fixed << setprecision(1); //print numbers to one decimal place

   //display prompt for user to select a medium
   cout << "Select the medium that sound is traveling through:\n";
   cout << "1 Carbon Dioxide\n";
   cout << "2 Air\n";
   cout << "3 Helium\n";
   cout << "4 Hydrogen\n";

   cin >> medium; //get user input for medium

   //check if input is valid i.e. 1-4
   if (medium == 0 || medium > 4)
   {
      cout << "The menu value is invalid. Please run the program again.\n"; //if input is invalid, tell user to start again
   }
   else
   {
      //if input is valid, take input for the time the sound travels
      cout << "Enter time (in seconds)\n";
      cin >> seconds;

      //if the input time is not between 0 and 30, tell user it must be between 0 and 30
      if (seconds < 0 || seconds > 30)
      {
         cout << "The time must be between 0.0 and 30.0 (inclusive)\n";
      }
      else
      {
         //if the input distance is valid, calculate the time the sound travels based on the selected medium
         if (medium == 1)
         {
            cout << "Carbon Dioxide: " << seconds << " seconds\n";
            cout << setprecision(2) << "Traveled " << seconds * CO2_SPEED << " meters\n";
         }
         else if (medium == 2)
         {
            cout << setprecision(1) << "Air: " << seconds << " seconds\n";
            cout << setprecision(2) << "Traveled " << seconds * AIR_SPEED << " meters\n";
         }
         else if (medium == 3)
         {
            cout << setprecision(1) << "Helium: " << seconds << " seconds\n";
            cout << setprecision(2) << "Traveled " << seconds * HELIUM_SPEED << " meters\n";
         }
         else
         {
            cout << setprecision(1) << "Hydrogen: " << seconds << " seconds\n";
            cout << setprecision(2) << "Traveled " << seconds * HYDROGEN_SPEED << " meters\n";
         }
      }
   }

   return 0;
} //end function main()