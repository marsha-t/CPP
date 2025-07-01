#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) 
{
	debugMsg("BitcoinExchange initialised");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)
{
	debugMsg("BitcoinExchange initalised via copy");
	_database = obj._database;	
}

BitcoinExchange::~BitcoinExchange(void) 
{
	debugMsg("BitcoinExchange destroyed");
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &obj)
{
	if (this != &obj)
	{
		debugMsg("BitcoinExchange copied via assignment");
		_database = obj._database;
	}
	return (*this);
}

void	BitcoinExchange::loadDatabase(std::string const &filename)
{
	if (!checkCSVExtension(filename))
		throw std::invalid_argument("Database must have .csv extension");
	std::ifstream	database(filename.c_str());
	if (!database.is_open())
		throw std::runtime_error("Cannot open database file: " + filename);
	std::string	row;
	if (!std::getline(database, row) || row != "date,exchange_rate")
		throw std::runtime_error("Invalid CSV header in database file");
	std::size_t	comma;
	std::string date;
	std::string valueStr;
	double value;
	while (std::getline(database, row))
	{
		comma = row.find(',');
		if (comma == std::string::npos)
			throw std::runtime_error("Bad line format in database");
		date = trim(row.substr(0, comma));
		valueStr = trim(row.substr(comma + 1));
		value = std::atof(valueStr.c_str());
		if (!isValidDate(date))
			throw std::runtime_error("Invalid date in database");
		if (!isValidValue(valueStr))
			throw std::runtime_error("Invalid value in database");
		_database.insert(std::pair<std::string, double>(date, value));
	}
}

bool	BitcoinExchange::checkCSVExtension(std::string const &filename) const
{
	std::string	ext = ".csv";
	if (filename.length() >= ext.length() && filename.compare(filename.length() - ext.length(), ext.length(), ext) == 0)
		return (true);
	return (false);
}

/* isValidDate checks 
	- length of 10 and correct dashes
	- dates are numeric and have the right range (including for leap years)
*/
bool	BitcoinExchange::isValidDate(const std::string &date) const
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return (false);
	for (std::size_t i = 0; i < 10; ++i)
	{
		if (i == 4 || i == 7)
			continue;
		else if (!std::isdigit(date[i]))
			return (false);
	}
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	if (month < 1 || month > 12 || day < 1)
		return (false);
	int daysMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		daysMonth[1] = 29;
	if (day > daysMonth[month - 1])
		return (false);
	return (true);
}

/* isValidValue checks 
	- characters are numeric
	- allow only one dot 
	- invalid if value is empty string or starts/ends with dot
	- invalid if contains '-' so can't have negative values
*/
bool	BitcoinExchange::isValidValue(const std::string &value) const
{
	if (value.empty() || value == "." || value[0] == '.' || value[value.length() - 1] == '.')
		return (false);
	int	dotFlag = 0;
	for (std::size_t i = 0; i < value.length(); ++i)
	{
		if (value[i] == '.')
		{
			if (dotFlag == 0)
				dotFlag = 1;
			else
				return (false);
		}
		else if (!std::isdigit(value[i]))
			return (false);
	}
	return (true);
}

std::string	BitcoinExchange::trim(std::string const &str) const
{
	std::size_t	start = 0;
	while (start < str.length() && std::isspace(str[start]))
		++start;
	std::size_t	end = str.length();
	while (end > start && std::isspace(str[end - 1]))
		--end;
	return (str.substr(start, end - start));
}

void	BitcoinExchange::processInput(std::string const &filename)
{
	std::ifstream	input(filename.c_str());
	if (!input.is_open())
		throw std::runtime_error("Cannot open input file: " + filename);
	std::string row;
	if (!std::getline(input, row) || row != "date | value")
		throw std::runtime_error("Invalid header in input file");
	std::size_t	pipe;
	std::string date;
	std::string valueStr;
	double	value;
	while (std::getline(input, row))
	{
		if (row.empty())
		{
			errorMsg("Error: Bad input => empty line");
			continue;
		}
		pipe = row.find("|");
		if (pipe == std::string::npos)
		{
			errorMsg("Error: Bad input => " + row);
			continue;
		}
		date = trim(row.substr(0, pipe));
		valueStr = trim(row.substr(pipe + 1));
		value = std::atof(valueStr.c_str());
		if (!isValidDate(date))
			errorMsg("Error: Bad input => " + date);
		else if (!isValidValue(valueStr))
			errorMsg("Error: Bad input => " + valueStr);
		else if (value > 1000)
			errorMsg("Error: too large a number.");
		else
			printRate(date, value);	
	}
}

void	BitcoinExchange::printRate(std::string const &date, double &value) const
{
	std::map<std::string, double>::const_iterator	it = _database.lower_bound(date);
	if (it != _database.end() && it->first == date)
		std::cout << date << " => " << value << " = " << it->second * value<< std::endl;
	else if (it != _database.begin())
	{
		--it;
		std::cout << date << " => " << value << " = " << it->second * value << std::endl;
	}
	else
		errorMsg("Error: Date predates database");
}

void	BitcoinExchange::printDatabase(void) const
{
	std::map<std::string, double>::const_iterator	it;
	for (it = _database.begin(); it != _database.end(); ++it)
		std::cout << it->first << ": " << it->second << std::endl;
}