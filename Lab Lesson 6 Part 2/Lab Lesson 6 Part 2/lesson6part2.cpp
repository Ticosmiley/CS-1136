#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
   double startTemp; //variable for input starting temperature
   double endTemp; //variable for input ending temperature
   double increment; //variable for increment between temperatures converted

   cout << fixed << setprecision(3); //print numbers to three decimal places

   //take input until the input is valid
   do 
   {
      cin >> startTemp;
      cin >> endTemp;
      cin >> increment;
      if (endTemp < startTemp || increment <= 0) //if input is invalid, print an error
      {
         cout << "Starting temperature must be <= ending temperature and increment must be > 0.0\n";
      }
   } while (endTemp < startTemp || increment <= 0);

   cout << setw(15) << "Fahrenheit" << setw(15) << "Celsius" << endl; //print header for table of converted temperatures

   //calculate and print the converted temperatures
   for (double i = startTemp; i <= endTemp; i += increment)
   {
      cout << setw(15) << i << setw(15) << (i - 32) / 1.8 << endl;
   }
   
   return 0;
} //end function main()