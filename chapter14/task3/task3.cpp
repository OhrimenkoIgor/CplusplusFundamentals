
// workmi.cpp -- multiple inheritance
// compile with workermi.cpp
#include <iostream>
#include <cstring>
#include "workermi.h"
#include "queuetp.h"

const int SIZE = 5;
int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::strchr;
	QueueTp<Worker *> queue(SIZE);
	Worker * pworker;
	while (!queue.isfull())
	{
		char choice;
		cout << "Enter the employee category:\n"
			<< "w: waiter s: singer "
			<< "t: singing waiter q: quit\n";
		cin >> choice;
		while (strchr("wstq", choice) == NULL)
		{
			cout << "Please enter a w, s, t, or q: ";
			cin >> choice;
		}
		if (choice == 'q')
			break;
		switch(choice)
		{
		case 'w': pworker = new Waiter;
			break;
		case 's': pworker = new Singer;
			break;
		case 't': pworker = new SingingWaiter;
			break;
		}
		cin.get();
		pworker->Set();
		queue.enqueue(pworker);
	}
	cout << "\nHere is your staff:\n";
	while(!queue.isempty())
	{
		cout << endl;
		queue.dequeue(pworker);
		pworker->Show();
		delete pworker;
	}
	cout << "Bye.\n";

	while(cin.get() != '\n');
	cin.get();
	return 0;
}
