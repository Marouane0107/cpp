#include "BitcoinExchange.hpp"


bool    is_date_valid(std::string &date)
{
	if(date.empty())
		return (false);
	if(date.length() != 10)
		return (false);
	if(date[4] != '-' || date[7] != '-')
		return (false);
	if (!isdigit(date[0]) || !isdigit(date[1]) || !isdigit(date[2]) || !isdigit(date[3]))
		return (false);
    if (!isdigit(date[5]) || !isdigit(date[6]) || !isdigit(date[8]) || !isdigit(date[9]))
		return (false);

	return (true);
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

string get_closest_date(std::string &input_date, std::map<std::string, double> &bitcoin)
{
	
}

double	get_result(std::string &input_date, std::string &db_date, std::string &input_value, std::string &exchange_rate)
{
	double result;
	double value;
	double exchange;
	stringstream ss_value(input_value);
	ss >> value;
	stringstream ss_exchange_rate(exchange_rate);
	ss_exchange_rate >> exchange;


}
