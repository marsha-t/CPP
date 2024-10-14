#include "Harl.hpp"
#include <iostream>

Harl::Harl(void)
{
	std::cout << "Harl constructed" << std::endl;
	return ;
}

Harl::~Harl(void)
{
	std::cout << "Harl destroyed" << std::endl;
	return ;
}

void	Harl::debug(void)
{
	std::cout << "Debug message" << std::endl;
	return ;
}
void	Harl::info(void)
{
	std::cout << "Info message" << std::endl;
	return ;
}
void	Harl::warning(void)
{
	
	std::cout << "Warning message" << std::endl;
	return ;
}
void	Harl::error(void)
{
	std::cout << "Error message" << std::endl;
	return ;
}

void	Harl::complain(std::string level)
{
	typedef	void (Harl::*func)(void);
	std::string	level_list[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	func		func_list[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	int	i = 0;
	while (i < 4 && level != level_list[i])
		++i;

	switch (i)
	{
		case 0:
			(this->*func_list[0])();
			// fall through
		case 1:
			(this->*func_list[1])();
			// fall through
		case 2:
			(this->*func_list[2])();
			// fall through
		case 3:
			(this->*func_list[3])();
			break ;
		case 4:
			std::cout << "Insignificant message" << std::endl;
		default:
			;
	}
	return ;
}
