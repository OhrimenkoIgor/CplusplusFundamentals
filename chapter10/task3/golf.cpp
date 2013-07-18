
#include <iostream>
#include <cstring>

#include "golf.h"

golf::golf(const char * name, int hc){
	if (name){
		strncpy(fullname_, name, Len_);
	} else {
		fullname_[0] = '\0';
	}
	handicap_ = hc;
}

int golf::setgolf(){
	using namespace std;
	golf temp;
	cout << "Enter name: ";
	cin.getline(temp.fullname_, Len_);
	if(!temp.fullname_[0]){
		temp.handicap_ = 0;
		*this = temp;
		return 0;
	}
	cout << "Enter handicap: ";
	while (!(cin >> temp.handicap_)) {
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cout << "Please enter a number: ";
	}
	cin.get();
	*this = temp;
	return 1;
}

void golf::handicap(int hc){
	handicap_ = hc;
}

void golf::showgolf() const {
	std::cout << fullname_ << ", " << handicap_ << std::endl;
}