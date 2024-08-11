#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
#include <list>
#include <stdexcept>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() : std::stack<T>() {}
		MutantStack(const MutantStack &other) : std::stack<T>(other) {}
		MutantStack &operator=(const MutantStack &other)
		{
			if (this == &other)
				return *this;
			std::stack<T>::operator=(other);
			return *this;
		}
		~MutantStack() {}

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin()
		{
			return std::stack<T>::c.begin();
		}

		iterator end()
		{
			return std::stack<T>::c.end();
		}
};

#endif