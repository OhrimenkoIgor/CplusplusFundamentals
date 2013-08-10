
#include <algorithm>
#include <iterator>
#include <iostream>

int reduce(long ar[], int n){
	std::sort (ar, ar + n);
	return std::unique(ar, ar + n) - ar;
}

int main(){

	const int SIZE = 7;
	long arr [SIZE] = {5, 3, 7, 3, 4, 1, 7};

	std::ostream_iterator<long, char> out_iter(std::cout, " ");
	copy(arr, arr + SIZE, out_iter); 
	std::cout << std::endl;

	int nsize = reduce(arr, SIZE);
	copy(arr, arr + nsize, out_iter); 
	std::cout << std::endl;

	std::cin.get();
	return 0;
}
