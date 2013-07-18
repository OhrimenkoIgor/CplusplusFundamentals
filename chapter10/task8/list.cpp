
#include "list.h"

List::List(){
	top = 0;
}

bool List::add(const Item & item){
	if (top >= SIZE)	
		return false;
	arr[top++] = item;
	return true;
}

bool List::is_empty() const{
	return top == 0;
}

bool List::is_full() const{
	return top == SIZE;
}

void List::visit_each_item(visit_function_t f){
	for(int i = 0; i < top; i++){
		f(arr[i]);
	}
}
