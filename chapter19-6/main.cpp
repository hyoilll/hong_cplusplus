/*
	멀티쓰레딩 예제
	(벡터 내적 계산)

	atomic, lockguard는 빈번하게 호출되는 곳에 사용하면 느려짐
*/

#include <vector>

int main()
{
	/*
		v0 = {1,2,3}
		v1 = {4,5,6}
		v0_dot_v1 = 1*4 + 2*5 + 3*6
	*/

	const long long n_data = 100'000'000;
	const unsigned int n_threads = 4;

	// initialize vectors
	std::vector<int> v0, v1;

	v0.reserve(n_data);
	v1.reserve(n_data);




	return 0;
}