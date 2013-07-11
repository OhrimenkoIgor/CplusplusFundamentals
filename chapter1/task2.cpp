#include <iostream>

using namespace std;

int main()
{
   int furlongs, yards;
   const int yards_in_furlong = 220;
   cout << "Enter distance in furlongs: "; 
   cin >> furlongs;
   cout << endl << "Yards: " << furlongs * yards_in_furlong << endl;
   
   return 0;
}