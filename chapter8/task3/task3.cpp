
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void to_upper(string & str){
	int len = str.length();
	for(int i = 0; i < len; i++){
		str[i] = toupper(str[i]);
	}
}

int main(){
	string s;
	cout << "Enter a string (q to quit): ";
	while (getline(cin,s) && s != "q"){
		to_upper(s);
		cout << s << endl;
		cout << "Next string (q to quit): ";
	}
	cout << "Bye.";
	cin.get();
}