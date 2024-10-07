#include "phonebook.hpp"

/**
 * @brief Contact Constructor (no input): all fields initialised to empty strings
 * 
 */
Contact::Contact(void): _first_name(""), _last_name(""), _nickname(""), _phone_num(""), _darkest_secret("")
{
	return ;
}

/**
 * @brief Contact Constructor: fields initialised using array of 5 strings 
 * 
 * @param input Array of 5 strings
 */
Contact::Contact(std::string (&input)[5]): _first_name(input[0]), _last_name(input[1]), _nickname(input[2]), _phone_num(input[3]), _darkest_secret(input[4])
{
	return ;
}

/**
 * @brief Contact Destructor
 * 
 */
Contact::~Contact(void)
{
	return ;
}

/**
 * @brief Displays contact with one field per line
 * 
 */
void	Contact::display(void) const
{
	typedef	const std::string& (Contact::*get_func)() const;
	std::string	field[5] = {"First Name", "Last Name", "Nickname", "Phone Number", "Darkest Secret"};
	get_func memberfunc[5] = {&Contact::get_first_name, &Contact::get_last_name, &Contact::get_nickname, &Contact::_get_phone_num, &Contact::_get_darkest_secret};

	std::cout << std::endl;
	std::string	temp;
	for (int i = 0; i < 5; ++i)
	{
		std::cout << YELLOW BOLD << field[i] << ": " << std::flush ;
		temp = (this->*memberfunc[i])();
		if (!temp.empty())
			std::cout << RESET YELLOW << (this->*memberfunc[i])() << std::endl;
		else
			std::cout << RESET YELLOW "<empty>" RESET << std::endl;
	}
	std::cout << std::endl;
	return ; 
}
