
#include <iostream>

using namespace std;

typedef double (*f_type)(double, double);

double calculate(double x, double y, f_type f){
	return f(x, y);
}

double add(double x, double y){
	return x + y;
}

double sub(double x, double y){
	return x - y;
}

double mul(double x, double y){
	return x * y;
}


int main (){
	double x, y;
	x = y = 0;

	f_type arr[3] = {add, sub, mul};

	while (cout << "Enter pair: ", cin >> x >> y){
		for(int i = 0; i < 3; i++)
			cout << "Function " << i + 1 << ": " << calculate(x, y, arr[i]) << endl;
	}

	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	cin.get();
}

