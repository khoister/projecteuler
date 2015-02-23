#include <iostream>
#include <vector>


std::vector<bool> create_sieve(int n)
{
	std::vector<bool> sieve(n, true);

	for (int i = 2; i < n; ++i)
		if (sieve[i])
			for (int j = i*i; j < n; j += i)
				// Not a prime
				sieve[j] = false;
	return sieve;
}

// For debugging
void dump_sieve(const std::vector<bool>& sieve)
{
	for (int i = 0; i < sieve.size(); ++i)
		if (sieve[i])
			std::cout << i << ' ';
	std::cout << std::endl;
}

inline int compute_quadratic(int n, int a, int b)
{
	return n*n + a*n + b;
}

int consecutive_primes(int a, int b, const std::vector<bool>& sieve)
{
	int streak = 0;
	int n = 0;
	int c = 0;

	while ((c = compute_quadratic(n++, a, b)) > 0 && sieve[c])
		++streak;
	return streak;
}

int quadratic_primes(const std::vector<bool>& sieve)
{
	int longest_consecutive_primes = 0;
	int A = 0;
	int B = 0;

	// Look between |a| < 1000 and |b| < 1000
	for (int a = -999; a < 1000; ++a)
	{
		for (int b = -999; b < 1000; ++b)
		{
			int c = consecutive_primes(a, b, sieve);
			if (c > longest_consecutive_primes)
			{
				longest_consecutive_primes = c;
				A = a;
				B = b;
			}
		}
	}
	return (A*B);
}

int main(int argc, char* argv[])
{
	int n = 1000;
	if (argc > 1)
		n = atoi(argv[1]);

	// Generate primes with values up to n
	std::vector<bool> v = create_sieve(n);
	std::cout << quadratic_primes(v) << std::endl;

	return 0;
}

