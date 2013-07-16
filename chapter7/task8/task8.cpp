/*
Redo Listing 7.15without using the arrayclass.Do two versions:
a. Use an ordinary array of const char *for the strings representing the sea-
son names,and use an ordinary array of doublefor the expenses.
b. Use an ordinary array of const char *for the strings representing the sea-
son names,and use a structure whose sole member is an ordinary array of
doublefor the expenses.(This design is similar to the basic design of the
arrayclass.)
*/

#include <iostream>
#include <string>
// constant data
const int Seasons = 4;
const char * Snames [Seasons] =
{"Spring", "Summer", "Fall", "Winter"};
// function to modify array object
void fill_A(double pa []);
// function that uses array object without modifying it
void show_A(const double da []);

struct Expenses_B {
	double expenses [Seasons];
};
// function to modify array object
void fill_B(Expenses_B * pa);
// function that uses array object without modifying it
void show_B(Expenses_B da);

int main()
{
	std::cout << "Part A:" << std::endl;
	double expenses_A [Seasons];
	fill_A(expenses_A);
	show_A(expenses_A);

	std::cout << std::endl << std::endl << "Part B:" << std::endl;
	Expenses_B expenses_B;
	fill_B(&expenses_B);
	show_B(expenses_B);

	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::cin.get();

	return 0;
}
void fill_A(double pa [])
{
	using namespace std;
	for (int i = 0; i < Seasons; i++)
	{
		cout << "Enter " << Snames[i] << " expenses: ";
		cin >> pa[i];
	}
}
void show_A(const double da [])
{
	using namespace std;
	double total = 0.0;
	cout << "\nEXPENSES\n";
	for (int i = 0; i < Seasons; i++)
	{
		cout << Snames[i] << ": $" << da[i] << endl;
		total += da[i];
	}
	cout << "Total Expenses: $" << total << endl;
}

void fill_B(Expenses_B * pa)
{
	using namespace std;
	for (int i = 0; i < Seasons; i++)
	{
		cout << "Enter " << Snames[i] << " expenses: ";
		cin >> pa->expenses[i];
	}
}
void show_B(Expenses_B da)
{
	using namespace std;
	double total = 0.0;
	cout << "\nEXPENSES\n";
	for (int i = 0; i < Seasons; i++)
	{
		cout << Snames[i] << ": $" << da.expenses[i] << endl;
		total += da.expenses[i];
	}
	cout << "Total Expenses: $" << total << endl;
}