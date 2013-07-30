
#ifndef CLASSIC_H_
#define CLASSIC_H_

#include "cd.h"

class Classic : public Cd{
private:
	char primary_work [50];
public:
	Classic(char * s0 = "", char * s1 = "", char * s2 = "", int n = 0, double x = 0.0);
	virtual void Classic::Report() const;
	virtual ~Classic(){}
};

#endif //CLASSIC_H_
