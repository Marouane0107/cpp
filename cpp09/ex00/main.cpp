#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./ex00 filename" << std::endl;
        return 1;
    }
    std::ifstream file(argv[1]);
    std::ifstream database("data.csv");
    BitcoinExchange exchange;
    exchange.get_database(database);
    //std::cout << "Database loaded." << std::endl;
    exchange.get_data(file);
   // std::cout << "Data loaded." << std::endl;
    exchange.print_result();

    return 0;
}