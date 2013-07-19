
// randwalk.cpp -- using the Vector class
// compile with the vect.cpp file
#include <iostream>
#include <cstdlib> // rand(), srand() prototypes
#include <ctime> // time() prototype
#include "vect.h"
int main()
{
	using namespace std;
	using VECTOR::Vector;
	srand(time(0)); // seed random-number generator
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps, min_steps, max_steps, steps_sum;
	double avg_steps;
	avg_steps = steps = min_steps = max_steps = steps_sum = 0;
	double target;
	double dstep;
	int N = 0;
	cout << "Enter target distance (q to quit): ";
	while (cin >> target)
	{
		cout << "Enter step length: ";
		if (!(cin >> dstep))
			break;
		cout << "Enter number of trials: ";
		if (!(cin >> N))
			break;
		for(int i = 0; i < N; i++){
			while (result.magval() < target)
			{
				direction = rand() % 360;
				step.reset(dstep, direction, Vector::POL);
				result = result + step;
				steps++;
			}
			//statics conunting
			steps_sum += steps;
			if(i == 0) {
				min_steps = steps;
				max_steps = steps;
			} else {
				if (steps > max_steps)
					max_steps = steps;			
				if (steps < min_steps) 
					min_steps = steps;
			}
			steps = 0;
			result.reset(0.0, 0.0);
		}
		avg_steps = double (steps_sum) / N;

		cout << "After " << N << " trials number of steps:" << endl;
		cout << "highest = " << max_steps << endl;
		cout << "lowest = " << min_steps << endl;
		cout << "average = " << avg_steps << endl;

		avg_steps = steps = min_steps = max_steps = steps_sum = 0;
		cout << "Enter target distance (q to quit): ";
	}
	cout << "Bye!\n";
	cin.clear();
	while (cin.get() != '\n')
		continue;
	return 0;
}
