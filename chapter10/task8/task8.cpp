/*
You can describe a simple list as follows:
* The simple list can hold zero or more items of some particular type.
* You can create an empty list.
* You can add items to the list.
* You can determine whether the list is empty .
* You can determine whether the list is full.
* You can visit each item in the list and perform some action on it.
As you can see,this list really is simple;it doesn’t allow insertion or deletion,for example.
Design a Listclass to represent this abstract type.You should provide a list.h
header file with the class declaration and a list.cppfile with the class method
implementations.You should also create a short program that utilizes your design.
The main reason for keeping the list specification simple is to simplify this pro-
gramming exercise.You can implement the list as an array or,if you’re familiar with
the data type,as a linked list.But the public interface should not depend on your
choice.That is,the public interface should not have array indices,pointers to nodes,
and so on.It should be expressed in the general concepts of creating a list,adding
an item to the list,and so on.The usual way to handle visiting each item and per-
forming an action is to use a function that takes a function pointer as an argument:
void visit(void (*pf)(Item &));
Here pf points to a function (not a member function) that takes a reference to Item
argument, where Item is the type for items in the list. The visit() function applies
thisfunction toeachitem in thelist.You can use the Stack class as a general guide.
*/

#include <iostream>

#include "list.h"

void add_one(Item & i){
	i++;
}

void mul_by_two(Item & i){
	i *= 2;
}

void show(Item & i){
	std::cout << i << std::endl;
}

int main(){

	using namespace std;

	List list;

	for(int i = 0; !list.is_full(); i++){
		list.add(i);
	}

	if(!list.is_empty()){
		cout << "List: " << endl;
		list.visit_each_item(show);
		cout << endl;

		list.visit_each_item(add_one);
		cout << "Added 1 to each element: " << endl;
		list.visit_each_item(show);
		cout << endl;

		list.visit_each_item(mul_by_two);
		cout << "Mul each element by two: " << endl;
		list.visit_each_item(show);
		cout << endl;

	}

	cin.get();

	return 0;
}