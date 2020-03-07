/*
	이동 생성자와 이동 대입
*/

#include "AutoPtr.h"
#include "Resource.h"

using namespace std;

AutoPtr<Resource> generateResouce()
{
	AutoPtr<Resource> res(new Resource(10000000));

	return res;
}

int main() 
{
	using namespace std;

	streambuf* orig_buf = cout.rdbuf();

	{
		AutoPtr<Resource> main_res;
		main_res = generateResouce();
	}

	cout.rdbuf(orig_buf);

	return 0;
}