
#ifndef LIST_H_
#define LIST_H_

typedef int Item;

class List{	
	typedef void (*visit_function_t)(Item &);
private:
	static const int SIZE = 5;
	Item arr[SIZE];
	int top;
public:
	List();
	bool add(const Item & item);
	bool is_empty() const;
	bool is_full() const;
	void visit_each_item(visit_function_t f);
};

#endif //LIST_H_
