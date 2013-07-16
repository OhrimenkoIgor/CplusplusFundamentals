/*
This exercise provides practice in writing functions dealing with arrays and struc-
tures.The following is a program skeleton.Complete it by providing the described
functions:
*/

#include <iostream>
using namespace std;
const int SLEN = 30;
struct student {
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};
// getinfo() has two arguments: a pointer to the first element of
// an array of student structures and an int representing the
// number of elements of the array. The function solicits and
// stores data about students. It terminates input upon filling
// the array or upon encountering a blank line for the student
// name. The function returns the actual number of array elements
// filled.
int getinfo(student pa[], int n);
// display1() takes a student structure as an argument
// and displays its contents
void display1(student st);
// display2() takes the addressof student structure as an
// argument and displays the structure’s contents
void display2(const student * ps);
// display3() takes the address of the first element of an array
// of student structures and the number of array elements as
// arguments and displays the contents of the structures
void display3(const student pa[], int n);
int main()
{
	cout << "Enter class size: ";
	int class_size;
	cin >> class_size;
	while (cin.get() != '\n')
		continue;
	student * ptr_stu = new student[class_size];
	int entered = getinfo(ptr_stu, class_size);
	for (int i = 0; i < entered; i++)
	{
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	}
	display3(ptr_stu, entered);
	delete [] ptr_stu;
	cout << "Done\n";

	cin.get();

	return 0;
}


int getinfo(student pa[], int n){
	int i = 0;
	while (i < n && (cout << "Enter name " << i+1 << ": ", cin >> pa[i].fullname) && strcmp (pa[i].fullname, "")){
		cout << "Enter hobby " << i+1 << ": ";
		cin >> pa[i].hobby;
		cout << "Enter ooplevel " << i+1 << ": ";
		(cin >> pa[i].ooplevel).get();
		i++;
	}
	return i;
}

void display1(student st){
	cout << st.fullname << endl
		<< st.hobby << endl
		<< st.ooplevel;
}

void display2(const student * ps){
	if (ps)
		cout << ps->fullname << endl
		<< ps->hobby << endl
		<< ps->ooplevel;
}

void display3(const student pa[], int n){
	const student * end = pa + n;
	for(; pa < end; pa++)
		display2(pa);
}