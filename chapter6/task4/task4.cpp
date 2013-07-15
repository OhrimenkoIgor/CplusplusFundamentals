#include <iostream>

using namespace std;

const int strsize = 40;

struct bop {
	char fullname[strsize]; // real name
	char title[strsize]; // job title
	char bopname[strsize]; // secret BOP name
	int preference; // 0 = fullname, 1 = title, 2 = bopname
};

void list_by_fullname(bop arr[], int n){
	for(int i = 0; i < n; i++){
		cout << arr[i].fullname << endl;
	}
}

void list_by_title(bop arr[], int n){
	for(int i = 0; i < n; i++){
		cout << arr[i].title << endl;
	}
}

void list_by_bopname(bop arr[], int n){
	for(int i = 0; i < n; i++){
		cout << arr[i].bopname << endl;
	}
}

void list_by_preference(bop arr[], int n){
	for(int i = 0; i < n; i++){
		switch (arr[i].preference){
		case 0: cout << arr[i].fullname << endl;
			break;
		case 1: cout << arr[i].title << endl;
			break;
		case 2: cout << arr[i].bopname << endl;
			break;
		default: cout << arr[i].fullname << endl;
		}
	}
}

int main(){

	const int arr_size = 5;
	bop arr[5] = {
		{"Wimp Macho", "Middle Programmer", "WIMAC", 0},
		{"Raki Rhodes", "Junior Programmer", "RHOD", 1}, 
		{"Celia Laiter", "Trainee", "MIPS", 2}, 
		{"Hoppy Hipman", "Analyst Trainee", "HIPHOP", 1}, 
		{"Pat Hand", "Junior Programmer", "LOOPY", 2}
	};

	cout << "Benevolent Order of Programmers Report" << endl;
	cout << "a. display by name    b. display by title" << endl
		<< "c. display by bopname d. display by preference" << endl
		<< "q. quit" << endl;

	cout << "Enter your choice: ";
	char choice;
	while (cin >> choice){
		switch(choice){
		case 'a' : list_by_fullname(arr, arr_size);
			break;
		case 'b' : list_by_title(arr, arr_size);
			break;
		case 'c' : list_by_bopname(arr, arr_size);
			break;
		case 'd' : list_by_preference(arr, arr_size);
			break;
		case 'q' : cout << "Bye!" << endl;
			goto end;
		}
		cout << "Next choice: ";
	}

end:
	cin.ignore(cin.rdbuf()->in_avail());
	cin.get();

	return 0;
}

