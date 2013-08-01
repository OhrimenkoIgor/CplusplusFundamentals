
#ifndef WINEC_H_
#define WINEC_H_

#include <string>
#include <valarray>

#include "pair.h"

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine : private std::string, private PairArray {
public:

	// initialize label to l, number of years to y,
	// vintage years to yr[], bottles to bot[]
	Wine(const char * l, int y, const int yr[], const int bot[]);
	// initialize label to l, number of years to y,
	// create array objects of length y
	Wine(const char * l, int y);

	void GetBottles();
	const std::string & Label() const {return (const std::string &)(*this);}
	int sum() const {return second().sum();}
	void Show() const;
};

#endif //WINEC_H_
