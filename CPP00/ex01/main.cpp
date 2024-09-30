#include "phonebook.hpp"

int	main(void)
{
	PhoneBook pb;
	std::string	command;
	pb.start();
	while (1)
	{
		std::cout << YELLOW BOLD << "Type your command" << RESET << std::endl;
		std::getline(std::cin, command);
		std::cout << std::endl;
		if (command.compare("ADD") == 0)
			pb.add_contact();
		else if (command.compare("SEARCH") == 0)
			pb.display_overview();
		else if (command.compare("EXIT") == 0)
			return (0);
		else
			std::cout << RED << "Invalid command: This phonebook only supports ADD, SEARCH and EXIT" << RESET << std::endl;
		std::cin.clear();
	}
	return (EXIT_SUCCESS);
}