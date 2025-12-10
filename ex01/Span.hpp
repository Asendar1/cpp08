#pragma once

#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

class Span
{
	private:
		std::vector<unsigned int> _array;
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

	void addNumber(unsigned int n);
	unsigned int shortestSpan();
	unsigned int longestSpan();
	void addRange(std::vector<unsigned int>::iterator start, std::vector<unsigned int>::iterator end);
};
