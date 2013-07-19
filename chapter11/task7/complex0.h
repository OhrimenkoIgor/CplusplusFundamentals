
#ifndef COMPLEX0_H_
#define COMPLEX0_H_

#include <iostream>

class complex{
private:
	double re;
	double im;
public:
	complex(double r = 0, double i = 0): re(r), im(i){}

	complex operator~();
	complex operator+(const complex & c);
	complex operator-(const complex & c);
	complex operator*(const complex & c);
	friend complex operator*(double x, const complex & c);

	friend std::istream & operator>> (std::istream & is, complex & c);
	friend std::ostream & operator<< (std::ostream & os, const complex & c);
};

#endif //COMPLEX0_H_