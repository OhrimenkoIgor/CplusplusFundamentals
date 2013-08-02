
// exc_mean.h -- exception classes for hmean(), gmean()
#include <iostream>

class base_mean : public std::logic_error{
private:
	double v1;
	double v2;
public:
	base_mean(double a = 0, double b = 0, const char * what_msg = "mean") : std::logic_error(what_msg), v1(a), v2(b){}
	virtual void mesg() = 0;
	double get_v1() {return v1;}
	double get_v2() {return v2;}
};

class bad_hmean : public base_mean
{
public:
	bad_hmean(double a = 0, double b = 0, const char * what_msg = "hmean") : base_mean(a, b, what_msg) {}
	virtual void mesg();
};
void bad_hmean::mesg()
{
	std::cout << "hmean(" << get_v1() << ", " << get_v2() <<"): "
		<< "invalid arguments: a = -b\n";
}

class bad_gmean : public base_mean
{
public:
	bad_gmean(double a = 0, double b = 0, const char * what_msg = "gmean") : base_mean(a, b, what_msg) {}
	virtual void mesg();
};
void bad_gmean::mesg()
{
	std::cout << "gmean(" << get_v1() << ", " << get_v2() <<"): arguments should be >= 0\n";
}
