#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <fstream>
#include <map>
#include <iostream>
#include <cstdlib>
#include <stdexcept>

void	debugMsg(std::string msg);
void	errorMsg(std::string msg);

class BitcoinExchange
{
	public:
		// Constructor
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &obj);

		// Destructor
		~BitcoinExchange(void);

		// Operators
		BitcoinExchange	&operator=(const BitcoinExchange &obj);
		
		// Other functions
		void	loadDatabase(std::string const &filename);
		void	processInput(std::string const &filename);
		void	printDatabase(void) const;
		
	private:
		std::map<std::string, double> _database;
		
		bool	checkCSVExtension(std::string const &filename) const;
		bool	isValidDate(const std::string &date) const;
		bool	isValidValue(const std::string &value) const;
		std::string	trim(std::string const &str) const;

		void	printRate(std::string const &date, double &value) const;
};

#endif
