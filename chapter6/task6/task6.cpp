
#include <iostream>
#include <string>
#include <sstream>

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

	int num_contr;
	cout << "Enter the number of contributors: ";
	(cin >> num_contr).get();

	Contribution * contributions = new Contribution[num_contr]; 

	for(int i = 0; i< num_contr; i++){
		cout << "Enter name of contributor " << i+1 << ": ";
		getline(cin, contributions[i].name);
		cout << "Enter contribution of contributor " << i+1 << ": ";
		(cin >> contributions[i].amount).get();
	}

	print_list(contributions, num_contr);

	delete [] contributions;

	cin.ignore(cin.rdbuf()->in_avail());
	cin.get();

	return 0;
}
