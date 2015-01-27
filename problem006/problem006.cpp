#include <iostream>


unsigned long long square_of_sum(int n)
{
	// Using math:
	//
	//  n(n + 1)
	//  --------
	//     2  
	unsigned long long m = (n * (n+1)) >>  1;
	return (m*m);
}

unsigned long long sum_of_squares(int n)
{
#if 0
	// Using iteration
	unsigned long long t = 0;
	for (int i = 1; i <= n; ++i)
		t += (i*i);

	return t;
#endif

	// Using math:
	//
	//  n(n + 1)(2n + 1)
	//  ----------------
	//        6
	return n*(n+1)*(2*n+1) / 6;
}

int main(int argc, char* argv[])
{
	int n = 100;
	if (argc > 1)
		n = atoi(argv[1]);

	std::cout << square_of_sum(n) - sum_of_squares(n) << std::endl;
}

