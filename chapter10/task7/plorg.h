#ifndef PLORG_H_
#define PLORG_H_

class Plorg {
private:
	static const int m_LEN = 20;
	char m_name[m_LEN];
	int m_ci;
public:
	Plorg(char name[] = "Plorga", int ci = 50);
	void set_ci(int ci){ m_ci = ci; }
	const char * get_name() const {	return m_name; }
	int get_ci() const { return m_ci; }
};

#endif //PLORG_H_