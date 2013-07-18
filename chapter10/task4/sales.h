#ifndef SALES_H
#define SALES_H

namespace SALES
{

	class Sales
	{
	private:
		static const int QUARTERS = 4;
		double sales[QUARTERS];
		double average;
		double max;
		double min;
	public:
		// copies the lesser of 4 or n items from the array ar
		// to the sales member of s and computes and stores the
		// average, maximum, and minimum values of the entered items;
		// remaining elements of sales, if any, set to 0
		Sales(const double ar[] = 0, int n = 0);
		// gathers sales for 4 quarters interactively, stores them
		// in the sales member of s and computes and stores the
		// average, maximum, and minimum values
		void setSales();
		// display all information in structure s
		void showSales() const;
	};
}

#endif
