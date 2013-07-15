
#include <iostream>

using namespace std;

int read_array(double arr[], int arr_size){
	int i = 0;
	while(i < arr_size && cin >> arr[i]){
		i++;
	}
	cin.clear();
	return i;
}

void display_array_in_line(double arr[], int num){
	for(int i = 0; i < num; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

double count_array_average(double arr[], int num){
	double sum = 0;
	for(int i = 0; i < num; i++){
		sum += arr[i];
	}
	return sum/num;
}

int main()
{
	const int arr_size = 10;
	double scores[arr_size] = { 0 };

	cout << "Enter up to 10 golf scores (not a number terminates input):" << endl;	
	int num_scores = read_array(scores, arr_size);

	cout << "Scores:" << endl;	
	display_array_in_line(scores, num_scores);

	cout << "The average: " << count_array_average(scores, num_scores) << endl;
	
	cin.ignore(cin.rdbuf()->in_avail());
	cin.get();

	return 0;
}