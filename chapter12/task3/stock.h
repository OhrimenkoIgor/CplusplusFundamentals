
#ifndef STOCK20_H_
#define STOCK20_H_
//#include <string>
namespace std{
	template<class _Elem,
	class _Traits>
	class basic_ostream;
	typedef basic_ostream<char, char_traits<char> > ostream;
}

class Stock
{
private:
	//std::string company;
	char * company;
	int shares;
	double share_val;
	double total_val;
	void set_tot() { total_val = shares * share_val; }
public:
	Stock(); // default constructor
	Stock(const char * co, long n = 0, double pr = 0.0);
	~Stock(); // do-nothing destructor
	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	const Stock & topval(const Stock & s) const;

	friend std::ostream & operator<<(std::ostream & os, const Stock & s);
};
#endif
