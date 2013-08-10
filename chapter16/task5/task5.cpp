
#include <algorithm>
#include <iterator>
#include <iostream>
#include <string>

template <class T>
int reduce(T ar[], int n){
	std::sort (ar, ar + n);
	return std::unique(ar, ar + n) - ar;
}

int main(){

	const int SIZE = 7;
	long arrl [SIZE] = {5, 3, 7, 3, 4, 1, 7};

	std::string arrs [SIZE] = { "garage", "health", "florid",  "insult", "danger", "jackal", "health"};

	std::ostream_iterator<long, char> out_iter_l(std::cout, " ");
	std::ostream_iterator<std::string, char> out_iter_s(std::cout, " ");

	copy(arrl, arrl + SIZE, out_iter_l); 
	std::cout << std::endl;

	int nlsize = reduce(arrl, SIZE);
	copy(arrl, arrl + nlsize, out_iter_l); 
	std::cout << std::endl;

	copy(arrs, arrs + SIZE, out_iter_s); 
	std::cout << std::endl;

	int nssize = reduce(arrs, SIZE);
	copy(arrs, arrs + nssize, out_iter_s); 
	std::cout << std::endl;

	std::cin.get();
	return 0;
}
