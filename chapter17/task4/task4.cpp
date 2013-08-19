
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){

	ifstream fin1;
	ifstream fin2;
	ofstream fout;

	fin1.open("in1.txt");
	fin2.open("in2.txt");
	fout.open("out.txt");

	if(!fin1.is_open() || !fin2.is_open() || !fout.is_open()){
		cerr << "Error openning files" << endl;
		cin.get();
		return 1;
	}

	string line1, line2;
	while(static_cast<bool>(getline(fin1, line1)) | static_cast<bool>(getline(fin2, line2))){
		if(fin1){
			fout << line1;
		}
		if (fin1 && fin2){
			fout << " ";
		}
		if (fin2) {
			fout << line2;
		}
		fout << endl;
	}

	fin1.close();
	fin2.close();
	fout.close();

	cin.get();
	return 0;
}

