#include "phonebook.hpp"

PhoneBook::PhoneBook(void): _num_contact(0)
{
	// std::cout << GREEN << "PhoneBook constructed" << RESET << std::endl;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	// std::cout << GREEN << "PhoneBook destroyed" << RESET << std::endl;
	return ;
}

/**
 * @brief Prints usage instructions for phonebook
 * 
 */
void	PhoneBook::start(void) const
{
	std::cout << std::endl << YELLOW << "----- USAGE FOR PHONEBOOK -----" << std::endl;
	std::cout << BOLD << "ADD" << RESET YELLOW << "\tto add contact" << std::endl;
	std::cout << BOLD << "SEARCH" << RESET YELLOW << "\tto search for contact" << std::endl;
	std::cout << BOLD << "EXIT" << RESET YELLOW << "\tto exit phonebook" << std::endl;
	std::cout << "-------------------------------" << RESET << std::endl << std::endl;
}

/**
 * @brief	Prompts user for details on new contact and adds into phonebook
 * 			Replaces 1st contact if new contact is the 9th
 */
void	PhoneBook::add_contact(void)
{
	std::string	prompt[4] = {"last name", "nickname", "phone number", "darkest secret"};
	std::string	input[5];

	std::cout << YELLOW BOLD << "Please insert first name of contact" << RESET << std::endl;
	getline(std::cin, input[0]);
	while (input[0].empty())
	{
		std::cout << RED << "First name" << " cannot be empty. Please type input." << RESET << std::endl;
		getline(std::cin, input[0]);
	}
	for (int i = 0; i < 4; i++)
	{
		std::cout << YELLOW BOLD << "What is " << input[0] << "'s " << prompt[i] << "?" << RESET << std::endl;
		getline(std::cin, input[i + 1]);
		while (input[i + 1].empty())
		{
			std::cout << RED << input[0] << "'s " << prompt[i] << " cannot be empty. Please try again." << RESET << std::endl;
			getline(std::cin, input[i + 1]);
		}
	}
	std::cout << std::endl;
	Contact	new_contact(input);
	if (_num_contact < 8)
	{
		this->_contacts[_num_contact] = new_contact;
		_num_contact++;
	}
	else
	{
		this->_contacts[0] = new_contact;
		_num_contact = 1;
	}
	return ;
}

/**
 * @brief 	Displays overview of phonebook
 * 			and prompts for index to search and display
 */
void	PhoneBook::display_overview(void) const
{
	std::cout << YELLOW BOLD UNDERLINE << std::setw(10) << std::left << "Index" << "|";
	std::cout << std::setw(10) << std::left << "First Name" << "|";
	std::cout << std::setw(10) << std::left << "Last Name" << "|";
	std::cout << std::setw(10) << std::left << "Nickname" << "|" << RESET YELLOW << std::endl;

	for (int i = 0; i < 8; i++)
	{
		std::cout << std::setw(10) << std::right << i + 1 << "|";
		
		std::string overview[3] = {this->_contacts[i].get_first_name(), this->_contacts[i].get_last_name(), this->_contacts[i].get_nickname()};
		for (int j = 0; j < 3; j++)
		{
			if (overview[j].length() > 10)
			{
				overview[j] = overview[j].substr(0, 10);
				overview[j][9] = '.'; // check how this works with an exact 10 char len
			}
			std::cout << std::setw(10) << std::right << overview[j] << "|";
		}
		std::cout << std::endl;
	}
	std::cout << RESET << std::endl;
	this->_search();
	return ;
}

/**
 * @brief 	Prompts for index and validates index
 * 			If not, error message and prompt until valid index given
 */
void	PhoneBook::_search(void) const
{
	int	index;

	std::cout << YELLOW BOLD << "Which entry (between 1 and 8) would you like to display?" << RESET << std::endl;
	while (true)
	{
		std::cin >> index;
		if (index > 0 && index < 9)
		{
			std::cin.ignore();
			_contacts[index - 1].display();
			break ;
		}
		else
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << RED << "Please input valid index between 1 and 8" << RESET << std::endl;
		}
	}
	return ;
}