#include <iostream>

using namespace std;

int main()
{
   double kilometers, liters;
   cout << "Enter distance in kilometers:";
   cin >> kilometers;
   cout << endl << "Enter petrol in liters:";
   cin >> liters;
   cout << endl << "You car gasoline consumption is " << liters / (kilometers / 100) 
        << " liters per 100 kilometers." << endl;
  
   return 0;
}