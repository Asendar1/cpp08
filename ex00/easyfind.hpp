#pragma once

#include <iostream>
#include <algorithm>
#include <stdexcept>

template <typename T>
int easyfind(const T &container, int n)
{
	if (std::find(container.begin(), container.end(), n) == container.end())
		throw std::runtime_error("Value not found in container");
	return n;
}
