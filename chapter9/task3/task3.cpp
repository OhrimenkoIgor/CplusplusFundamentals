/*
Write a program that uses placement new to place an array of two such structures in
a buffer.Then assign values to the structure members (remembering to use
strcpy()for the chararray) and use a loop to display the contents.Option 1 is to
use a static array,like that in Listing 9.10,for the buffer.Option 2 is to use regular
newto allocate the buffer.
*/

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

	return 0;
}