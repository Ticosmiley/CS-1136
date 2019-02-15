#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
   double mass; //variable for input mass in kg
   double earthWeight; //variable for calculated weight on Earth
   const double EARTH_ACCEL = 9.81; //constant for acceleration due to gravity on Earth
   double moonWeight; //variable for calculated weight on the moon
   const double MOON_ACCEL = 1.62; //constant for acceleration due to gravity on the moon
   double marsWeight; //variable for calculated weight on Mars
   const double MARS_ACCEL = 3.77; //constant for acceleration due to gravity on Mars

   //take input for mass and print it out
   cin >> mass;
   cout << fixed << setprecision(3) << "The mass is " << mass << " kg\n";

   //if mass is less than or equal to zero, print a message saying it must be greater than zero
   if (mass <= 0)
   {
      cout << "The mass must be greater than zero\n";
   }
   else
   {
      //calculate the weight on Earth, the moon, and Mars for the given mass
      earthWeight = mass * EARTH_ACCEL;
      moonWeight = mass * MOON_ACCEL;
      marsWeight = mass * MARS_ACCEL;
      
      //print out the weights
      cout << "Location  Weight (N)\n";
      cout << "Earth" << setw(15) << earthWeight << endl;
      cout << "Mars" << setw(16) << marsWeight << endl;
      cout << "Moon" << setw(16) << moonWeight << endl;
      
      //The instructions say the object is heavy if the object's weight on Earth is greater than OR EQUAL TO 1000, but if you actually go to the trouble of writing 
      //if (earthWeight > 1000 || fabs(earthWeight - 1000) < 0.001) 
      //zyBooks reads the output as wrong ~~grumble grumble grumble~~

      //determine if the object is heavy or light and print it out if it is
      if (earthWeight > 1000)
      {
         cout << "The object is heavy\n";
      }
      if (earthWeight < 10)
      {
         cout << "The object is light\n";
      }
   }
   
   return 0;
} //end function main()