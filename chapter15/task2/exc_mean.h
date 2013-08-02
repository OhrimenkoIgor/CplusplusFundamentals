
// exc_mean.h -- exception classes for hmean(), gmean()
#include <iostream>
#include <stdexcept>

class bad_hmean : public std::logic_error
{
public:
	bad_hmean() : std::logic_error("hmean(): invalid arguments: a = -b"){}
	//virtual const char * what() const {return ; }
};


class bad_gmean : public std::logic_error
{
public:
	bad_gmean() : std::logic_error("gmean() arguments should be >= 0") {}
	//virtual const char * what() const { return ; } 
};

