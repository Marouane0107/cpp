#include "RPN.hpp"

int	check_is_operator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return (1);
    return (0);
}

int	check_is_digit(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int	check_is_valid_input(std::string input)
{
    for (size_t i = 0; i < input.length(); i++)
    {
        if (!check_is_digit(input[i]) && !check_is_operator(input[i]) && input[i] != ' ')
            return (0);
    }
    return (1);
}

int	check_is_valid_rpn(std::string input)
{
    std::stack<int> stack;
    int	operand = 0;
    int	operand_count = 0;
    int	operator_count = 0;

    for (size_t i = 0; i < input.length(); i++)
    {
        if (check_is_digit(input[i]))
        {
            operand = 0;
            while (check_is_digit(input[i]))
            {
                operand = operand * 10 + input[i] - '0';
                i++;
            }
            i--;
            stack.push(operand);
            operand_count++;
        }
        else if (check_is_operator(input[i]))
        {
            if (stack.size() < 2)
                return (0);
            stack.pop();
            stack.pop();
            stack.push(1);
            operator_count++;
        }
        else if (input[i] != ' ')
            return (0);
    }
    if (operand_count - operator_count != 1)
        return (0);
    return (1);
}

int calculate_rpn(std::string input)
{
    std::stack<int> stack;
    int	operand = 0;

    for (size_t i = 0; i < input.length(); i++)
    {
        if (check_is_digit(input[i]))
        {
            operand = 0;
            while (check_is_digit(input[i]))
            {
                operand = operand * 10 + input[i] - '0';
                i++;
            }
            i--;
            stack.push(operand);
        }
        else if (check_is_operator(input[i]))
        {
            if (stack.size() < 2)
                return (0);
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();
            if (input[i] == '+')
                stack.push(b + a);
            else if (input[i] == '-')
                stack.push(b - a);
            else if (input[i] == '*')
                stack.push(b * a);
            else if (input[i] == '/')
            {
                if (a == 0)
                {
                    std::cerr << "Error" << std::endl;
                    exit(1);
                }
                stack.push(b / a);
            }
        }
    }
    return (stack.top());
}