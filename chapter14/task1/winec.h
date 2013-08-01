
#ifndef WINEC_H_
#define WINEC_H_

#include <string>
#include <valarray>

#include "pair.h"

class Wine{
public:
	typedef std::valarray<int> ArrayInt;
	typedef Pair<ArrayInt, ArrayInt> PairArray;

	// initialize label to l, number of years to y,
	// vintage years to yr[], bottles to bot[]
	Wine(const char * l, int y, const int yr[], const int bot[]);
	// initialize label to l, number of years to y,
	// create array objects of length y
	Wine(const char * l, int y);

	void GetBottles();
	const std::string & Label() const {return name;}
	int sum() const {return years_bottles.second().sum();}
	void Show() const;

private:
	std::string name;
	PairArray years_bottles;
};

#endif //WINEC_H_
