#include <iostream>

using namespace std;

double ly_to_au(double years){
    return  63240 * years;
}

int main()
{
   double years;
   cout << "Enter the number of light years: "; 
   cin >> years;
   cout << endl << years << " light years = " << ly_to_au(years) <<" astronomical units." << endl;
   
   return 0;
}