
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]){

	ofstream fout;

	if(argc == 2) {
		fout.open(argv[1]);
	} else {
		fout.open("file.txt");
	}
	if(!fout.is_open()){
		cerr << "Error openning file" << endl;
		return 1;
	}

	cout << "Enter chars, EOF to stop:" << endl;
	int ch;
	while((ch = cin.get()) != EOF){
		fout.put(ch);
	}

	fout.close();

	cin.clear();
	while(cin.get() != '\n');
	cin.get();
	return 0;
}
