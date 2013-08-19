
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]){

	ifstream fin;
	ofstream fout;

	if(argc == 3) {
		fin.open(argv[1]);
		fout.open(argv[2]);
	} else {
		fin.open("in.txt");
		fout.open("out.txt");
	}
	if(!fin.is_open() || !fout.is_open()){
		cerr << "Error openning files" << endl;
		cin.get();
		return 1;
	}

	int ch;
	while((ch = fin.get()) != EOF){
		fout.put(ch);
	}

	fin.close();
	fout.close();

	cin.get();
	return 0;
}
