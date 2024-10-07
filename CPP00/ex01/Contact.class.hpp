#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

#include "phonebook.hpp"

class Contact
{
	public:
		Contact(void);
		Contact(std::string (&input)[5]);
		~Contact(void);
		const std::string&	get_first_name(void) const { return (this->_first_name); }
		const std::string&	get_last_name(void) const { return (this->_last_name); }
		const std::string&	get_nickname(void) const { return (this->_nickname); }
		void	display(void) const;
	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_num;
		std::string	_darkest_secret;
		const std::string&	_get_phone_num(void) const { return (this->_phone_num); }
		const std::string&	_get_darkest_secret(void) const { return (this->_darkest_secret); }
};
#endif