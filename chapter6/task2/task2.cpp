#include <iostream>
#include <cctype>
using namespace std;

int main()
{
	const int arr_size = 10;
	double arr[arr_size] = { 0 };

	cout << "Enter up to 10 donation values:" << endl;

	int i = 0;
	double sum = 0;
	while(i < arr_size && cin >> arr[i]){
		sum += arr[i];
		i++;
	}
	cin.clear();

	int num_in_arr = i;
	double average = sum / num_in_arr;
	int num_larger = 0;
	for(int j = 0; j < num_in_arr; j++){
		if(arr[j] > average) num_larger++;
	}

	cout << "The average of the numbers is: " << average << endl;
	cout << "Numbers in the array are larger than the average: " << num_larger << endl;

	cin.ignore(cin.rdbuf()->in_avail());
	cin.get();

	return 0;
}