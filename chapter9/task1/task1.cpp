#include <iostream>

#include "golf.h"
/*
.For example,a loop should solicit input for an array of golf
structures and terminate when the array is full or the user enters an empty string
for the golfer’s name.The main()function should use only the prototyped func-
tions to access the golf structures.
*/

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
