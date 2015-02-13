#include <iostream>
#include <vector>
#include <math.h>
#include <assert.h>


int proper_divisors_sum(int n)
{
	int t = 0;
	int s = n >> 1;
	for (int i = 1; i <= s; ++i)
		if (n % i == 0)
			t += i;
	return t;
}


int main(int argc, char* argv[])
{
	// Tests
	assert(proper_divisors_sum(220) == 284);
	assert(proper_divisors_sum(284) == 220);

	// Find the answer...
	int t = 0;
	std::vector<unsigned char> v(10000,1);
	for (int a = 0; a < v.size(); ++a)
	{
		if (v[a])
		{
			int b = proper_divisors_sum(a);
			if (v[b])
			{
				// Find amicable pairs and add to total
				if (a != b && proper_divisors_sum(b) == a)
					t += (a+b);

				// Don't look at this pair again
				v[a] = v[b] = 0;
			}
		}
	}
	std::cout << t << std::endl;

	return 0;
}

