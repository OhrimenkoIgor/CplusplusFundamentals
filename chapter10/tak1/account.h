
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class account {
private:
	std::string name_;
	std::string number_;
	double balance_;
public:
	account(std::string name = "", std::string number = "", double balance = 0);
	void display() const;
	void deposit(double);
	void withdraw(double);
};

#endif //ACCOUNT_H