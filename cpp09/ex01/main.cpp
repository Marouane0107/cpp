#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Usage: ./ex01 [string]" << std::endl;
        return (1);
    }
    if (!check_is_valid_input(av[1]))
    {
        std::cerr << "Error" << std::endl;
        return (1);
    }
    if (!check_is_valid_rpn(av[1]))
    {
        std::cerr << "Invalid RPN" << std::endl;
        return (1);
    }
    std::cout << calculate_rpn(av[1]) << std::endl;

    return (0);
}