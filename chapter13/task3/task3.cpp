
// usebrass2.cpp -- polymorphic example
// compile with brass.cpp
#include <iostream>
#include <string>
#include "dma.h"
const int NUM = 4;
int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	abcDMA * p_DMA[NUM];
	std::string tlabel, tcolor, tstyle;
	int trating;
	char kind;
	for (int i = 0; i < NUM; i++)
	{
		cout << "Enter label: ";
		getline(cin, tlabel);

		cout << "Enter rating: ";
		while (!(cin >> trating)) {
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Please enter a number: ";
		}
		while (cin.get() != '\n'); //new line

		cout << "Enter 1 for baseDMA or "
			<< "2 for lacksDMA or 3 for hasDMA: ";
		while (cin >> kind && (kind != '1' && kind != '2' && kind != '3'))
			cout <<"Enter either 1 or 2 or 3: ";
		while (cin.get() != '\n'); //new line
		switch (kind){
		case '1' :
			p_DMA[i] = new baseDMA(tlabel.c_str(), trating);
			break;
		case '2':
			cout << "Enter color: ";
			getline(cin, tcolor);
			p_DMA[i] = new lacksDMA(tcolor.c_str() , tlabel.c_str(), trating);
			break;
		case '3':
			cout << "Enter style: ";
			getline(cin, tstyle);
			p_DMA[i] = new hasDMA(tstyle.c_str() , tlabel.c_str(), trating);
			break;
		}			
		while (cin.get() != '\n')
			continue;
	}
	cout << endl;
	for (int i = 0; i < NUM; i++)
	{
		p_DMA[i]->View();
		cout << endl;
	}
	for (int i = 0; i < NUM; i++)
	{
		delete p_DMA[i]; // free memory
	}
	cout << "Done.\n";

	cin.get();
	return 0;
}
