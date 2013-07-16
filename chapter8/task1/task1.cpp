
#include <iostream>

using namespace std;

void print(const char * str, int flag = 0);

int main(){

	print("First call, no flag");
	print("Second call, flag = 1", 1);
	print("Third call, flag = 0", 0);
	print("Forth call, flag = 1", 1);
	print("Fifth call, no flag");

	cin.get();
	return 0;
}

void print(const char * str, int flag){
	static int calls = 1;
	int n = flag ? calls : 1;
	for(int i = 0; i < n; i++){
		cout << str << endl;
	}
	calls++;
}