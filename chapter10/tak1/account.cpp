
#include <iostream>

#include "account.h"

account::account(std::string name, std::string number, double balance):name_(name),number_(number),balance_(balance){
}

void account::display() const{
	using std::cout;
	using std::endl;
	cout << "Name: " << name_ << endl
		<< "Number: " << number_ << endl
		<< "Balance: " << balance_ << endl;
}

void account::deposit(double d){
	balance_ += d;
}

void account::withdraw(double w){
	balance_ -= w;
}