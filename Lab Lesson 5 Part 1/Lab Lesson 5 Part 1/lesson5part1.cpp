#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
   unsigned int medium; //variable that stores user's choice of medium
   double distance; //variable for input distance sound travels
   const int AIR_SPEED = 1100; //constant for speed of sound through air
   const int WATER_SPEED = 4900; //constant for speed of sound through water
   const int STEEL_SPEED = 16400; //constant for speed of sound through steel

   cout << fixed << setprecision(1); //print numbers to one decimal place

   //display prompt for user to select a medium
   cout << "Select the medium that sound is traveling through:\n";
   cout << "1 Air\n";
   cout << "2 Water\n";
   cout << "3 Steel\n";

   cin >> medium; //get user input for medium

   switch (medium)
   {
      //check if input is valid i.e. 1-3
      case 1:
      case 2:
      case 3:
         //if input is valid, take input for the distance the sound travels
         cout << "Enter distance (in feet)\n";
         cin >> distance;

         //if the input distance is less than or equal to zero, tell user it must be greater than zero
         if (distance <= 0)
         {
            cout << "The distance must be greater than zero\n";
         }
         else
         {
            //if the input distance is valid, calculate the time the sound travels based on the selected medium
            switch (medium)
            {
            case 1:
               cout << "Air: " << distance << " ft\n";
               cout << "Traveled for " << distance / AIR_SPEED << " seconds\n";
               break;
            case 2:
               cout << "Water: " << distance << " ft\n";
               cout << "Traveled for " << distance / WATER_SPEED << " seconds\n";
               break;
            case 3:
               cout << "Steel: " << distance << " ft\n";
               cout << "Traveled for " << distance / STEEL_SPEED << " seconds\n";
               break;
            }
         }
         break;

      //if input is not valid, tell user to start again
      default:
         cout << "The menu value is invalid. Please run the program again.\n";
         break;
   }

   return 0;
} //end function main()