
#include <iostream>

using namespace std;

template <typename T> T max5(T arr [5]);

template <typename T> void print_in_line_5(T arr [5]);

int main (){

	int iarr [5] = {3, 5, 6, 1, 2};
	double darr [5] = {3.4, 5.1, 6.9, 1.0, 2.7};

	cout << "Int array is: " << endl;
	print_in_line_5(iarr);
	cout << "Double array is: " << endl;
	print_in_line_5(darr);

	cout << "Max int element is: " << max5(iarr) << endl;
	cout << "Max double element is: " << max5(darr) << endl;

	cin.get();

	return 0;
}

template <typename T> T max5(T arr [5]){
	T max = arr[0];
	for(int i = 1; i < 5; i++){
		if (arr[i] > max){
			max = arr[i];
		}
	}
	return max;
}

template <typename T> void print_in_line_5(T arr [5]){
	for(int i = 0; i < 5; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}
