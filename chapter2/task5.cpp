#include <iostream>

using namespace std;

int celsius_to_fahrenheit(int celsius){
    return  1.8 * celsius + 32.0;
}

int main()
{
   int celsius;
   cout << "Please enter a Celsius value: "; 
   cin >> celsius;
   cout << endl << celsius << " degrees Celsius is " << celsius_to_fahrenheit(celsius) <<" degrees Fahrenheit." << endl;
   cout << "For reference,here is the formula for making the conversion:" <<endl;
   cout << "Fahrenheit = 1.8 × degrees Celsius + 32.0" <<endl;
   
   return 0;
}