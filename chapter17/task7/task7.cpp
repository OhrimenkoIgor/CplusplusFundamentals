
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <cassert>

void ShowStr(const std::string & s){
	std::cout << s << std::endl;
}

class Store{
	std::ostream & os;
public:
	Store(std::ostream & out) : os(out){}
	void operator()(const std::string & s){
		size_t len = s.size();
		os.write((char *)&len, sizeof(std::size_t)); // store length
		os.write(s.data(), len); // store characters
	}
};

void GetStrs(std::ifstream & fin, std::vector<std::string> & vistr){
	size_t len = 0;
	while(true){
		fin.read((char*)&len, sizeof(size_t));
		if(fin.gcount() != sizeof(size_t)){
			break;
		}
		std::string s;
		for(size_t i = 0; i < len; i++){
			s.push_back(fin.get());
		}
		vistr.push_back(s);
	}
}

int main()
{
	using namespace std;
	vector<string> vostr;
	string temp;
	// acquire strings
	cout << "Enter strings (empty line to quit):\n";
	while (getline(cin,temp) && /*temp[0] != '\0'*/ temp !="")
		vostr.push_back(temp);
	cout << "Here is your input.\n";
	for_each(vostr.begin(), vostr.end(), ShowStr);
	// store in a file
	ofstream fout("strings.dat", ios_base::out | ios_base::binary);
	for_each(vostr.begin(), vostr.end(), Store(fout));
	fout.close();
	// recover file contents
	vector<string> vistr;
	ifstream fin("strings.dat", ios_base::in | ios_base::binary);
	if (!fin.is_open())
	{
		cerr << "Could not open file for input.\n";

		exit(EXIT_FAILURE);
	}
	GetStrs(fin, vistr);
	cout << "\nHere are the strings read from the file: \n";
	for_each(vistr.begin(), vistr.end(), ShowStr);

	cin.get();
	return 0;
}

