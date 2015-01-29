#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


std::vector<short> load()
{
	std::vector<short> v;
	std::string line;

	while(std::getline(std::cin, line))
		for (int i = 0; i < line.size(); ++i)
			v.push_back(line[i] - '0');

	return v;
}

long eval(const std::vector<short>& v, int series_length)
{
	long largest = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		long t = 1;
		for (int j = i; j < i+series_length && j < v.size(); ++j)
		{
			if (v[j] == 0)
			{
				t = 0;
				break;
			}
			t *= v[j];
		}
		largest = std::max(largest, t);
	}
	return largest;
}

int main(int argc, char* argv[])
{
	int series_length = 13;
	if (argc > 2)
		series_length = atoi(argv[1]);

	std::vector<short> v = load();
	std::cout << eval(v, series_length) << std::endl;

	return 0;
}

