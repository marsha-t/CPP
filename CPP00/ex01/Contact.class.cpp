#include "phonebook.hpp"

// think this constructor is necessary for phonebook to construct array in first instance
Contact::Contact(void): first_name(""), last_name(""), nickname(""), phone_num(""), darkest_secret("")
{
	// std::cout << GREEN << "Contact constructed with empty strings" << RESET << std::endl;
	return ;
}

Contact::Contact(std::string *input)
{
	// std::cout << GREEN << "Contact constructed with input array" << RESET << std::endl;
	this->first_name = input[0];
	this->last_name = input[1];
	this->nickname = input[2];
	this->phone_num = input[3];
	this->darkest_secret = input[4];
	return ;
}

Contact::~Contact(void)
{
	// std::cout << GREEN << "Contact destroyed" << RESET << std::endl;
	return ;
}

void	Contact::display(void) const
{
	typedef	const std::string& (Contact::*get_func)() const;
	std::string	field[5] = {"First Name", "Last Name", "Nickname", "Phone Number", "Darkest Secret"};
	get_func memberfunc[5] = {&Contact::get_first_name, &Contact::get_last_name, &Contact::get_nickname, &Contact::get_phone_num, &Contact::get_darkest_secret};
	std::string	temp;

	std::cout << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << YELLOW BOLD << field[i] << ": " << std::flush ;
		temp = (this->*memberfunc[i])();
		if (!temp.empty())
			std::cout << RESET YELLOW << (this->*memberfunc[i])() << std::endl;
		else
			std::cout << RESET YELLOW << "<empty>" << std::endl;
	}
	std::cout << RESET << std::endl;
	return ; 
}