#include "phonebook.hpp"

/**
 * @brief Print signal number and then exit program
 * 
 * @param signum Signal number
 */
void	signal_handler(int signum)
{
	std::cout << RED "\n Signal received " << signum << " and exiting..." RESET << std::endl;
	exit(signum);
}

int	main(void)
{
	signal(SIGINT, signal_handler);

	PhoneBook pb;
	std::string	command;
	while (1)
	{
		std::cout << YELLOW BOLD "Type your command"  RESET << std::endl;
		if (!std::getline(std::cin, command))
		{
			std::cout << RED "Error detected when getting line and exiting..." RESET << std::endl;
			return (EXIT_FAILURE);
		}
		std::cout << std::endl;
		if (command == "ADD")
		{
			if (pb.add_contact() == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		else if (command == "SEARCH")
		{
			if (pb.display_overview() == EXIT_FAILURE)
				return (EXIT_FAILURE);
		} 
		else if (command == "EXIT")
			return (EXIT_SUCCESS);
		else
			std::cout << RED "Invalid command: This phonebook only supports ADD, SEARCH and EXIT" RESET << std::endl;
	}
	return (EXIT_SUCCESS);
}