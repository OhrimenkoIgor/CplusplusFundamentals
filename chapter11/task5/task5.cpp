
#include <iostream>

#include "stonewt.h"

using namespace std;

int main(){
	Stonewt wt1(140.7), wt2(16.8), wt3;

	cout << "wt1 = " << wt1 << endl; 
	cout << "wt2 = " << wt2 << endl; 
	cout << "wt3 = " << wt3 << endl; 

	cout << "wt3 = wt1 + wt2" << endl;
	wt3 = wt1 + wt2;
	cout << "wt3 = " << wt3 << endl;

	cout << "wt3 -= wt2 * 2" << endl;
	wt3 = wt3 - wt2 * 2;
	cout << "Stones: wt3 = " << wt3 << endl;

	wt3.set_mode(Stonewt::FP_POUNDS);
	cout << "Fractional pounds: wt3 = " << wt3 << endl;

	wt3.set_mode(Stonewt::POUNDS);
	cout << "Pounds: wt3 = " << wt3 << endl;

	cin.get();
	return 0;
}
