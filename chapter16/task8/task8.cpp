
#include <vector>
#include <iterator>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){

	istream_iterator<string> eos;
	ostream_iterator<string, char> out_iter(cout, " ");

	vector<string> mat_friends;
	cout << "Enter Mat`s friends (Cntl-Z to stop): " << endl;
	istream_iterator<string> iit1 (cin); 
	mat_friends.insert (mat_friends.begin(), iit1, eos);
	cin.clear();

	sort(mat_friends.begin(), mat_friends.end());

	cout << "Mat`s friends: " << endl;
	copy(mat_friends.begin(), mat_friends.end(), out_iter); 
	cout << endl;

	vector<string> pat_friends;
	cout << "Enter Pat`s friends (Cntl-Z to stop): " << endl;;
	istream_iterator<string> iit2 (cin);
	pat_friends.insert (pat_friends.begin(), iit2, eos);
	cin.clear();

	sort(pat_friends.begin(), pat_friends.end());

	cout << "Pat`s friends: " << endl;
	copy(pat_friends.begin(), pat_friends.end(), out_iter); 
	cout << endl;

	vector<string> friends(mat_friends.size() + pat_friends.size());
	merge(mat_friends.begin(), mat_friends.end(), pat_friends.begin(), pat_friends.end(), friends.begin());

	cout << endl << "All friends: " << endl;
	friends.erase(unique(friends.begin(), friends.end()), friends.end());
	copy(friends.begin(), friends.end(), out_iter); 
	cout << endl;
	
	cin.get();
	return 0;
}
