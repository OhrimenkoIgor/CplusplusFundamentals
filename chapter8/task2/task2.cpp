
#include <iostream>
#include <string>

using namespace std;

struct CandyBar{
	string name;
	double weight;
	int calories;
};

void set_candy_bar(CandyBar &bar, char * name = "Millennium Munch, ", double weight = 2.85, int calories = 350){
	bar.name = name;
	bar.weight = weight;
	bar.calories = calories;
}

void show_candy_bar(const CandyBar &bar){
	cout << bar.name << "weight = " << bar.weight << ", calories = " << bar.calories << endl;
}

int main(){
	CandyBar bar;
	set_candy_bar(bar);
	show_candy_bar(bar);
	cin.get();
}