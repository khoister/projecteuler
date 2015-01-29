#include <iostream>


int main(int argc, char* argv[])
{
	int u = 500; // upper limit

	for (int a = 0; a <= u; ++a)
		for (int b = a+1; b <= u; ++b)
			for (int c = b+1; c <= u; ++c)
				// Find a Pythagorean triplet that sums up to 1000
				if ( ((a*a + b*b) == (c*c)) && ((a+b+c) == 1000) )
					std::cout << a << "*" << b << "*" << c << " = " << a*b*c << std::endl;
	return 0;
}

