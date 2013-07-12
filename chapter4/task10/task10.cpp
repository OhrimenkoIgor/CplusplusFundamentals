// task10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

/*
Write a program that requests the user to enter three times for the 40-yd dash (or
40-meter,if you prefer) and then displays the times and the average.Use an array
object to hold the data.(Use a built-in array if arrayis not available.)
*/

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	array<double,3> times;

	cout << "Enter first dash time: ";
	(cin >> times[0]).get();
	cout << "Enter second dash time: ";
	(cin >> times[1]).get();
	cout << "Enter third dash time: ";
	(cin >> times[2]).get();

	cout << endl << "Times:" << endl;
	double sum = 0;
	for (int i = 0; i < 3; i++){
		sum+=times[i];
		cout << times[i] << "  ";
	}
	cout << endl << "Average: " << sum / 3 << endl;	

	cin.get();
	return 0;
}

