
#include <iostream>

using namespace std;

int Fill_array(double arr[], int size){
	int i = 0;
	while(i < size && cin >> arr[i]){
		i++;
	}
	cin.clear();
	return i;
}

void Show_array(double arr[], int num){
	for(int i = 0; i < num; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

void Reverse_array(double arr[], int num){
	for(int i = 0; i < num/2; i++){
		std::swap(arr[i], arr[num-1-i]);
	}
}

int main(){

	const int arr_size = 10;
	double arr [arr_size] = {0};

	cout << "Fill array:" << endl;
	int num = Fill_array(arr, arr_size);

	cout << "Your array:" << endl;
	Show_array(arr, num);

	cout << "Your reversed array:" << endl;
	Reverse_array(arr, num);
	Show_array(arr, num);

	cout << "Your reversed array (except first and last elements):" << endl;
	Reverse_array(arr + 1, num - 2);
	Show_array(arr, num);

	cin.ignore(cin.rdbuf()->in_avail());
	cin.get();

	return 0;
}