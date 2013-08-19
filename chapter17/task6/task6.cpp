
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // (for exit()

#include "emp.h"

const char * file = "employee.txt";

void read_file_contents(std::ifstream & fin, int & ct, abstr_emp * pc[], int MAX){
	int classtype;
	char ch;
		while(ct < MAX && (fin >> classtype).get(ch)){ // newline separates int from data
			switch(classtype) {
			case Employee:
				pc[ct] = new employee;
				break;
			case Manager:
				pc[ct] = new manager;
				break;
			case Fink:
				pc[ct] = new fink;
				break;
			case Highfink:
				pc[ct] = new highfink;
				break;
			}
			pc[ct++]->GetAll(fin);
		}
}

int main()
{
	using namespace std;

	const int MAX = 10; // no more than 10 objects

	abstr_emp * pc[MAX];

	int ct = 0;

	// show initial contents
	ifstream fin;
	fin.open(file);
	if (fin.is_open())
	{
		cout << "Here are the current contents of the "
			<< file << " file:\n";

		read_file_contents(fin, ct,  pc, MAX);

		for (int i = 0; i < ct; i++){
			pc[i]->ShowAll();
		}

		fin.close();
	}
	// add new names
	ofstream fout(file, ios::out | ios::app);
	if (!fout.is_open())
	{
		cerr << "Can't open " << file << " file for output.\n";
		exit(EXIT_FAILURE);
	}


	for (; ct < MAX; ct++)
	{
		char choice;

		cout << "Enter category:\n"
			<< "e: employee m: manager "
			<< "f: fink h: highfink q: quit\n";
		cin >> choice;
		while (strchr("emfhq", choice) == NULL)
		{
			cout << "Please enter a e, m, f, h or q: ";
			cin >> choice;
		}
		if (choice == 'q')
			break;
		while(cin.get() != '\n'); //new line

		switch(choice)
		{
		case 'e': 
			pc[ct] = new employee();
			break;
		case 'm':
			pc[ct] = new manager();
			break;
		case 'f':
			pc[ct] = new fink();
			break;
		case 'h': 
			pc[ct] = new highfink();
			break;
		}
		pc[ct]->SetAll();

		pc[ct]->WriteAll(fout);// fout ofstream connected to output file
	}

	for (int i = 0; i < ct; i++)
		delete pc[i];

	fout.close();
	// show revised file
	fin.clear(); // not necessary for some compilers
	fin.open(file);
	if (fin.is_open())
	{
		cout << "Here are the new contents of the "
			<< file << " file:\n";

		int nct = 0;
		read_file_contents(fin, nct,  pc, MAX);

		for (int i = 0; i < nct; i++){
			pc[i]->ShowAll();
		}

		fin.close();
	}
	cout << "Done.\n";

	cin.clear();
	while(cin.get() != '\n');
	cin.get();
	return 0;
}

