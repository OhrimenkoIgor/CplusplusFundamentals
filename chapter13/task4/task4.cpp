
/*

b. 
	void Show() const; //virtual, need to show another content
c.
	operator=(); //assignment operator is not inherited
	operator<<(); //friends are not inherited

*/

#include <iostream>
#include <string>

#include "vintageport.h"

const int NUM = 4;

int main(){
	using std::cin;
	using std::cout;
	using std::endl;
	Port * p_port[NUM];
	std::string tbrand, tstyle, tnickname;
	int tbottles, tyear;
	for (int i = 0; i < NUM; i++)
	{
		cout << "Enter brand: ";
		getline(cin, tbrand);

		cout << "Enter style: ";
		getline(cin, tstyle);

		cout << "Enter bottles: ";
		while (!(cin >> tbottles)) {
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Please enter a number: ";
		}
		while (cin.get() != '\n'); //new line

		if(tstyle != "vintage"){
			p_port[i] = new Port(tbrand.c_str(), tstyle.c_str(), tbottles);;
		} else {
			cout << "Enter nickname: ";
			getline(cin, tnickname);

			cout << "Enter year: ";
			while (!(cin >> tyear)) {
				cin.clear();
				while (cin.get() != '\n')
					continue;
				cout << "Please enter a number: ";
			}
			while (cin.get() != '\n'); //new line

			p_port[i] = new VintagePort(tbrand.c_str(), tbottles, tnickname.c_str(), tyear);
		}			
		while (cin.get() != '\n')
			continue;
	}
	cout << endl;
	for (int i = 0; i < NUM; i++)
	{
		p_port[i]->Show();
		cout << endl;
	}
	for (int i = 0; i < NUM; i++)
	{
		delete p_port[i]; // free memory
	}
	cout << "Done.\n";

	cin.get();
	return 0;
}
