#include <iostream>
#include <vector>



class Grid
{
	public:
		Grid(int x, int y);
		Grid& calc();
		void print(bool debug = false) const;
		unsigned long long routes() const;

	private:
		void init(int x, int y);

	private:
		typedef std::vector<unsigned long long> column;
		typedef std::vector<column> grid;
		grid g;
};

Grid::Grid(int x, int y)
{
	init(x, y);
}

void Grid::init(int x, int y)
{
	// Create a two-dimensional grid with all intersections set t 0
	for (int i = 0; i < x+1; ++i)
		g.push_back(column(y+1,0));

	// Top horizontal row has just one path going across at each intersection
	for (int i = 1; i < g.size(); ++i)
		g[i][0] = 1;

	// Left vertical column has just one path going down at each intersection
	for (int i = 1; i < g[0].size(); ++i)
		g[0][i] = 1;
}

Grid& Grid::calc()
{
	// For each intersection (x,y), we add the number of paths from (x-1,y) and (x,y-1)
	for (int y = 1; y < g[0].size(); ++y)
		for (int x = 1; x < g.size(); ++x)
			g[x][y] = g[x-1][y] + g[x][y-1];
	return *this;
}

void Grid::print(bool debug) const
{
	if (!debug) return;

	for (int y = 0; y < g[0].size(); ++y)
	{
		for (int x = 0; x < g.size(); ++x)
			std::cout << g[x][y] << " ";
		std::cout << std::endl;
	}
}

unsigned long long Grid::routes() const
{
	int x = g.size()-1;
	int y = g[0].size()-1;
	return g[x][y];
}

int main(int argc, char* argv[])
{
	int x = 20;
	int y = 20;
	if (argc > 2)
	{
		x = atoi(argv[1]);
		y = atoi(argv[2]);
	}

	Grid g(x, y);
	std::cout << g.calc().routes() << std::endl;

	return 0;
}

