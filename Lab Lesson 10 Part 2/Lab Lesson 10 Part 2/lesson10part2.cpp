#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

const int MAX_COLUMNS = 5; //constant for max number of columns

int readFile(double[][MAX_COLUMNS], int, string);
double average(double[][MAX_COLUMNS], int);
double columnAverage(double[][MAX_COLUMNS], int, int);
double findSmallest(double[][MAX_COLUMNS], int);

int main()
{
   const int MAX_ROWS = 20; //constant for max number of rows
   string inputFileName; //input file name
   double grades[MAX_ROWS][MAX_COLUMNS]; //2-dimensional array holding all the grades
   int actualRows; //number of rows read from the input file

   cout << fixed << setprecision(2); //print doubles to 2 decimal places

   cin >> inputFileName; //get input file name from user
   actualRows = readFile(grades, MAX_ROWS, inputFileName); //read grades from file into the array

   if (actualRows == -1) //if the file couldnt be opened, print an error
   {
      cout << "File \"" << inputFileName << "\" could not be opened\n";
      return 1;
   }
   else if (actualRows == 0) //if the file had no data, print an error
   {
      cout << "The input file \"" << inputFileName << "\" did not contain any data\n";
      return 1;
   }
   else
   {
      //display the calculated results of all the grades
      cout << "Processing " << actualRows << " rows, and " << MAX_COLUMNS << " columns\n";
      cout << "Average for all values is " << average(grades, actualRows) << endl;
      for (int i = 0; i < MAX_COLUMNS; i++)
      {
         cout << "Average for column " << i << " is " << columnAverage(grades, i, actualRows) << endl;
      }
      for (int i = 0; i < actualRows; i++)
      {
         cout << "Smallest value for row " << i << " is " << findSmallest(grades, i) << endl;
      }
   }

   return 0;
} //end function main()

//this function reads the values from an input file and puts them into a 2-dimensional array
//if the file can't be opened it returns -1
//if the there is no data in the file it returns 0
//otherwise it returns the number of rows read from the file
int readFile(double values[][MAX_COLUMNS], int maxRows, string inputFileName)
{
   int col = MAX_COLUMNS; //keeps track of current column
   int row = 0; //keeps track of current row
   ifstream inFS; //input file stream

   inFS.open(inputFileName);
   if (!inFS.good())
   {
      return -1;
   }
   else
   {
      while (row < maxRows && col == MAX_COLUMNS)
      {
         col = 0;
         while (col < MAX_COLUMNS && inFS >> values[row][col])
         {
            col++;
         }
         if (col < MAX_COLUMNS && row == 0)
         {
            inFS.close();
            return 0;
         }
         if (col == MAX_COLUMNS)
         {
            row++;
         }
      }
      inFS.close();
      return row;
   }
} //end function readFile()

//this function calculates the average of all grades in the array
double average(double values[][MAX_COLUMNS], int numberRows)
{
   double sum = 0; //calculated sum of all grades
   int totValues = numberRows * MAX_COLUMNS; //total number of grades

   for (int i = 0; i < numberRows; i++)
   {
      for (int j = 0; j < MAX_COLUMNS; j++)
      {
         sum += values[i][j];
      }
   }
   return sum / totValues;
} //end function average()

//this function calculates the average of all grades in one column
double columnAverage(double values[][MAX_COLUMNS], int column, int numberRows)
{
   double sum = 0; //calculated sum of grades in the column

   for (int i = 0; i < numberRows; i++)
   {
      sum += values[i][column];
   }
   return sum / numberRows;
} //end function columnAverage()

//this function finds the lowest grade in a given row
double findSmallest(double values[][MAX_COLUMNS], int row)
{
   double smallest = 101; //keeps track of smallest value in the row

   for (int i = 0; i < MAX_COLUMNS; i++)
   {
      if (smallest > values[row][i])
      {
         smallest = values[row][i];
      }
   }
   return smallest;
} //end function findSmallest()