#include <iostream>
#include <algorithm>

template <typename T>
int easyfind(T &container, int n)
{
	if (std::find(container.begin(), container.end(), n) == container.end())
		throw std::runtime_error("Value not found in container");
	return n;
}
