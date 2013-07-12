#include <iostream>

using namespace std;

void display_time(int hours, int minutes){
    cout << "Time: " << hours << ":" << minutes << endl;
}

int main()
{
   int hours, minutes;
   cout << "Enter the number of hours: "; 
   cin >> hours;
   cout << endl << "Enter the number of minutes: ";
   cin >> minutes;
   cout << endl;
   display_time(hours, minutes);
   
   return 0;
}