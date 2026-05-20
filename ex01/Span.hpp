#pragma once

#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

class Span
{
	private:
		std::vector<int>	_array;
		unsigned int		_maxSize;
	public:
		Span();
		Span(unsigned int n);
		~Span();
		Span (const Span &other);
		Span &operator= (const Span &other);

	class SpanFullException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return "Span is already full";
			}
	};
	class NotEnoughElementsException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return "Not enough elements to calculate span";
			}
	};

	void addNumber(int n);
	unsigned int shortestSpan();
	unsigned int longestSpan();

	template <typename IT>
	void addRange(IT start, IT end)
	{
		size_t range_size = std::distance(start, end);

		if (_array.size() + range_size > _maxSize)
			throw SpanFullException();
		_array.insert(_array.end(), start, end);
	}
};
