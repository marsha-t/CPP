#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include "phonebook.hpp"

class	PhoneBook 
{
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	start(void) const;
		void	add_contact(void);
		void	display_overview(void) const;
	private:
		Contact	_contacts[8];
		int	_num_contact;
		void	_search (void) const;
};

# endif