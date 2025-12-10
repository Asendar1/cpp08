#include "Span.hpp"

Span::Span() : _maxSize(0)
{
}

Span::Span(unsigned int n) : _maxSize(n)
{
}

Span::~Span()
{
}

Span::Span (const Span &other) : _array(other._array), _maxSize(other._maxSize)
{
}

Span &Span::operator= (const Span &other)
{
	if (this != &other)
	{
		_array = other._array;
		_maxSize = other._maxSize;
	}
	return *this;
}

void Span::addNumber(unsigned int n)
{
	if (_array.size() >= _maxSize)
		throw SpanFullException();
	_array.push_back(n);
}

unsigned int Span::shortestSpan()
{
	if (_array.size() < 2)
		throw NotEnoughElementsException();

	std::vector<unsigned int> sortedArray = _array;
	std::sort(sortedArray.begin(), sortedArray.end());

	unsigned int minSpan = UINT_MAX;
	for (size_t i = 1; i < sortedArray.size(); ++i)
	{
		unsigned int span = sortedArray[i] - sortedArray[i - 1];
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

unsigned int Span::longestSpan()
{
	if (_array.size() < 2)
		throw NotEnoughElementsException();

	unsigned int minElement = *std::min_element(_array.begin(), _array.end());
	unsigned int maxElement = *std::max_element(_array.begin(), _array.end());

	return maxElement - minElement;
}

void Span::addRange(std::vector<unsigned int>::iterator start, std::vector<unsigned int>::iterator end)
{
	size_t range_size = std::distance(start, end);

	if (_array.size() + range_size > _maxSize)
		throw SpanFullException();
	_array.insert(_array.end(), start, end);
}
