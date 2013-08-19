
#include <vector>
#include <iterator>
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

int main(){

	ifstream fin1;
	ifstream fin2;
	ofstream fout;

	fin1.open("mat.dat");
	fin2.open("pat.dat");
	fout.open("matnpat.dat");

	if(!fin1.is_open() || !fin2.is_open() || !fout.is_open()){
		cerr << "Error openning files" << endl;
		cin.get();
		return 1;
	}

	istream_iterator<string> eos;
	ostream_iterator<string, char> cout_iter(cout, " ");
	ostream_iterator<string, char> fout_iter(fout, "\n");

	vector<string> mat_friends;
	istream_iterator<string> iit1 (fin1); 
	mat_friends.insert (mat_friends.begin(), iit1, eos);

	sort(mat_friends.begin(), mat_friends.end());

	cout << "Mat`s friends: " << endl;
	copy(mat_friends.begin(), mat_friends.end(), cout_iter); 
	cout << endl;


	vector<string> pat_friends;
	istream_iterator<string> iit2 (fin2);
	pat_friends.insert (pat_friends.begin(), iit2, eos);

	sort(pat_friends.begin(), pat_friends.end());

	cout << "Pat`s friends: " << endl;
	copy(pat_friends.begin(), pat_friends.end(), cout_iter); 
	cout << endl;


	vector<string> friends(mat_friends.size() + pat_friends.size());
	merge(mat_friends.begin(), mat_friends.end(), pat_friends.begin(), pat_friends.end(), friends.begin());

	friends.erase(unique(friends.begin(), friends.end()), friends.end());
	copy(friends.begin(), friends.end(), fout_iter); 
	cout << endl;

	fin1.close();
	fin2.close();
	fout.close();

	cin.get();
	return 0;
}
