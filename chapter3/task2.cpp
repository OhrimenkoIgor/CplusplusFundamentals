#include <iostream>

#define SECONDS_IN_MINUTE 60
#define MINUTES_IN_DEGREE 60

using namespace std;

int main()
{
   int degrees, minutes, seconds;
   cout << "Enter a latitude in degrees, minutes, and seconds:" << endl; 
   cout << "First, enter the degrees:";
   cin >> degrees;
   cout << endl << "Next, enter the minutes of arc:";
   cin >> minutes;
   cout << endl << "Finally, enter the seconds of arc:";
   cin >> seconds;
   double latitude = degrees + double(minutes) / MINUTES_IN_DEGREE 
        + double(seconds) / (SECONDS_IN_MINUTE * MINUTES_IN_DEGREE);
   cout << endl << degrees << " degrees, " << minutes << " minutes, " 
        << seconds << " seconds = " << latitude << " degrees" << endl;
   
   return 0;
}
