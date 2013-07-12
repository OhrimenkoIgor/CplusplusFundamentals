#include <iostream>

#define INCHES_IN_FOOT 12
#define METERS_IN_INCH 0.0254
#define POUNDS_IN_KILOGRAM 2.2

using namespace std;

int main()
{
   //part 1
   int total_inches, inches, feet, pounds;
   cout << "Enter your height in integer inches:__\b\b";
   cin >> total_inches;
   feet = total_inches / INCHES_IN_FOOT;
   inches = total_inches % INCHES_IN_FOOT;   
   cout << endl << total_inches << " inches = " << feet << " feet, " << inches 
        << " inches" << endl;

   //part 2
   cout << "Enter your height in feet and inches:" << endl;
   cout << endl << "Enter feet:";
   cin >> feet;
   cout << endl << "Enter inches:";
   cin >> inches;
   cout << endl << "Enter your weight in pounds:";
   cin >> pounds;
   int heihgt_in_inches = feet * INCHES_IN_FOOT + inches;
   double heihgt_in_meters = heihgt_in_inches * METERS_IN_INCH;
   double kilograms = pounds / POUNDS_IN_KILOGRAM;
   double bmi = kilograms / (heihgt_in_meters * heihgt_in_meters);
   cout << endl << "Your BMI is " << bmi << endl;

   return 0;
}