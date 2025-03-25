#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <fstream>

void	debugMsg(std::string msg)

class BitcoinExchange:
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
		bool	loadDatabase(std::string const &filename);
		double	getRate(std::string const &date) const;


	private:
		std::map<std::string, double> _database;
};

#endif
