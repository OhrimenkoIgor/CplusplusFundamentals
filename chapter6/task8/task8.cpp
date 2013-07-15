
#include <iostream>
#include <fstream>

using namespace std;

int main(){

	ifstream file("file.txt", ifstream::in);

	int n = 0;
	while (file.get() != EOF) n++;

	file.close();

	cout << "Number of characters in the file is: " << n;
	cin.get();

	return 0;
}
