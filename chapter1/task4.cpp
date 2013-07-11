#include <iostream>

using namespace std;

int main()
{
   int months, years;
   const int months_in_year = 12;
   cout << "Enter your age: "; 
   cin >> years;
   cout << endl << "Your age in months is " << years *  months_in_year << endl;
   
   return 0;
}