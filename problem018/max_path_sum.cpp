#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;


typedef vector< vector<int> > triangle;


void print(triangle& t, bool debug = false)
{
	if (!debug)
		return;

	std::cout << std::endl;
	for (int i = 0; i < t.size(); ++i)
	{
		for (int j = 0; j < t[i].size(); ++j)
			std::cout << t[i][j] << " ";

		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void load(triangle& t)
{
	int line_no = 0;
	string line;

	while (std::getline(cin, line))
	{
		++line_no;
		stringstream ss(line);

		// Add a row to the triangle
		t.push_back(vector<int>());

		int val;
		for (int i = 0; i < line_no; ++i)
		{
			ss >> val;
			t[line_no-1].push_back(val);
		}
	}
}

void calculate(triangle& t, bool debug = false)
{
	int height = t.size();

	for (int i = 1; i < height; ++i)
	{
		int width = t[i].size();
		int previous_row = i - 1;

		for (int j = 0; j < width; ++j)
		{
			int s1 = 0;
			int s2 = 0;

			if (j-1 >= 0)
			{
				s1 = t[i][j] + t[previous_row][j-1];
				if (debug)
					std::cout << "s1 = (" << t[i][j] << "+" << t[previous_row][j-1] << "=" << s1 << "), ";
			}

			if (j >= 0 && j < width-1)
			{
				s2 = t[i][j] + t[previous_row][j];
				if (debug)
					std::cout << "s2 = (" << t[i][j] << "+" << t[previous_row][j] << "=" << s2 << "), ";
			}

			t[i][j] = std::max(s1, s2);
		}
		if (debug)
			std::cout << std::endl;
	}
}

int max_path_sum(const triangle& t)
{
	// The maximum path sum will be contained in the bottom row of the triangle
	int bottom_row = t.size() - 1;
	return (bottom_row >= 0) ? *std::max_element(t[bottom_row].begin(), t[bottom_row].end()) : 0;
}


int main()
{
	triangle t;

	load(t);
	print(t);
	calculate(t);
	print(t);
	std::cout << "Max path sum is " << max_path_sum(t) << std::endl;

	return 0;
}

