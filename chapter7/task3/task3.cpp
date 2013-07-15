
#include <iostream>

using namespace std;

struct box{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};

void display(box b){
	cout << b.maker << endl;
	cout << b.height << endl;
	cout << b.width << endl;
	cout << b.length << endl;
	cout << b.volume << endl;
}

void set_volume(box * b){
	if (!b) return;
	b->volume = b->length * b->width * b->height;
}

int main(){
	box b = {"Boxes Inc.", 3, 4, 2, 0};
	set_volume(&b);
	display(b);
	cin.get();
	return 0;
}