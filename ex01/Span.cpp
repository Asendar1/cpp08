#include "Span.hpp"

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int n) : _maxSize(n) {}

Span::~Span() {}

Span::Span(const Span &other)
{
	*this = other;
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->_array = other._array;
		this->_maxSize = other._maxSize;
	}
	return *this;
}

void Span::addNumber(int n)
{
	if (_array.size() >= _maxSize)
		throw SpanFullException();
	_array.push_back(n);
}

unsigned int Span::shortestSpan()
{
	if (_array.size() < 2)
		throw NotEnoughElementsException();

	std::vector<int> sortedArray = _array;
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

	int minElement = *std::min_element(_array.begin(), _array.end());
	int maxElement = *std::max_element(_array.begin(), _array.end());

	return static_cast<unsigned int>(maxElement - minElement);
}
