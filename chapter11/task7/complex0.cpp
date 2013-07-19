
#include "complex0.h"

using namespace std;

complex complex::operator~(){
	return complex(re, -im);
}

complex complex::operator+(const complex & c){
	return complex(re + c.re, im + c.im);
}

complex complex::operator-(const complex & c){
	return complex(re - c.re, im - c.im);
}

complex complex::operator*(const complex & c){
	return complex(re * c.re - im * c.im, re * c.im + c.re * im);
}

complex operator*(double x, const complex & c){
	return complex(x * c.re, x * c.im);
}

std::istream & operator>> (std::istream & is, complex & c){
	std::cout << "real:";
	is >> c.re;
	if (!is) return is;
	std::cout << "imaginary:";
	is >> c.im;
	return is;
}

std::ostream & operator<< (std::ostream & os, const complex & c){
	return os << "(" << c.re << "," << c.im << "i)";
}
