#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    std::ifstream file(argv[1]);
    if(!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    std::string line;
    std::map<std::string, double> bitcoin;
    while(std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string date;
        std::string value;
        std::getline(ss, date, ',');
        std::getline(ss, value, ',');
        if(!is_date_valid(date) || !is_value_valid(value))
            std::cerr << "Error: bad input => " << line << std::endl;
        bitcoin[date] = std::atoi(value.c_str());
    }
    for (std::map<std::string, double>::iterator it = bitcoin.begin(); it != bitcoin.end(); ++it)
    {
        std::cout << it->first << " " << it->second << std::endl;
    }
    return 0;
}