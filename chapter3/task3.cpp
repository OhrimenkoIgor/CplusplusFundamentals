#include <iostream>

#define HOURS_IN_DAY 24
#define MINUTES_IN_HOUR 60
#define SECOMDS_IN_MINUTE 60

using namespace std;

int main()
{
   int days, hours, minutes, seconds;
   long long total_seconds;
   cout << "Enter the number of seconds:";
   cin >> total_seconds;
   days = total_seconds / (HOURS_IN_DAY * MINUTES_IN_HOUR * SECOMDS_IN_MINUTE);
   hours = total_seconds / (MINUTES_IN_HOUR * SECOMDS_IN_MINUTE) % HOURS_IN_DAY;
   minutes = total_seconds / SECOMDS_IN_MINUTE % MINUTES_IN_HOUR;
   seconds = total_seconds % SECOMDS_IN_MINUTE;   
   cout << endl << total_seconds << " seconds = " << days << " days, " << hours 
        << " hours, " << minutes << " minutes, " << seconds << " seconds" << endl;   
   
   return 0;
}