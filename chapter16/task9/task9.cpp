
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <ctime>

using namespace std;

void test(int size){
	clock_t start, end;

	vector<int> vi0(size);
	generate(vi0.begin(), vi0.end(), rand);

	vector<int> vi(vi0.begin(), vi0.end());
	list<int> li(vi0.begin(), vi0.end());

	cout << "size: " << size << endl;

	start = clock();
	sort(vi.begin(), vi.end());
	end = clock();
	cout << "vi: " << (double)(end - start)/CLOCKS_PER_SEC << endl;

	start = clock();
	li.sort();
	end = clock();
	cout << "li: " << (double)(end - start)/CLOCKS_PER_SEC << endl;

	copy(vi0.begin(), vi0.end(), li.begin());
	start = clock();
	copy(li.begin(), li.end(), vi.begin());
	sort(vi.begin(), vi.end());
	copy(vi.begin(), vi.end(), li.begin());
	end = clock();
	cout << "li: " << (double)(end - start)/CLOCKS_PER_SEC << endl;

	cout <<endl;
}

int main(){

	test(100000);
	test(1000000);
	test(10000000);

	cin.get();

	return 0;
}
