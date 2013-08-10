
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

vector<int> Lotto(int num_spots, int num_rand){

	vector<int> v;
	v.reserve(num_spots);
	for (int i = 1; i < num_spots; ++i){
		v.push_back(i);
	}
	std::random_shuffle(v.begin(), v.end());
	v.resize(num_rand);
	sort(v.begin(), v.end());
	return v;
}

int main(){
	vector<int> winners1 = Lotto(51,6);

	vector<int> winners2 = Lotto(51,6);

	ostream_iterator<int, char> out_iter(cout, " ");

	cout << "Firest lotto winners: " << endl;
	copy(winners1.begin(), winners1.end(), out_iter); 
	cout << endl;

	cout << "Second lotto winners: " << endl;
	copy(winners2.begin(), winners2.end(), out_iter); 
	cout << endl;

	cin.get();
	return 0;
}
