#include <iostream>

#define MILES_IN_KILOMETER (62.14 / 100)
#define LITERS_IN_GALLON 3.875

using namespace std;

int main()
{
   double liters_per_100_kilometers, miles_per_gallon;
   cout << "Enter gasoline consumption in liters per 100 kilometers:";
   cin >> liters_per_100_kilometers;
   miles_per_gallon = 1 / (liters_per_100_kilometers / 100) * LITERS_IN_GALLON * MILES_IN_KILOMETER;
   cout << endl << "You car gasoline consumption is " << miles_per_gallon 
        << " miles per gallon." << endl;
  
   return 0;
}