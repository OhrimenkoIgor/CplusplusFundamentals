
#include <cstring>
#include "stack.h"

Stack::Stack(int n){
	pitems = new Item[n];
	size = n;
	top = 0;
}

Stack::Stack(const Stack & st){
	pitems = new Item[st.size];
	size = st.size;
	top = st.top;
	memcpy(pitems, st.pitems, sizeof(Item) * top);
}

Stack::~Stack(){
	delete [] pitems;
}

bool Stack::isempty() const{
	return top == 0;
}

bool Stack::isfull() const{
	return top == size;
}

bool Stack::push(const Item & item){
	if (top == size){
		return false;
	}
	pitems[top] = item;
	top++;
	return true;
}

bool Stack::pop(Item& item){
	if (top == 0){
		return false;
	}
	top--;
	item = pitems[top];
	return true;
}

Stack & Stack::operator=(const Stack & st){
	if (&st == this){
		return *this;
	}
	delete [] pitems;
	pitems = new Item[st.size];
	size = st.size;
	top = st.top;
	memcpy(pitems, st.pitems, sizeof(Item) * top);
	return *this;
}
