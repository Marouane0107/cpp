#include "BitcoinExchange.hpp"


bool    is_date_valid(std::string &date)
{
	if(date.empty())
		return false;
	if(date.length() != 10)
		return false;
	if(date[4] != '-' || date[7] != '-')
		return false;
	for(int i = 0; i < 10; i++){
		if(i == 4 || i == 7)
			continue;
		if(date[i] < '0' || date[i] > '9')
			return false;
	}
	return true;
}

bool    is_value_valid(std::string &value)
{
	if (value.empty())
		return false;

	for(std::string::size_type i = 0; i < value.length(); i++){
		if(value[i] < '0' || value[i] > '9')
			return false;
	}

	return true;
}

