
#ifndef CD_H_
#define CD_H_

// base class
class Cd { // represents a CD disk
private:
	char performers[50];
	char label[20];
	int selections; // number of selections
	double playtime; // playing time in minutes
public:
	Cd(char * s1 = "", char * s2 = "", int n = 0, double x = 0.0);
	//Cd(const Cd & d); //no need
	//Cd(); //no need
	virtual ~Cd(){}
	virtual void Report() const; // reports all CD data
	//Cd & operator=(const Cd & d); //no need
};

#endif
