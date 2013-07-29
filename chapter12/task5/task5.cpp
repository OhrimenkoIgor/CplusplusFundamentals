
// bank.cpp -- using the Queue interface
// compile with queue.cpp
#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
#include "queue.h"
const int MIN_PER_HR = 60;
const int SIMULATION_HOURS = 100;
const double TIME_LIMIT = 1.0;
const double TIME_STEP = 0.05;

using std::cin;
using std::cout;
using std::endl;
using std::ios_base;

bool newcustomer(double x); // is there a new customer?

double simulate_wait_time(int queue_size, int simulation_hours, double customers_per_hour);

int main()
{
	// setting things up
	std::srand(std::time(0)); // random initializing of rand()
	cout << "Case Study: Bank of Heather Automatic Teller\n";
	cout << "Enter maximum size of queue: ";
	int qs;
	(cin >> qs).get();
	
	double customers_per_hour = 0;
	for (double i = 0; ; i +=TIME_STEP){
		if(simulate_wait_time(qs, SIMULATION_HOURS, i) > TIME_LIMIT){
			break;
		}
		customers_per_hour = i;
	}
	cout << customers_per_hour << " customers per hour leads to an average wait time of " << TIME_LIMIT << " minute" << endl;

	cin.get();
	return 0;
}
// x = average time, in minutes, between customers
// return value is true if customer shows up this minute
bool newcustomer(double x)
{
	return (std::rand() * x / RAND_MAX < 1);
}

double simulate_wait_time(int qs, int hours, double perhour){
	
	Queue line(qs); // line queue holds up to qs people
	// simulation will run 1 cycle per minute
	long cyclelimit = MIN_PER_HR * hours; // # of cycles
	double min_per_cust; // average time between arrivals
	min_per_cust = MIN_PER_HR / perhour;
	Item temp; // new customer data
	long turnaways = 0; // turned away by full queue
	long customers = 0; // joined the queue
	long served = 0; // served during the simulation
	long sum_line = 0; // cumulative line length
	int wait_time = 0; // time until autoteller is free
	long line_wait = 0; // cumulative time in line
	// running the simulation
	for (int cycle = 0; cycle < cyclelimit; cycle++)
	{
		if (newcustomer(min_per_cust)) // have newcomer
		{
			if (line.isfull())
				turnaways++;
			else
			{
				customers++;
				temp.set(cycle); // cycle = time of arrival
				line.enqueue(temp); // add newcomer to line
			}
		}
		if (wait_time <= 0 && !line.isempty())
		{
			line.dequeue (temp); // attend next customer
			wait_time = temp.ptime(); // for wait_time minutes
			line_wait += cycle - temp.when();
			served++;
		}
		if (wait_time > 0)
			wait_time--;
		sum_line += line.queuecount();
	}

	return (double) line_wait / served;

}
