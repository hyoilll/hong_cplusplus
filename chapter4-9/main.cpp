/*
	자료형 가명 붙이기 (Type aliases)
*/

#include <iostream>
#include <vector>
#include <cstdint>

int main()
{
	typedef double distance_t;

	std::int8_t i(97); // == typedef double

	//변수 선언 2가지 타입 (같음)
	double my_distance = 0.0;
	distance_t home2work = 0.0;
	
	/*
		만약 나중에 distance를 나타내는 변수의 자료형이 
		double > float로 변경 되면 typedef선언하면 쉽게 변경 가능 = 유지보수에 좋음 
	*/

	//---------------------------------------------------------------------

	using namespace std;

	vector<pair<string, int>> pairlist1;
	vector<pair<string, int>> pairlist2;
	vector<pair<string, int>> pairlist3;

	typedef vector<pair<string, int>> pairlist_t;
	// == using pairlist_t = vector<pair<string, int>>; '컴파일러에게 이런 가명을 붙이겠다' 라는 메세지

	pairlist_t pairlist4;
	pairlist_t pairlist5;

	//좀 더 깔끔해짐

	return 0;
}