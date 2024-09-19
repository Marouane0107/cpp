#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	if (this != &copy)
	{
		*this = copy;
	}
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	if (this != &copy)
	{
		_file_data = copy._file_data;
	}
	return *this;
}

int BitcoinExchange::check_is_date_valid(std::string date, std::string input)
{
	if (date.size() != 10)
	{
		std::cerr << "Error: bad input => " << input << std::endl;
		return 1;
	}
	if (date[4] != '-' || date[7] != '-')
	{
		std::cerr << "Error: bad input => " << input << std::endl;
		return 1;
	}
	for (size_t i = 0; i < date.size(); i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(date[i]))
		{
			std::cerr << "Error: bad input => " << input << std::endl;
			return 1;
		}
	}


	return 0;
}

int	BitcoinExchange::check_val_range(double val)
{
	if (val < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return 1;
	}
	if (val > 1000)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return 1;
	}
	return 0;
}

int BitcoinExchange::check_is_value_valid(std::string value)
{
	if (value.empty())
	{
		std::cerr << "Error: bad input => " << value << std::endl;
		return 1;
	}
	std::stringstream ss(value);
	double val;
	ss >> val;
	if (check_val_range(val))
		return 1;
	for (size_t i = 0; i < value.size(); i++)
	{
		if (!isdigit(value[i]) && value[i] != '.')
		{
			std::cerr << "Error: bad input => " << value << std::endl;
			return 1;
		}
	}
	int dot_count = 0;
	for (size_t i = 0; i < value.size(); i++)
	{
		if (value[i] == '.')
			dot_count++;
	}
	if (dot_count > 1)
	{
		std::cerr << "Error: bad input => " << value << std::endl;
		return 1;
	}

	return 0;
}

int BitcoinExchange::check_if_line_is_valid(std::string line)
{
	if (line.empty())
		return 1;
	
	std::string date;
	std::string pipe;
	std::string value;
	std::string tmp;
	std::stringstream ss(line);
	ss >> date >> pipe >> value >> tmp;
	if (!tmp.empty())
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return 1;
	}
	if (date.empty() )
		return 1;
	if (check_is_date_valid(date, line))
		return 1;
	if (pipe != "|" || check_date_range(date))
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return 1;
	}
	if (check_is_value_valid(value))
		return 1;
	
	return 0;
}

void	BitcoinExchange::check_empty_file(std::ifstream &file)
{
	if (file.peek() == std::ifstream::traits_type::eof())
	{
		std::cerr << "Error: file is empty." << std::endl;
		exit(1);
	}
}

void	BitcoinExchange::find_head_of_file(std::ifstream &file)
{
	std::string line;

	while (getline(file, line))
	{
		if (line.empty())
			continue;
		else
		{
			std::string date;
			std::string pipe;
			std::string value;
			std::stringstream ss(line);
			ss >> date >> pipe >> value;
			if (date != "date" || pipe != "|" || value != "value")
			{
				std::cerr << "Error: line must start with 'Date | Value'." << std::endl;
				exit(1);
			}
			break;
		}
	}
}


void	BitcoinExchange::get_data(std::ifstream &file)
{
	std::string line;
	std::string key;
	std::string pipe;
	double value;

	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		exit(1);
	}
	check_empty_file(file);
	find_head_of_file(file);
	while (std::getline(file, line))
	{
		if (!check_if_line_is_valid(line))
		{
			std::istringstream iss(line);
			iss >> key >> pipe >> value;
			_file_data[key] = value;
			value_multipliedby_exchangerate(key, value);
		}
	}
	file.close();
}

void	BitcoinExchange::get_database(std::ifstream &file)
{
	std::string line;
	std::string date;
    std::string str_value;
	double value;
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file (database)." << std::endl;
		exit(1);
	}
	std::getline(file, line);
	while(std::getline(file, line))
	{
		std::stringstream ss(line);
        if (std::getline(ss, date, ',') && std::getline(ss, str_value))
		{
        	std::stringstream rate_ss(str_value);
        	rate_ss >> value;
        	_database[date] = value;
        }
	}
	file.close();
}

bool BitcoinExchange::isLeapYear(int year)
{
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            return year % 400 == 0;
        }
        return true;
    }
    return false;
}

int	BitcoinExchange::check_date_range(std::string date)
{
	std::string tmp;
	int year;
	int month;
	int day;
	
	std::stringstream ss(date);
	std::getline(ss, tmp, '-');
	std::stringstream convert(tmp);
	convert >> year;
	tmp.clear();
	std::getline(ss, tmp, '-');
	std::stringstream convert2(tmp);
	convert2 >> month;
	tmp.clear();
	std::getline(ss, tmp);
	std::stringstream convert3(tmp);
	convert3 >> day;
	if (year < 2009 || year > 2022 || month < 1 || month > 12 || day < 1 || day > 31)
		return 1;
	if (month == 2 && day > 28)
	{
		if (isLeapYear(year) && day == 29)
			return 0;
		return 1;
	}
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return 1;
	return 0;
}

std::string	BitcoinExchange::convert_date_to_string(int year, int month, int day)
{
	std::string date;
	std::string tmp;
	std::stringstream ss;
	ss << year;
	ss >> tmp;
	date += tmp;
	date += "-";
	ss.clear();
	if (month < 10)
		date+= "0";
	ss << month;
	ss >> tmp;
	date += tmp;
	date += "-";
	ss.clear();
	if (day < 10)
		date+= "0";
	ss << day;
	ss >> tmp;
	date += tmp;
	return date;
}


double	BitcoinExchange::get_clousest_date(std::string date, int year, int month, int day)
{
	std::string new_date = convert_date_to_string(year, month, day);
	std::map<std::string, double>::iterator it;
	it = _database.find(new_date);
	if (it != _database.end())
		return it->second;
	else
	{
		if (day > 1)
			return get_clousest_date(date, year, month, day - 1);
		else if (month > 1)
			return get_clousest_date(date, year, month - 1, 31);
		else if (year > 2009)
			return get_clousest_date(date, year - 1, 12, 31);
		else
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			return -1;
		}
	}
	return 0;
}

void	BitcoinExchange::value_multipliedby_exchangerate(std::string date, double value)
{
	int year;
	int month;
	int day;
	std::string tmp;
	std::stringstream ss(date);
	std::getline(ss, tmp, '-');
	std::stringstream convert(tmp);
	convert >> year;
	tmp.clear();
	std::getline(ss, tmp, '-');
	std::stringstream convert2(tmp);
	convert2 >> month;
	tmp.clear();
	std::getline(ss, tmp);
	std::stringstream convert3(tmp);
	convert3 >> day;

	std::map<std::string, double>::iterator it;
	it = _database.find(date);
	if (it != _database.end())
		std::cout << date << " => " << value << " = " << value * it->second << std::endl;
	else
	{
		double val = get_clousest_date(date, year, month, day);
		if (val != -1)
			std::cout << date << " => " << value << " = " << value * val << std::endl;
		else
			return;
	}
}
