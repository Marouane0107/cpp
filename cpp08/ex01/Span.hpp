#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdexcept>


class Span
{
	private:
		std::vector <unsigned int>    Numbers;
		unsigned int    N;
	public:
		Span();
		Span(unsigned int n);
		Span(Span const &other);
		Span &operator=(Span const &other);
		~Span();
		void    addNumber(unsigned int number);
		void	addNumber(std::vector<unsigned int>::iterator begin, std::vector<unsigned int>::iterator end);
		unsigned int    shortestSpan();
		unsigned int    longestSpan();
};

#endif