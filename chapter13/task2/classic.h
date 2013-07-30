
#ifndef CLASSIC_H_
#define CLASSIC_H_

#include "cd.h"

class Classic : public Cd{
private:
	char * primary_work;
public:
	Classic(char * s0 = "", char * s1 = "", char * s2 = "", int n = 0, double x = 0.0);
	Classic(const Classic & d);
	virtual ~Classic();
	virtual void Classic::Report() const;
	Classic & operator=(const Classic & d);
};

#endif //CLASSIC_H_
