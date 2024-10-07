#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include "phonebook.hpp"

class	PhoneBook 
{
	public:
		PhoneBook(void);
		~PhoneBook(void);
		bool	add_contact(void);
		bool	display_overview(void) const;
	private:
		Contact	_contacts[8];
		int		_num_contact;
		void	_start(void) const;
		bool	_prompt_contact(std::string (&input)[5]) const;
		bool	_search (void) const;
		bool	_is_valid_num(const std::string &phone_number) const;
};

# endif