#include <iostream>
#include <string>
#include <sstream>


static const char* small[] =
{
	"",
	"one",
	"two",
	"three",
	"four",
	"five",
	"six",
	"seven",
	"eight",
	"nine",
	"ten",
	"eleven",
	"twelve",
	"thirteen",
	"fourteen",
	"fifteen",
	"sixteen",
	"seventeen",
	"eighteen",
	"nineteen"
};

static const char* tens[] = 
{
	"",
	"ten",
	"twenty",
	"thirty",
	"forty",
	"fifty",
	"sixty",
	"seventy",
	"eighty",
	"ninety"
};

std::string number_to_words(int n)
{
	std::string words;

	if (n < 20)
		return small[n];

	if (n < 100)
	{
		std::stringstream ss;
		int t = n / 10;
		int r = n % 10;
		ss << tens[t];
		if (r)
			ss << small[r];
		return ss.str();
	}

	if (n < 1000)
	{
		std::stringstream ss;
		int h = n / 100;
		int r = n % 100;

		ss << small[h] << "hundred";
		if (r)
			ss << "and" << number_to_words(r);
		return ss.str();
	}

	if (n < 10000)
	{
		std::stringstream ss;
		int th = n / 1000;
		int r = n % 1000;

		ss << small[th] << "thousand";
		if (r)
			ss << number_to_words(r);
		return ss.str();
	}

	return words;
}

int main(int argc, char* argv[])
{
	std::stringstream ss;
	for (int i = 1; i <= 1000; ++i)
		ss << number_to_words(i);

	std::cout << ss.str().length() << std::endl;

	return 0;
}

