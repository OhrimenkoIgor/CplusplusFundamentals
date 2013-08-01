
#ifndef QUEUE_H_
#define QUEUE_H_

template <typename Item>
class QueueTp
{
private:
	// class scope definitions
	// Node is a nested structure definition local to this class
	struct Node { Item item; struct Node * next;};
	enum {Q_SIZE = 10};
	// private class members
	Node * front; // pointer to front of Queue
	Node * rear; // pointer to rear of Queue
	int items; // current number of items in Queue
	const int qsize; // maximum number of items in Queue
	// preemptive definitions to prevent public copying
	QueueTp(const QueueTp & q) : qsize(0) { }
	QueueTp & operator=(const QueueTp & q) { return *this;}
public:
	QueueTp(int qs = Q_SIZE); // create queue with a qs limit
	~QueueTp();
	bool isempty() const;
	bool isfull() const;
	int queuecount() const;
	bool enqueue(const Item &item); // add item to end
	bool dequeue(Item &item); // remove item from front
};

template <typename Item>
QueueTp<Item>::QueueTp(int qs) : qsize(qs)
{
	front = rear = NULL; // or nullptr
	items = 0;
}

template <typename Item>
QueueTp<Item>::~QueueTp()
{
	Node * temp;
	while (front != NULL) // while queue is not yet empty
	{
		temp = front; // save address of front item
		front = front->next;// reset pointer to next item
		delete temp; // delete former front
	}
}

template <typename Item>
bool QueueTp<Item>::isempty() const
{
	return items == 0;
}

template <typename Item>
bool QueueTp<Item>::isfull() const
{
	return items == qsize;
}

template <typename Item>
int QueueTp<Item>::queuecount() const
{
	return items;
}

template <typename Item>
bool QueueTp<Item>::enqueue(const Item & item)
{
	if (isfull())
		return false;
	Node * add = new Node; // create node
	// on failure, new throws std::bad_alloc exception
	add->item = item; // set node pointers
	add->next = NULL; // or nullptr;
	items++;
	if (front == NULL) // if queue is empty,
		front = add; // place item at front
	else
		rear->next = add; // else place at rear
	rear = add; // have rear point to new node
	return true;
}

template <typename Item>
bool QueueTp<Item>::dequeue(Item & item)
{
	if (front == NULL)
		return false;
	item = front->item; // set item to first item in queue
	items--;
	Node * temp = front; // save location of first item
	front = front->next; // reset front to next item
	delete temp; // delete former first item
	if (items == 0)
		rear = NULL;
	return true;
}

#endif
