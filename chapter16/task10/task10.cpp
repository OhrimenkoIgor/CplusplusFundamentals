
// vect3.cpp -- using STL functions
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

struct Review {
	std::string title;
	int rating;
	double price;
};

std::shared_ptr<Review> FillReview();
void ShowReview(const std::shared_ptr<Review> & rr);
bool operator<(const std::shared_ptr<Review> & r1, const  std::shared_ptr<Review> r2);
bool worseThan(const std::shared_ptr<Review> & r1, const  std::shared_ptr<Review> r2);
bool cheaperThan(const std::shared_ptr<Review> & r1, const  std::shared_ptr<Review> r2);

bool show_menu();

int main()
{
	using namespace std;
	vector<shared_ptr<Review> > books;
	shared_ptr<Review> temp;
	while (temp = FillReview())
		books.push_back(temp);
	if (books.size() > 0)
	{
		vector<shared_ptr<Review> > books_stitle(books.begin(), books.end());
		sort(books_stitle.begin(), books_stitle.end());

		vector<shared_ptr<Review> > books_srating(books.begin(), books.end());
		sort(books_srating.begin(), books_srating.end(), worseThan);

		vector<shared_ptr<Review> > books_sprice(books.begin(), books.end());
		sort(books_sprice.begin(), books_sprice.end(), cheaperThan);

		char key;
		while(show_menu() && cin>>key){
			while (cin.get() != '\n');

			if (key == 'q')
				break;

			switch(key){
			case '1':
				cout << "Rating\tBook\tPrice\n";
				for_each(books.begin(), books.end(), ShowReview);
				break;
			case '2':
				cout << "Rating\tBook\tPrice\n";
				for_each(books_stitle.begin(), books_stitle.end(), ShowReview);
				break;
			case '3':
				cout << "Rating\tBook\tPrice\n";
				for_each(books_srating.begin(), books_srating.end(), ShowReview);
				break;
			case '4':
				cout << "Rating\tBook\tPrice\n";
				for_each(books_srating.rbegin(), books_srating.rend(), ShowReview);
				break;
			case '5':
				cout << "Rating\tBook\tPrice\n";
				for_each(books_sprice.begin(), books_sprice.end(), ShowReview);
				break;
			case '6':
				cout << "Rating\tBook\tPrice\n";
				for_each(books_sprice.rbegin(), books_sprice.rend(), ShowReview);
				break;
			}
		}
	}
	else
		cout << "No entries. ";
	cout << "Bye.\n";

	while (cin.get() != '\n');
	cin.get();
	return 0;
}

std::shared_ptr<Review> FillReview()
{
	std::shared_ptr<Review> rr(new Review);
	std::cout << "Enter book title (quit to quit): ";
	std::getline(std::cin,rr->title);
	if (rr->title == "quit")
		return std::shared_ptr<Review>();
	std::cout << "Enter book rating: ";
	std::cin >> rr->rating;
	if (!std::cin){
		std::cin.clear();
		return std::shared_ptr<Review>();
	}
	std::cout << "Enter book price: ";
	std::cin >> rr->price;
	if (!std::cin){
		std::cin.clear();
		return std::shared_ptr<Review>();
	}
	// get rid of rest of input line
	while (std::cin.get() != '\n')
		continue;
	return rr;
}

void ShowReview(const std::shared_ptr<Review> & rr)
{
	std::cout << rr->rating << "\t" << rr->title << "\t"<< "$" << rr->price << std::endl;
}

bool operator<(const std::shared_ptr<Review> & r1, const  std::shared_ptr<Review> r2){
	if (r1->title < r2->title)
		return true;
	else if (r1->title == r2->title && r1->rating < r2->rating)
		return true;
	else if (r1->title == r2->title && r1->rating == r2->rating && r1->price < r2->price)
		return true;
	return false;
}

bool worseThan(const std::shared_ptr<Review> & r1, const  std::shared_ptr<Review> r2){
	if (r1->rating < r2->rating)
		return true;
	return false;
}

bool cheaperThan(const std::shared_ptr<Review> & r1, const  std::shared_ptr<Review> r2){
	if (r1->price < r2->price)
		return true;
	return false;
}

bool show_menu(){
	std::cout << std::endl << "Possible choices:\n"
		"1: in original order\n" 
		"2: in alphabetical order\n"
		"3: in order of increasing ratings\n"
		"4: in order of decreasing ratings\n"
		"5: in order of increasing price\n"
		"6: in order of decreasing price\n"
		"q: and quitting\n";
	return true;
}
