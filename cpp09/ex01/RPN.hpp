#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>

int	check_is_operator(char c);
int	check_is_digit(char c);
int	check_is_valid_input(std::string input);
int	check_is_valid_rpn(std::string input);
int calculate_rpn(std::string input);

#endif 