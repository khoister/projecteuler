#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

typedef std::vector< std::vector<int> > grid;


void load_grid(grid& g)
{
	std::string line;
	int n = 0;
	while(std::getline(std::cin, line))
	{
		std::vector<int> v;
		std::stringstream ss(line);
		while(!ss.eof())
		{
			ss >> n;
			v.push_back(n);
		}
		g.push_back(v);
	}
}

int max_product(const grid& g)
{
	int max       = 0;
	int max_horz  = 0;
	int max_vert  = 0;
	int max_right = 0;
	int max_left  = 0;
	int p_horz    = 1;
	int p_vert    = 1;
	int p_right   = 1;
	int p_left    = 1;

	for (int row = 0; row < g.size(); ++row)
	{
		for (int col = 0; col < g[row].size(); ++col)
		{
			p_horz = p_vert = p_right = p_left = 1;
			for (int i = 0; i < 4; ++i)
			{
				if (col+i < g[row].size())
					p_horz *= g[row][col+i];

				if (row+i < g.size())
					p_vert *= g[row+i][col];

				if (row+i < g.size() && col+i < g[row].size())
					p_right *= g[row+i][col+i];

				if (row+i < g.size() && col-i >= 0)
					p_left *= g[row+i][col-i];
			}
			max_horz  = std::max(max_horz, p_horz);
			max_vert  = std::max(max_vert, p_vert);
			max_right = std::max(max_right, p_right);
			max_left  = std::max(max_left, p_left);
			max = std::max(max, std::max(std::max(max_horz, max_vert), std::max(max_right, max_left)));
		}
	}
	return max;
}

int main(int argc, char* argv[])
{
	grid g;
	load_grid(g);
	std::cout << max_product(g) << std::endl;
	return 0;
}

