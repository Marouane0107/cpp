#include "Span.hpp"

Span::Span() : N(0)
{
}

Span::Span(unsigned int n) : N(n)
{
}

Span::Span(Span const &other)
{
	*this = other;
}

Span &Span::operator=(Span const &other)
{
	if (this != &other)
	{
		this->Numbers = other.Numbers;
		this->N = other.N;
	}
	return *this;
}

Span::~Span()
{
}

void    Span::addNumber(unsigned int number)
{
	if (this->Numbers.size() < this->N)
		this->Numbers.push_back(number);
	else
		throw std::runtime_error("Exception: Span is full");
}

unsigned int	Span::shortestSpan()
{
	if (this->Numbers.size() < 2)
		throw std::runtime_error("Exception: Not enough numbers to calculate span");
	std::vector <unsigned int>    sorted = this->Numbers;
	std::sort(sorted.begin(), sorted.end());
	unsigned int    min = sorted[1] - sorted[0];
	for (unsigned int i = 2; i < sorted.size(); i++)
	{
		unsigned int    diff = sorted[i] - sorted[i - 1];
		if (diff < min)
			min = diff;
	}
	return min;
}

unsigned int	Span::longestSpan()
{
	if (this->Numbers.size() < 2)
		throw std::runtime_error("Exception: Not enough numbers to calculate span");
	std::vector <unsigned int>    sorted = this->Numbers;
	std::sort(sorted.begin(), sorted.end());
	return sorted[sorted.size() - 1] - sorted[0];
}

void	Span::addNumber(std::vector<unsigned int>::iterator begin, std::vector<unsigned int>::iterator end)
{
	if (this->Numbers.size() + std::distance(begin, end) > this->N)
		throw std::runtime_error("Exception: Span is full");
	this->Numbers.insert(this->Numbers.end(), begin, end);
}
