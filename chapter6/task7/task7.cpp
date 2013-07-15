
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main (){

	cout << "Enter words (q to quit):" << endl;
	
	string word;
	char ch;
	int num_vowels, num_consonants, num_others;
	num_vowels = num_consonants = num_others = 0;
	while(cin >> word && word != "q"){
		ch = word.at(0);
		if(isalpha(ch)){
			switch (ch){
			case 'A' :
			case 'E' :
			case 'I' :
			case 'O' :
			case 'U' :
			case 'Y' :
			case 'a' :
			case 'e' :
			case 'i' :
			case 'o' :
			case 'u' :
			case 'y' :
				num_vowels++;
				break;
			default :
				num_consonants++;
			}
		} else {
			num_others++;
		}
	}

	cout << num_vowels <<" words beginning with vowels" << endl
		<< num_consonants << " words beginning with consonants" << endl
		<< num_others << " others" << endl;

	cin.ignore(cin.rdbuf()->in_avail());
	cin.get();

	return 0;
}
