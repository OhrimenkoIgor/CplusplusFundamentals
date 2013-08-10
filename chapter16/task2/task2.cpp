
#include <iostream>
#include <string>
#include <cctype>

bool is_palindrome_simple(const std::string & s){
	std::string::const_iterator it1 = s.begin();
	std::string::const_iterator it2 = s.end();

	while(it1 < it2){
		--it2;
		if(*it1 != *it2)
			return false;
		++it1;
	}
	return true;
}

bool is_palindrome(const std::string & s){
	std::string ss;

	for(std::string::const_iterator it = s.begin(); it != s.end(); it++){
		if(isalpha(*it)){
			ss += tolower(*it);
		}
	}

	return is_palindrome_simple(ss);
}

int main() {
	using namespace std;

	string arr[5] = {"otto" , "adad", "Otto", "Madam,I`m Adam", "madam i madam"};

	for(int i =0; i < 5; i++){
		cout << is_palindrome(arr[i]) << " " << arr[i] << endl;
	}

	cin.get();
	return 0;
}
