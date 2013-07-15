
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

struct Contribution{
	string name;
	double amount;
};

void print_list(Contribution contributions[], int n){
	cout << "List of contributors:" << endl;
	cout << "Grand Patrons" << endl;
	ostringstream grand_patrons;
	for(int i = 0; i< n; i++){
		if(contributions[i].amount >= 10000){
			grand_patrons << contributions[i].name << endl << contributions[i].amount << endl;
		}
	}
	if(grand_patrons.str() != "") cout << grand_patrons.str() ; else cout << "none" << endl;

	cout << "Patrons" << endl;
	ostringstream patrons;
	for(int i = 0; i< n; i++){
		if(contributions[i].amount < 10000){
			patrons << contributions[i].name << endl << contributions[i].amount << endl;
		}
	}
	if (patrons.str() != "") cout << patrons.str(); else cout << "none" << endl;
}

int main (){

	ifstream file("input.txt", ifstream::in);

	int num_contr;
	(file >> num_contr).get();
	Contribution * contributions = new Contribution[num_contr]; 

	for(int i = 0; i< num_contr; i++){		
		getline(file, contributions[i].name);
		(file >> contributions[i].amount).get();
	}

	print_list(contributions, num_contr);

	delete [] contributions;
	file.close();

	cin.get();
	return 0;
}