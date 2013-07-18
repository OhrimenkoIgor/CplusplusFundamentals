#include <iostream>

#include "golf.h"

int main(){

	using std::cin;

	golf arr[5];

	setgolf(arr[0], "John", 5);

	int i = 1;
	while(setgolf(arr[i])) i++;

	int num_in_arr = i;
	handicap(arr[num_in_arr-1], 1);

	for(int i = 0; i < num_in_arr; i++){
		showgolf(arr[i]);
	}

	cin.ignore(cin.rdbuf()->in_avail());
	cin.get();
	return 0;
}
