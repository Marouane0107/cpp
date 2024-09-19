#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cstdlib>

class BitcoinExchange
{
	private:
		std::map<std::string, double> _file_data;
		std::map<std::string, double> _database;
		
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &copy);
		void	get_data(std::ifstream &file);
		void	get_database(std::ifstream &file);
		void	find_head_of_file(std::ifstream &file);
		int		check_if_line_is_valid(std::string line);
		int		check_is_date_valid(std::string date, std::string input);
		int		check_is_value_valid(std::string value);
		int		check_val_range(double val);
		int		check_date_range(std::string date);
		void	value_multipliedby_exchangerate(std::string date, double value);
		double	get_clousest_date(std::string date, int year, int month, int day);
		bool	isLeapYear(int year);
		std::string	convert_date_to_string(int year, int month, int day);
		void	check_empty_file(std::ifstream &file);
};


#endif