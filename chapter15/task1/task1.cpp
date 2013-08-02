
#include <iostream>

#include "tv.h"

using namespace std;

int main(){

	Tv s42;
	cout << "Initial settings for 42\" TV: \n";
	s42.settings();
	s42.onoff();
	s42.chanup();
	cout << "\nAdjusted settings for 42\" TV: \n";
	s42.settings();

	Remote grey;
	cout << "Remote control mode: ";
	grey.display_rcmode();
	s42.set_rcmode(grey);
	cout << "Remote control mode after set_rcmode: ";
	grey.display_rcmode();

	cout << "TV off";
	s42.onoff();
	s42.set_rcmode(grey);
	cout << "Remote control mode after set_rcmode by off tv: ";
	grey.display_rcmode();

	cin.get();
	return 0;
}