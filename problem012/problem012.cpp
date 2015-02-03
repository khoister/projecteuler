#include <iostream>
#include <math.h>


int main(int argc, char* argv[])
{
	int limit = 500;
	if (argc > 1)
		limit = atoi(argv[1]);

	int n   = 0;
	int tri = 0;
	int f   = 0;

	while (f <= limit)
	{
		// Triangular number
		tri += ++n;

		f = 2; // Skip checking 1 and the number itself
		int sqroot = int(sqrt(tri));
		for (int j = 2; j < sqroot; ++j)
			if (tri % j == 0)
				// Since we're checking up to the square root of t,
				// the factors are mirrored so there are two of them.
				f += 2;
	}
	std::cout << tri << std::endl;
	return 0;
}

