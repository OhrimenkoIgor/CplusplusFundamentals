
// stonewt.h -- definition for the Stonewt class
#ifndef STONEWT_H_
#define STONEWT_H_

#include <iostream>

class Stonewt
{
public:
	enum Mode {STONE, POUNDS, FP_POUNDS};
private:
	Mode mode;
	enum {Lbs_per_stn = 14}; // pounds per stone
	int stone; // whole stones
	double pds_left; // fractional pounds
	double pounds; // entire weight in pounds
public:
	Stonewt(double lbs); // constructor for double pounds
	Stonewt(int stn, double lbs); // constructor for stone, lbs
	Stonewt(); // default constructor
	~Stonewt();
	void set_mode(Mode m) {mode = m;}; // set mode

	Stonewt operator+(const Stonewt & o) const;
	Stonewt operator-(const Stonewt & o) const;
	Stonewt operator*(double d) const;

	friend std::ostream & operator<<(std::ostream & os, const Stonewt & swt);

};
#endif
