#include "phonebook.hpp"

/**
 * @brief PhoneBook Constructor (no input):number of contacts initialised to 0
 * 
 */
PhoneBook::PhoneBook(void): _num_contact(0)
{
	this->_start();
	return ;
}

/**
 * @brief PhoneBook Destructor
 * 
 */
PhoneBook::~PhoneBook(void)
{
	return ;
}

/**
 * @brief	Prompts user for details on new contact and adds into phonebook
 * 			Replaces 1st contact if new contact is the 9th
 * @return	false if issues with getline (from _prompt_contact)
 * @return	true otherwise
 */

bool	PhoneBook::add_contact(void)
{
	std::string	input[5];
	if (this->_prompt_contact(input) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	Contact	new_contact(input);
	if (_num_contact < 8)
		this->_contacts[this->_num_contact++] = new_contact;
	else
	{
		for (int i = 1; i < 8; ++i)
		{
			this->_contacts[i - 1] = this->_contacts[i];
		}
		this->_contacts[7] = new_contact;
	}
	return (EXIT_SUCCESS);
}

/**
 * @brief 	Displays overview of phonebook
 * 			and prompts for index to search and display
 * @return 	exit status of _search(): false if EOF typed (Ctrl-D)
 */
bool	PhoneBook::display_overview(void) const
{
	std::cout << YELLOW BOLD UNDERLINE << std::setw(10) << std::left << "Index" << "|";
	std::cout << std::setw(10) << std::left << "First Name" << "|";
	std::cout << std::setw(10) << std::left << "Last Name" << "|";
	std::cout << std::setw(10) << std::left << "Nickname" << "|" RESET YELLOW << std::endl;

	for (int i = 0; i < 8; ++i)
	{
		std::cout << std::setw(10) << std::right << i + 1 << "|";
		std::string overview[3] = {this->_contacts[i].get_first_name(), this->_contacts[i].get_last_name(), this->_contacts[i].get_nickname()};
		for (int j = 0; j < 3; ++j)
		{
			if (overview[j].length() > 10)
			{
				overview[j] = overview[j].substr(0, 10);
				overview[j][9] = '.';
			}
			std::cout << std::setw(10) << std::right << overview[j] << "|";
		}
		std::cout << std::endl;
	}
	std::cout << RESET << std::endl;
	return (this->_search());
}

/**
 * @brief Prints usage instructions for phonebook
 * 
 */
void	PhoneBook::_start(void) const
{
	std::cout << std::endl << YELLOW "----- USAGE FOR PHONEBOOK -----" << std::endl;
	std::cout << BOLD "ADD" RESET YELLOW "\tto add contact" << std::endl;
	std::cout << BOLD "SEARCH" RESET YELLOW "\tto search for contact" << std::endl;
	std::cout << BOLD "EXIT" RESET YELLOW "\tto exit phonebook" << std::endl;
	std::cout << "-------------------------------" RESET << std::endl << std::endl;
	return ;
}

/**
 * @brief 	Prompts user for details of contact; 
 * 			does input validation for phone number
 * @param input (array of 5 strings)
 * @return false if issues with getline
 * @return true otherwise
 */
bool	PhoneBook::_prompt_contact(std::string (&input)[5]) const
{
	std::string	prompt[4] = {"last name", "nickname", "phone number", "darkest secret"};

	std::cout << YELLOW BOLD "Please insert first name of contact" RESET << std::endl;
	if (!std::getline(std::cin, input[0]))
	{
		std::cout << RED "Error detected when getting line and exiting..." RESET << std::endl;
		return (EXIT_FAILURE);
	}
	while (input[0].empty())
	{
		std::cout << RED "First name cannot be empty. Please type input." RESET << std::endl;
		if (!std::getline(std::cin, input[0]))
		{
			std::cout << RED "Error detected when getting line and exiting..." RESET << std::endl;
			return (EXIT_FAILURE);
		}
	}
	for (int i = 0; i < 4; ++i)
	{
		std::cout << YELLOW BOLD "What is " << input[0] << "'s " << prompt[i] << "?" RESET << std::endl;
		if (!std::getline(std::cin, input[i + 1]))
		{
			std::cout << RED "Error detected when getting line and exiting..." RESET << std::endl;
			return (EXIT_FAILURE);
		}
		if (i == 2)
        {
            while (input[i + 1].empty() || !PhoneBook::_is_valid_num(input[i + 1]))
            {
                std::cout << RED << input[0] << "'s phone number is invalid or empty. Please enter a valid phone number." RESET << std::endl;
                if (!std::getline(std::cin, input[i + 1]))
                {
                    std::cout << RED "Error detected when getting line and exiting..." RESET << std::endl;
                    return (EXIT_FAILURE);
                }
            }
        }
		else
		{
			while (input[i + 1].empty())
			{
				std::cout << RED << input[0] << "'s " << prompt[i] << " cannot be empty. Please try again." RESET << std::endl;
				if (!std::getline(std::cin, input[i + 1]))
				{
					std::cout << RED "Error detected when getting line and exiting..." RESET << std::endl;
					return (EXIT_FAILURE);
				}
			}
		}
	}
	std::cout << std::endl;
	return (EXIT_SUCCESS);
}

/**
 * @brief 	Prompts for index and validates index
 * 			If not, error message and prompt until valid index given
 * @return false if EOF typed (Ctrl-D)
 * @return true otherwise
 */
bool	PhoneBook::_search(void) const
{
	int	index;

	std::cout << YELLOW BOLD "Which entry (between 1 and 8) would you like to display?" RESET << std::endl;
	while (true)
	{
		std::cin >> index;
        if (std::cin.eof())
		{
			std::cout << RED "Error detected when getting line and exiting..." RESET << std::endl;
			return (EXIT_FAILURE);
		}
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
			std::cout << RED "Please input valid index between 1 and 8." RESET << std::endl;
		}
	}
	return (EXIT_SUCCESS);
}

/**
 * @brief	Function checks if string contains only characters
 * 			that should feature in a phone number
 * @param phone_number const reference to string
 * @return true if string consists of digits, space, + or -
 * @return false otherwise
 */
bool PhoneBook::_is_valid_num(const std::string &phone_number) const {
    for (size_t i = 0; i < phone_number.length(); ++i)
	{
		char c = phone_number[i];
        if (!std::isdigit(c) && c != ' ' && c != '+' && c != '-') {
            return false;
        }
	}
    return true;
}
