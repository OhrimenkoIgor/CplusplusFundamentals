
#include <cstring>

#include "port.h"

Port::Port(const char * br, const char * st, int b) : bottles(b) {
	if(br){
		brand = new char[strlen(br) + 1];
		strcpy(brand, br);
	} else {
		brand = new char[1];
		brand = '\0';
	}
	if(st){
		strncpy(style, st, 19);
		style[19] = '\0';
	}else{
		style[0] = '\0';
	}
}

Port::Port(const Port & p) : bottles(p.bottles) {
	brand = new char[strlen(p.brand) + 1];
	strcpy(brand, p.brand);
	strcpy(style, p.style);
}

Port & Port::operator=(const Port & p){
	if (this != &p){
		bottles = p.bottles;

		delete [] brand;
		brand = new char[strlen(p.brand) + 1];
		strcpy(brand, p.brand);

		strcpy(style, p.style);
	}

	return *this;
}

Port & Port::operator+=(int b){
	bottles += b;
	return *this;
}

Port & Port::operator-=(int b){
	bottles -= b;
	return *this;
}

void Port::Show() const{
	cout << "Brand: " << brand << endl
		<< "Kind: " << style << endl
		<< "Bottles: " << bottles << endl;
}

ostream & operator<<(ostream & os, const Port & p){
	cout << p.brand << ", " << p.style << ", " << p.bottles;
	return os;
}
