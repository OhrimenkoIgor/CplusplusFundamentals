// golf.h -- for pe9-1.cpp

class golf{
private:
	static const int Len_ = 40;
	char fullname_[Len_];
	int handicap_;
public:
	// non-interactive version:
	// function sets golf structure to provided name, handicap
	// using values passed as arguments to the function
	golf(const char * name = "", int hc = 0);
	// interactive version:
	// function solicits name and handicap from user
	// and sets the members of g to the values entered
	// returns 1 if name is entered, 0 if name is empty string
	int setgolf();
	// function resets handicap to new value
	void handicap(int hc);
	// function displays contents of golf structure
	void showgolf() const;
};
