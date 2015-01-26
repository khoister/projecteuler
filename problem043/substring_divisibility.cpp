#include <string>
#include <iostream>
#include <set>

using namespace std;


bool pandigital_has_divisible_property(unsigned long long n)
{
	unsigned long long divisors[] = { 17, 13, 11, 7, 5, 3, 2 };

	bool has_property = true;
	for (int i = 0; i < sizeof(divisors) / sizeof(unsigned long long); ++i)
	{
		int num = n % 1000;
		n /= 10;

		if (num % divisors[i] != 0)
		{
			has_property = false;
			break;
		}
	}

	return has_property;
}

void swap(char& a, char&b)
{
	char c = a;
	a = b;
	b = c;
}

void permute(string& s, int i, int n, set<unsigned long long>& _set)
{
	if (i == n)
	{
		unsigned long long u = atoll(s.c_str());
		_set.insert(u);
	}
	else
	{
		int j;
		for (j = i; j <= n; j++)
		{
			swap(s[i], s[j]);
			permute(s, i+1, n, _set);
			swap(s[i], s[j]);
		}
	}
}

int main(int argc, char* argv[])
{
	// Generate all permutations of a pandigit number
	set<unsigned long long> _set;
	string s("0123456789");
	permute(s, 0, s.size()-1, _set);

	// Find the ones with prime divisible property
	unsigned long long total = 0ull;
	for (set<unsigned long long>::const_iterator it = _set.begin(); it != _set.end(); it++)
	{
		if (pandigital_has_divisible_property(*it))
			total += *it;
	}
	std::cout << "Total : " << total << std::endl;

	return 0;
}

