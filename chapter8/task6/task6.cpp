
#include <iostream>
#include <cstring>

using namespace std;

template <typename T>
T maxn(T arr[], int n){
	T max = arr[0];
	for(int i = 1; i < n; i++){
		if (arr[i] > max){
			max = arr[i];
		}
	}
	return max;
}

template <> char * maxn(char * arr[], int n){
	char * max = arr[0];
	unsigned int max_len = strlen(arr[0]);
	unsigned int len;
	for(int i = 1; i < n; i++){
		len = strlen(arr[i]);
		if (len > max_len){
			max = arr[i];
			max_len = len;
		}
	}
	return max;
}

template <typename T> void printn(T arr[], int n);
template <> void printn(char * arr[], int n);

int main (){

	int  iarr[6] = {1, 7, 2, 6, 2, 5};
	double darr[4] = {5.1, 6.7, 4.2, 6.5};
	char * carr[5] = {
		"First string",
		"Second string",
		"Third string",
		"Fourth string",
		"Fifth string"
	};


	cout << "Int arr: " << endl;
	printn(iarr, 6);
	cout << "Max int: " << maxn(iarr, 6) << endl;
	cout << endl;

	cout << "Double arr: " << endl;
	printn(darr, 4);
	cout << "Max double: " << maxn(darr, 4) << endl;
	cout << endl;

	cout << "char * arr: " << endl;
	printn(carr, 5);
	cout << "Max string: " << maxn(carr, 5) << endl;
	cout << endl;

	cin.get();

	return 0;
}

template <typename T> void printn(T arr[], int n){
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

template <> void printn(char * arr[], int n){
	for(int i = 0; i < n; i++){
		cout << arr[i] << endl;
	}
}