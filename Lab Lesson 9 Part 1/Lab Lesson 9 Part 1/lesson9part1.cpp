#include <iostream>
#include <iomanip>

using namespace std;

void getInfo(int&, int&, double&);
void displayResults(int, int, double);

int main()
{
   int spoolsOrder; //number of spools ordered
   int spoolsStock; //number of spools in stock
   double shippingCost = 11.88; //cost of shipping and handling per spool

   getInfo(spoolsOrder, spoolsStock, shippingCost); //get the necessary information from the user
   displayResults(spoolsOrder, spoolsStock, shippingCost); //report number of spools ready to be shipped and the cost

   return 0;
} //end function main()

//this function gets the number of spools order, the number of spools in stock, and any special shipping costs from the user
//it also checks that the spools ordered is more than 1 and that the spools in stock and the shipping cost is more than 0
void getInfo(int& spoolsOrder, int& spoolsStock, double& shippingCost)
{
   char isShipping;

   //get number of spools ordered
   do
   {
      cout << "Spools to be ordered\n";
      cin >> spoolsOrder;
      if (spoolsOrder < 1)
      {
         cout << "Spools order must be 1 or more\n";
      }
   } while (spoolsOrder < 1);

   //get number of spools in stock
   do
   {
      cout << "Spools in stock\n";
      cin >> spoolsStock;
      if (spoolsStock < 0)
      {
         cout << "Spools in stock must be 0 or more\n";
      }
   } while (spoolsStock < 0);

   //check if there are any special shipping costs
   cout << "Special shipping and handling (y or n)\n";
   cin >> isShipping;

   if (isShipping == 'y')
   {
      //get special shipping costs
      do
      {
         cout << "Shipping and handling amount\n";
         cin >> shippingCost;
         if (shippingCost < 0)
         {
            cout << "The spool shipping and handling charge must be 0.0 or more\n";
         }
      } while (shippingCost < 0);
   }
   
   return;
} //end function getInfo()

//this function displays how many spools are ready to ship, how many will be put on back-order, the subtotal of the cost,
//the cost of the shipping, and the total cost
void displayResults(int spoolsOrder, int spoolsStock, double shippingCost)
{
   int shipReady = (spoolsOrder < spoolsStock) ? spoolsOrder : spoolsStock;
   double subtotal = shipReady * 100;
   double totalShipping = shipReady * shippingCost;

   cout << "Spools ready to ship: " << shipReady << endl;
   cout << "Spools on back-order: " << spoolsOrder - shipReady << endl;
   cout << "Subtotal ready to ship: $" << fixed << setprecision(2) << setw(10) << subtotal << endl;
   cout << "Shipping and handling:  $" << setw(10) << totalShipping << endl;
   cout << "Total shipping charges: $" << setw(10) << totalShipping + subtotal << endl;

   return;
} //end function displayResults()