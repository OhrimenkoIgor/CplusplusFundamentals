#include <iostream>
#include <utility>

#include "cpmv.h"

int main() {
	using namespace std;

	cout << "o1:" << endl;
	Cpmv o1;
	o1.Display();
	cout << endl;

	cout << "o2:" << endl;
	Cpmv o2 { "o2_qcode", "o2_zcode" };
	o2.Display();
	cout << endl;

	cout << "o3:" << endl;
	Cpmv o3 { "o3_qcode", "o3_zcode" };
	o3.Display();
	cout << endl;

	cout << "o4:" << endl;
	Cpmv o4 { o3 };
	o4.Display();
	cout << endl;

	cout << "o5:" << endl;
	Cpmv o5 { o2 + o4 };
	o5.Display();
	cout << endl;

	cout << "o6:" << endl;
	Cpmv o6 { std::move(Cpmv("o6_qcode", "o6_zcode")) };
	o6.Display();
	cout << endl;

	cout << "o1 = o5:" << endl;
	o1 = o5;
	o1.Display();
	cout << endl;

	cout << "o4 = o2 + o4:" << endl;
	o4 = o2 + o4;
	o4.Display();
	cout << endl;

	return 0;
}
