
#include <iostream>
#include <cstring>

struct chaff
{
	char dross[20];
	int slag;
};

char buffer1[512];

int main(){

	using namespace std;

	char * buffer2 = new char [512];

	chaff * arr1 = new (buffer1) chaff[2];
	chaff * arr2 = new (buffer2) chaff[2];

	strcpy(arr1[0].dross, "Arr1 One");
	arr1[0].slag = 1;
	strcpy(arr1[1].dross, "Arr1 Two");
	arr1[1].slag = 2;

	strcpy(arr2[0].dross, "Arr2 One");
	arr2[0].slag = 1;
	strcpy(arr2[1].dross, "Arr2 Two");
	arr2[1].slag = 2;

	cout << "Array in static buffer:" << endl;
	for(int i = 0; i < 2; i++){
		cout << arr1[i].dross << " " << arr1[i].slag << endl;
	}

	cout << "Array in dynamic buffer:" << endl;
	for(int i = 0; i < 2; i++){
		cout << arr2[i].dross << " " << arr2[i].slag << endl;
	}

	cin.get();

	return 0;
}