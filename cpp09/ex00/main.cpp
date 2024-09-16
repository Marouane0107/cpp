#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    std::ifstream file(argv[1]);
    std::ifstream database("data.csv");
    BitcoinExchange exchange;
    exchange.get_database(database);
    exchange.get_data(file);
    

    return 0;
}