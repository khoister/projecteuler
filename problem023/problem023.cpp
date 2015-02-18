#include <iostream>
#include <assert.h>
#include <vector>
#include <set>


static const int UPPER_LIMIT = 28123;


int sum_of_divisors(int n)
{
	// Find all proper divisors
	int t = 0;
	for (int i = 2; i*i <= n; ++i)
	{
		if (n % i == 0)
		{
			t += i;
			if (i*i != n)
				t += n/i;
		}
	}
	// Include 1 in the sum
	return t+1;
}

bool is_abundant_number(int n)
{
	return (sum_of_divisors(n) > n ? true: false);
}

void find_abundant_numbers(std::vector<char>& v)
{
	// We know the smallest abundant number is 12
	for (int i = 12; i < v.size(); ++i)
		if (is_abundant_number(i))
			v[i] = 1;
}

int main(int argc, char* argv[])
{
	// Smoke tests
	assert(sum_of_divisors(28) == 28);
	assert(sum_of_divisors(12) == 16);

	std::vector<char> v(UPPER_LIMIT+1, 0);
	std::vector<char> a(UPPER_LIMIT+1, 0);

	// Find all abundant numbers less than upper limit
	find_abundant_numbers(v);

	// Find sum of abundant numbers
	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i])
		{
			for (int j = 0; j < v.size(); ++j)
			{
				if (v[j])
				{
					int sum = i+j;
					if (sum < v.size())
						// Both i and j are abundant numbers
						a[sum] = 1;
					else
						break;
				}
			}
		}
	}

	// Add up numbers that are NOT sum of two abundant numbers
	unsigned long long n = 0;
	for (int i = 0; i < a.size(); ++i)
		if (!a[i])
			n += i;
	std::cout << n << std::endl;
	return 0;
}

