
#include <iostream>

#include "golf.h"

int main(){

	using std::cin;

	golf arr[5] = {golf("John", 5)};

	int i = 1;
	while(arr[i].setgolf()) i++;

	int num_in_arr = i;
	arr[num_in_arr-1].handicap(1);

	for(int i = 0; i < num_in_arr; i++){
		arr[i].showgolf();
	}

	cin.ignore(cin.rdbuf()->in_avail());
	cin.get();
	return 0;
}