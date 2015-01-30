#include <iostream>
#include <vector>


class PrimeSieve
{
	public:
		PrimeSieve(unsigned long n);
		unsigned long long sum_of_primes() const;

	private:
		unsigned long sieve_length;
		std::vector<unsigned char> sieve;
};

PrimeSieve::PrimeSieve(unsigned long n) :
	sieve_length(n+1),
	sieve(sieve_length)
{
	// To begin, everything is considered a prime
	for (unsigned long i = 2; i < sieve_length; ++i)
		sieve[i] = 1;

	// 0 and 1 are not primes; Eliminate other none-primes
	sieve[0] = sieve[1] = 0;
	for (unsigned long i = 2; i < sieve_length; ++i)
		for (unsigned long j = i*i; j < sieve_length; j += i)
			sieve[j] = 0;
}

unsigned long long PrimeSieve::sum_of_primes() const
{
	unsigned long long t = 0;
	for (int i = 0; i < sieve.size(); ++i)
		if (sieve[i])
			t += i;

	return t;
}

int main(int argc, char* argv[])
{
	unsigned long n = 2000000;
	if (argc > 1)
		n = atol(argv[1]);

	PrimeSieve sieve(n);
	std::cout << sieve.sum_of_primes() << std::endl;

	return 0;
}

