
#include <iostream>
const int Max = 5;
// function prototypes
double * fill_array(double * begin, double * end);
void show_array(const double * begin, const double * end); // don't change data
void revalue(double r, double * begin, double * end);
int main()
{
	using namespace std;
	double properties[Max];
	double * properties_end = fill_array(properties, properties + Max);
	show_array(properties, properties_end);
	if (properties_end > properties)
	{
		cout << "Enter revaluation factor: ";
		double factor;
		while (!(cin >> factor)) // bad input
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input; Please enter a number: ";
		}
		revalue(factor, properties, properties_end);
		show_array(properties, properties_end);
	}
	cout << "Done.\n";
	cin.get();
	cin.get();
	return 0;
}

double * fill_array(double * begin, double * end)
{
	using namespace std;
	double temp;
	int i;
	double * p;
	for (p = begin, i = 1; p < end; p++, i++)
	{
		cout << "Enter value #" << i << ": ";
		cin >> temp;
		if (!cin) // bad input
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input; input process terminated.\n";
			break;
		}
		else if (temp < 0) // signal to terminate
			break;
		*p = temp;
	}
	return p;
}
// the following function can use, but not alter,
// the array whose address is ar
void show_array(const double * begin, const double * end)
{
	using namespace std;
	int i = 1;
	for (const double * p = begin; p < end; p++, i++)
	{
		cout << "Property #" << i << ": $";
		cout << *p << endl;
	}
}
// multiplies each element of ar[] by r
void revalue(double r, double * begin, double * end)
{
	for (double * p = begin; p < end; p++)
		*p *= r;
}