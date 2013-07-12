#include <iostream>

using namespace std;

int main()
{
   long long world_population, us_population;
   cout << "Enter the world's population:";
   cin >> world_population;
   cout << endl << "Enter the population of the US:";
   cin >> us_population;
   cout << endl << "The population of the US is " 
        << double (us_population) / world_population * 100 
        << "% of the world population." << endl;
   cout << "You can use the Internet to get more recent figures." << endl;
   
   return 0;
}
