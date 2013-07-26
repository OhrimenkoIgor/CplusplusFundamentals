
#include <iostream>

#include "cow.h"

int main(){

	Cow cow1;
	std::cout << "cow1:" << std::endl;
	cow1.ShowCow();

	Cow cow2("Jane", "handball", 45.9);
	std::cout << "cow2:" << std::endl;
	cow2.ShowCow();

	Cow cow3(cow2);
	std::cout << "cow3:" << std::endl;
	cow3.ShowCow();

	cow1 = cow3;
	std::cout << "now cow1:" << std::endl;
	cow1.ShowCow();

	std::cin.get();
	return 0;
}