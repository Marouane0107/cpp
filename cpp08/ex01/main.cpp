#include "Span.hpp"

// int	main()
// {
// 	Span   span(11000);
// 	try {
// 		for (int i = 0; i < 11001; i++)
// 			span.addNumber(i);
// 	}
// 	catch (std::exception &e) {
// 		std::cout << e.what() << std::endl;
// 	}
// 	try {
// 		std::cout << span.shortestSpan() << std::endl;
// 		std::cout << span.longestSpan() << std::endl;
// 	}
// 	catch (std::exception &e) {
// 		std::cout << e.what() << std::endl;
// 	}
// 	return 0;
// }

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
	return 0;
}
