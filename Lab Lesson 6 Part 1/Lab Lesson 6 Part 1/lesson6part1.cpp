#include <iostream>

using namespace std;

int main()
{
   unsigned int lower = 0; //variable for input lower value
   unsigned int upper = 0; //variable for input upper value

   //while the values are not within the proper range, ask for user input
   while (!(lower >= 32 && lower <= 126) || !(upper >= 32 && upper <= 126) || !(lower < upper))
   {
      //promt the user to input two values and assign them to their respective variables
      cout << "Enter lower and upper values\n";
      cin >> lower;
      cin >> upper;  

      //if the values are invalid print a message indicating the proper range
      if (!(lower >= 32 && lower <= 126) || !(upper >= 32 && upper <= 126) || !(lower < upper))
      {
         cout << "Values must be in range 32 to 126 inclusive\n";
      }
   }

   //print the the upper and lower values and the upper border of the character display
   cout << "Characters for ASCII values between " << lower << " and " << upper << endl;
   cout << "----+----+----+-";

   //loop for as many rows will be necassary to print all the characters
   for (int i = 0; i < (double)(upper - lower) / 16; ++i)
   {
      cout << endl;
      for (int j = 0; j < 16; j++) //each row should have no more than 16 characters
      {
         //if all the characters have been printed, exit the loop
         if ((i * 16 + j) > (upper - lower))
         {
            break;
         }
         cout << (char)(i * 16 + j + lower);
      }
   }

   //print the lower border of the character display
   cout << "\n----+----+----+-\n";

   return 0;
} //end function main()