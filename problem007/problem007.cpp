#include <iostream>
#include <vector>


std::vector<unsigned long> prime_sieve(unsigned long n)
{
	if (n < 2)
		return std::vector<unsigned long>();

	std::vector<unsigned long> primes(n+1);

	// Initialize
	primes[0] = 0;
	primes[1] = 0;
	for (unsigned long i = 2; i < n+1; ++i)
		primes[i] = 1;

	for (unsigned long i = 2; i < n+1; ++i)
	{
		unsigned long k = i*i;
		for (unsigned long j = k; j < n+1; j+=i)
			primes[j] = 0;
	}

	return primes;
}

unsigned long number_of_primes(const std::vector<unsigned long>& sieve)
{
	unsigned long t = 0;
	for (unsigned long i = 0; i < sieve.size(); ++i)
		t += sieve[i] ? 1 : 0;
	return t;
}

unsigned long nth_prime(const std::vector<unsigned long>& sieve, unsigned long nth)
{
	unsigned long t = 0;
	for (unsigned long i = 0; i < sieve.size(); ++i)
	{
		t += sieve[i] ? 1 : 0;
		if (t == nth)
			return i;
	}
	return 0;
}

int main(int argc, char* argv[])
{
	unsigned long n   = 110000; // Find primes up to n
	unsigned long nth = 10001;  // The nth prime
	if (argc > 1)
		n = atol(argv[1]);
	if (argc > 2)
		nth = atol(argv[2]);

	// Get the 10001st prime number
	std::vector<unsigned long> sieve = prime_sieve(n);
	if (number_of_primes(sieve) > nth)
	{
		std::cout << nth << " prime -> " << nth_prime(sieve, nth) << std::endl;
	}
	else
		std::cout << "Not enough primes" << std::endl;

	return 0;
}

