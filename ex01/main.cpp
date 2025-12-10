#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	Span sp2 = Span(1000000);
	std::vector<unsigned int> large_range(1000000);
	for (unsigned int i = 0; i < 1000000; ++i)
		large_range[i] = i;
	sp2.addRange(large_range.begin(), large_range.end());
	try
	{
		sp2.addNumber(214748364);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
