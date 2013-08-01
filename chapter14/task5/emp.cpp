
#include "emp.h"

template <typename T> static void enter_number(T & n){
	while (!(std::cin >> n)) {
		std::cin.clear();
		while (std::cin.get() != '\n')
			continue;
		std::cout << "Please enter a number: ";
	}
	while (std::cin.get() != '\n'); //new line
}

using namespace std;

abstr_emp::abstr_emp() {}

abstr_emp::abstr_emp(const std::string & fn, const std::string & ln, const std::string & j) 
	: fname(fn), lname(ln), job(j) {}

void abstr_emp::ShowAll() const{
	cout << "First name: " << fname << endl
		<< "Last name: " << lname << endl
		<< "Job: " << job << endl;
}

void abstr_emp::SetAll(){
	cout << "Enter first name: ";
	cin >> fname;
	cout << "Enter last name: ";
	cin >> lname;
	cout << "Enter job: ";
	cin >> job;
}

std::ostream & operator<<(std::ostream & os, const abstr_emp & e){
	return os << e.fname << " " << e.lname;
}

abstr_emp::~abstr_emp() {} 

employee::employee() {}

employee::employee(const std::string & fn, const std::string & ln, const std::string & j) 
	: abstr_emp(fn, ln, j) {}


manager::manager() : inchargeof(0) {}

manager::manager(const std::string & fn, const std::string & ln, const std::string & j, int ico)
	: abstr_emp(fn, ln, j), inchargeof(ico) {}

manager::manager(const abstr_emp & e, int ico)
	: abstr_emp(e), inchargeof(ico) {}

void manager::ShowAll() const{
	abstr_emp::ShowAll();
	cout << "In charge of: " << inchargeof << endl;
}

void manager::SetAll(){
	abstr_emp::SetAll();
	cout << "Enter in charge of: ";
	enter_number(inchargeof);
}


fink::fink() {}

fink::fink(const std::string & fn, const std::string & ln, const std::string & j, const std::string & rpo) 
	: abstr_emp(fn, ln, j), reportsto(rpo) {}

fink::fink(const abstr_emp & e, const std::string & rpo)
	: abstr_emp(e), reportsto(rpo) {}

void fink::ShowAll() const{
	abstr_emp::ShowAll();
	cout << "Reports to: " << reportsto << endl;
}

void fink::SetAll(){
	abstr_emp::SetAll();
	cout << "Enter reports to: ";
	getline(cin, reportsto);
}


highfink::highfink() {}

highfink::highfink(const std::string & fn, const std::string & ln, const std::string & j, const std::string & rpo, int ico)
	: abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo) {}

highfink::highfink(const abstr_emp & e, const std::string & rpo, int ico)
	: abstr_emp(e), manager(e, ico), fink(e, rpo) {}

highfink::highfink(const fink & f, int ico)
	: abstr_emp(f), fink(f), manager(f, ico) {}

highfink::highfink(const manager & m, const std::string & rpo) 
	: abstr_emp(m), manager(m), fink(m, rpo) {}

void highfink::ShowAll() const{
	abstr_emp::ShowAll();
	cout << "In charge of: " << InChargeOf() << endl;
	cout << "Reports to: " << ReportsTo() << endl;
}

void highfink::SetAll(){
	abstr_emp::SetAll();
	cout << "Enter in charge of: ";
	enter_number(InChargeOf());
	cout << "Enter reports to: ";
	getline(cin, ReportsTo());
}
