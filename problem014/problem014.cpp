#include <iostream>
#include <algorithm>
#include <assert.h>


unsigned long collatz_number(unsigned long n)
{
	if (n < 1)
		return 0;

	unsigned long chain = 1;
	while (n != 1)
	{
		n = (n%2 == 0) ? (n>>1) : (n*3)+1;
		++chain;
	}
	return chain;
}

int main(int argc, char* argv[])
{
	int limit = 1000000;
	if (argc > 1)
		limit = atoi(argv[1]);

	// Tests
	assert(collatz_number(0) == 0);
	assert(collatz_number(1) == 1);
	assert(collatz_number(13) == 10);

	// Solve
	int longest_chain = 0;
	int answer = 0;
	for (int i = 0; i < limit; ++i)
	{
		int chain = collatz_number(i);
		if (chain > longest_chain)
		{
			longest_chain = chain;
			answer = i;
		}
	}
	std::cout << answer << " has chain length " << longest_chain << std::endl;
	
	return 0;
}

