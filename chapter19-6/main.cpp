/*
	��Ƽ������ ����
	(���� ���� ���)

	atomic, lockguard�� ����ϰ� ȣ��Ǵ� ���� ����ϸ� ������
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