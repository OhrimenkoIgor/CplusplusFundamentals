
// stonewt.cpp -- Stonewt methods
#include <iostream>
using std::cout;
using std::endl;
#include "stonewt.h"
// construct Stonewt object from double value
Stonewt::Stonewt(double lbs)
{
	stone = int (lbs) / Lbs_per_stn; // integer division
	pds_left = int (lbs) % Lbs_per_stn + lbs - int(lbs);
	pounds = lbs;
	mode = STONE;
}
// construct Stonewt object from stone, double values
Stonewt::Stonewt(int stn, double lbs)
{
	stone = stn;
	pds_left = lbs;
	pounds = stn * Lbs_per_stn +lbs;
	mode = STONE;
}
Stonewt::Stonewt() // default constructor, wt = 0
{
	stone = pounds = pds_left = 0;
	mode = STONE;
}
Stonewt::~Stonewt() // destructor
{
}

Stonewt Stonewt::operator+(const Stonewt & o) const{
	return Stonewt(this->pounds + o.pounds);
}

Stonewt Stonewt::operator-(const Stonewt & o) const{
	return Stonewt(this->pounds - o.pounds);
}

Stonewt Stonewt::operator*(double d) const{
	return Stonewt(this->pounds* d);
}

std::ostream & operator<<(std::ostream & os, const Stonewt & swt){
	switch (swt.mode){
	case Stonewt::STONE:
		os << swt.stone << " stone, " << swt.pds_left << " pounds" << endl;
		break;
	case Stonewt::POUNDS:
		os << int(swt.pounds + 0.5) << " pounds" << endl;
		break;
	case Stonewt::FP_POUNDS:
		os << swt.pounds << " pounds" << endl;
		break;
	}
	return os;
}