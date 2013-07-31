
#include "vintageport.h"

VintagePort::VintagePort() : year(0), Port("none", "vintage") {
	nickname = new char[1];
	nickname[0] = '\0';
}

VintagePort::VintagePort(const char * br, int b, const char * nn, int y) : Port(br, "vintage", b), year(y) {
	if(nn){
		nickname = new char[strlen(nn) + 1];
		strcpy(nickname, nn);
	} else {
		nickname = new char[1];
		nickname[0] = '\0';
	}
}

VintagePort::VintagePort(const VintagePort & vp) : Port(vp), year(vp.year) {
	nickname = new char[strlen(vp.nickname) + 1];
	strcpy(nickname, vp.nickname);
}

VintagePort & VintagePort::operator=(const VintagePort & vp){
	if(this != &vp){
		Port::operator=(vp);

		delete [] nickname;
		nickname = new char[strlen(vp.nickname) + 1];
		strcpy(nickname, vp.nickname);

		year = vp.year;
	}

	return *this;
}

void VintagePort::Show() const{
	Port::Show();
	cout << "Nickname: " << nickname << endl
		<< "Year: " << year << endl;
}

ostream & operator<<(ostream & os, const VintagePort & vp){
	os << dynamic_cast<const Port &>(vp);
	os << vp.nickname << ", " << vp.year;
	return os;
}
