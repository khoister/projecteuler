#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <assert.h>


void get_names(std::set<std::string>& names)
{
	std::string line;
	while (std::getline(std::cin, line, ','))
	{
		size_t p = line.find_last_of('"');
		std::string name = line.substr(1, p-1);
		names.insert(name);
	}
}

int name_score(const std::string& name, int pos)
{
	int val = 0;
	for (int i = 0; i < name.size(); ++i)
		val += (name[i] - 'A' + 1) * pos;
	return val;
}

int main(int argc, char* argv[])
{
	assert(name_score("COLIN", 938) == 49714);

	// Insert names into a set for sorted order
	std::set<std::string> names;
	get_names(names);

	long total = 0;
	int i = 0;
	for (std::set<std::string>::const_iterator it = names.begin(); it != names.end(); ++it)
		total += name_score(*it, ++i);

	std::cout << total << std::endl;
	return 0;
}

