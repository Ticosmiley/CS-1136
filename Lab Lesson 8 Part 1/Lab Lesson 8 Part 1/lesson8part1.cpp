#include <iostream>
#include <iomanip>

using namespace std;

double readSeconds();
void displayResults(double, double);
double calculateDistance(double);

int main()
{
   double seconds = -1; //seconds the object travels
   double distance; //meters the object travels

   //continue asking for input and calculating distance as long as the input is not 0
   while (seconds != 0)
   {
      seconds = readSeconds();
      if (seconds == 0)
      {
         continue;
      }
      distance = calculateDistance(seconds);
      displayResults(seconds, distance);
   }

   return 0;
} //end function main()

//this function takes a double input form the user and verifies that it is greater or equal to 0
double readSeconds()
{
   double seconds;

   cout << "Enter the time (in seconds)\n";
   cin >> seconds;
   while (seconds < 0)
   {
      cout << "The time must be zero or more\n";
      cout << "Enter the time (in seconds)\n";
      cin >> seconds;
   }

   return seconds;
} //end function readSeconds()

//this function prints the calculated distance and the input seconds
void displayResults(double seconds, double distance)
{
   cout << fixed << setprecision(2) << "The object traveled " << distance << " meters in " << setprecision (1) << seconds << " seconds\n";

   return;
} //end function displayResults()

//this function calcualtes the distance travelled in meters over the input seconds
double calculateDistance(double seconds)
{
   double distance;

   distance = 1.0 / 2 * 9.8 * seconds * seconds;

   return distance;
} //end function calculateDistance()