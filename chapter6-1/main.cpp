/*
	1. array 배열, struct array
*/

#include <iostream>
using namespace std;

enum class StudentName
{
	JACKAJACK,	// 0
	DASH,		// 1
	VIOLET,		// 2
	NUM_STUDENT,// 3
};

struct Rectangle
{
	int length;
	int width;
};

int main()
{
	int one_student_score; //1 variable
	int student_scores[5] = { 1,2,3,4,5 }; //5 int

	cout << sizeof(one_student_score) << " " << sizeof(student_scores) << endl; // 4 20

	student_scores[0] = 100;
	student_scores[1] = 80;
	student_scores[2] = 90;
	student_scores[3] = 50;
	student_scores[4] = 0;

	cout << student_scores[0] << endl;
	cout << student_scores[1] << endl;
	cout << student_scores[2] << endl;
	cout << student_scores[3] << endl;
	cout << student_scores[4] << endl;
	cout << endl;

	//--------------------------------------------------------------------

	cout << sizeof(Rectangle) << endl;

	Rectangle rect_arr[10];

	cout << sizeof(rect_arr) << endl;

	rect_arr[0].length = 1;
	rect_arr[0].width = 2;

	//------------------------------------------------------------------------
	
	/*
		array 초기화
		int my_array1[5] = { 1,2,3,4,5 };
		int my_array2[] = { 1,2,3,4,5 };
		int my_array3[]{ 1,2,3,4,5 };
		int my_array4[] = { 1,2, };
		int my_array5[5] = { 1,2,3, };
	*/

	//-------------------------------------------------------------------------

	/*
		int num_students = 0;
		cin >> num_students;

		int students_scores[num_students];

		=> error, cin의 경우 runtime중 결정되는데 정적배열의 사이즈는 컴파일 중 결정되어야 하므로 error발생
	*/

	const int num_student = 5;
	int students_scores[num_student];


	return 0;
}

