#include <iostream>

#include "cpmv.h"

using std::cout;
using std::endl;

Cpmv::Cpmv() {
	cout << (void *) this << " Cpmv()" << endl;
	pi = new Info;
}

Cpmv::Cpmv(std::string q, std::string z) {
	cout << (void *) this << " Cpmv(std::string q, std::string z)" << endl;
	pi = new Info { q, z };
}

Cpmv::Cpmv(const Cpmv & cp) {
	cout << (void *) this << " Cpmv(const Cpmv & cp)" << endl;
	pi = new Info { cp.pi->qcode, cp.pi->zcode };
}

Cpmv::Cpmv(Cpmv && mv) {
	cout << (void *) this << " Cpmv(Cpmv && mv)" << endl;
	pi = mv.pi;
	mv.pi = nullptr;
}

Cpmv::~Cpmv() {
	cout << (void *) this << " ~Cpmv()" << endl;
	delete pi;
}

Cpmv & Cpmv::operator=(const Cpmv & cp) {
	cout << (void *) this << " operator=(const Cpmv & cp)" << endl;
	if (&cp != this) {
		delete pi;
		pi = new Info { cp.pi->qcode, cp.pi->zcode };
	}
	return *this;
}

Cpmv & Cpmv::operator=(Cpmv && mv) {
	cout << (void *) this << " operator=(Cpmv && mv)" << endl;
	if(&mv != this) {
		delete pi;
		pi = mv.pi;
		mv.pi = nullptr;
	}
	return *this;
}

Cpmv Cpmv::operator+(const Cpmv & obj) const {
	cout << (void *) this << " operator+(const Cpmv & obj)" << endl;
	return Cpmv { pi->qcode + obj.pi->qcode, pi->zcode + obj.pi->zcode };
}

void Cpmv::Display() const {
	cout << (void *) this << " Display()" << endl;
	cout << pi->qcode << endl << pi->zcode << endl;
}
