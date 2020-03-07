/*
	배열과 반복문 
*/

#include <iostream>
using namespace std;

int main()
{
	const int num_students = 5;
	int scores[num_students] = { 84,92,76,81,56 };

	int total_scores = 0;

	for (int i = 0; i < num_students; ++i)
	{
		total_scores = total_scores + scores[i];
	}
	
	double avg = static_cast<double>(total_scores) / num_students;

	cout << "average : " << avg << endl;

	//---------------------------------------------------------------

	int max_number = scores[0];
	int min_number = scores[0];

	for (int i = 1; i < num_students; ++i)
	{
		//if (max_number < scores[i])
		//	max_number = scores[i];
		max_number = (max_number < scores[i]) ? scores[i] : max_number;

		//if (min_number > scores[i])
		//	min_number = scores[i];
		min_number = (min_number > scores[i]) ? scores[i] : min_number;
	}

	cout << "max_number : " << max_number << endl;
	cout << "min_number : " << min_number << endl;

	return 0;
}