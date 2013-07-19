
#include <iostream>

#include "stonewt.h"

using namespace std;

int main(){

	Stonewt arr[6] = {45.6, 3.2, 10.5};
	Stonewt eleven_stones(11,0);
	double weight = 0;

	for(int i = 3; i < 6; i++){
		cout << "Enter weight in pounds #" << i + 1 <<" : ";
		while (!(cin >> weight)) {
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Please enter a number: ";
		}
		arr[i] = weight;
	}

	Stonewt min, max;
	min = max = arr[0];
	int num_larger_11 = 0;
	for(int i = 0; i < 6; i++){
		if (arr[i] > max) max = arr[i];
		if (arr[i] < min) min = arr[i];
		if (arr[i] >= eleven_stones) num_larger_11++;
	}

	cout << "Max wt = ";
	max.show_stn();
	cout << "Min wt = ";
	min.show_stn();
	cout << "Larger 11 stone " << num_larger_11 << " elements";

	cin.clear();
	while (cin.get() != '\n');
	cin.get();
	return 0;
}
