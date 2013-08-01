
#ifndef CLASSES_H_
#define CLASSES_H_

#include <string>

class Person{
private:
	std::string fname;
	std::string lname;
public:
	Person(std::string fname_val = "none", std::string lname_val = "none") : fname(fname_val), lname(lname_val) {}
	virtual void Show() const;
	virtual ~Person(){}
};

class Gunslinger : virtual public Person{
private:
	double draw_time;
	int notches;
public:
	Gunslinger(std::string fname_val = "none", std::string lname_val = "none", double draw_time_val = 0.0, int notches_val = 0)
		: Person(fname_val, lname_val), draw_time(draw_time_val), notches(notches_val) {}
	double Draw() const {return draw_time;} 
	virtual void Show() const;
};

class PokerPlayer : virtual public Person{
public:
	PokerPlayer(std::string fname_val = "none", std::string lname_val = "none") : Person(fname_val, lname_val) {};
	int Draw() const {return rand() % 52 + 1;}
};

class BadDude : public Gunslinger, public PokerPlayer{
public:
	BadDude(std::string fname_val = "none", std::string lname_val = "none", double draw_time_val = 0.0, int notches_val = 0)
		: Person(fname_val, lname_val), Gunslinger(fname_val, lname_val, draw_time_val, notches_val), PokerPlayer(fname_val, lname_val) {}
	double Gdraw() const {return Gunslinger::Draw();}
	int Cdraw() const {return PokerPlayer::Draw();}
	virtual void Show() const;
};

#endif //CLASSES_H_
