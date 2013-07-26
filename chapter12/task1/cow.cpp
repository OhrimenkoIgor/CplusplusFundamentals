
#include <cstring>
#include <iostream>

#include "cow.h"

using namespace std;

Cow::Cow() : weight(0) {
	name[0] = '\0';
	hobby = new char [1]();
}

Cow::Cow(const char * nm, const char * ho, double wt) : weight(wt) {
	strncpy(name, nm, 20);
	int hlen = strlen(ho);
	hobby = new char [hlen + 1];
	strcpy(hobby, ho);
}

Cow::Cow(const Cow & c) : weight(c.weight) {
	strncpy(name, c.name, 20);
	int hlen = strlen(c.hobby);
	hobby = new char [hlen + 1];
	strcpy(hobby, c.hobby);
}

Cow::~Cow(){
	delete [] hobby;
}

Cow & Cow::operator=(const Cow & c){
	if (&c == this) {
		return *this;
	}

	weight = c.weight;
	strncpy(name, c.name, 20);

	int chlen = strlen(c.hobby);
	int hlen = strlen(hobby);
	if(hlen < chlen){
		delete [] hobby;
		hobby = new char [chlen + 1];
	}
	strcpy(hobby, c.hobby);

	return *this;
}

void Cow::ShowCow() const{
	cout << "Cow: " << name << ", hobby: " << hobby << ", weight is: " << weight << endl;
}