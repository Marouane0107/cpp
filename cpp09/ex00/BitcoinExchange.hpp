#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cstdlib>



bool	is_date_valid(std::string &date);
bool	is_value_valid(std::string &value);
bool    result(std::string &date, std::string &value, std::map<std::string, double> &bitcoin);


#endif