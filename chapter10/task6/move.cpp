
#include <iostream>

#include "move.h"

Move::Move(double a, double b): x(a), y(b) {
}

void Move::showmove() const{
	std::cout << "x = " << x << ", y = " << y;
}

Move Move::add(const Move & m) const{
	return Move(x + m.x, y + m.y);
}

void Move::reset(double a, double b){
	x = a;
	y = b;
}
