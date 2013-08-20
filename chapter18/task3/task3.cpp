
#include <iostream>

// definition for 0 parameters
long double sum_values() {
	return 0;
}

// definition for 1 or more parameters
template<typename T, typename ... Args>
long double sum_values(const T& value, const Args&... args) {
	return value + sum_values(args...);
}

int main() {
	using namespace std;

	cout << sum_values() << endl;
	cout << sum_values(5.6) << endl;
	cout << sum_values(5, 1.3) << endl;
	cout << sum_values(5, 1.3, 4.5) << endl;
	cout << sum_values(5, 1.3, 4.5, 5, 40, 2, 5) << endl;

	return 0;
}
