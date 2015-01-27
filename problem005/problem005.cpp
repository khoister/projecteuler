#include <iostream>

bool is_multiple(unsigned long long n)
{
	bool b = true;
	for (unsigned long long i = 2; i <= 20; ++i)
	{
		if (n % i)
		{
			b = false;
			break;
		}
	}
	return b;
}

int main()
{
	unsigned long long n = 20;
	while (!is_multiple(n))
		++n;

	std::cout << n << std::endl;
	return 0;
}

