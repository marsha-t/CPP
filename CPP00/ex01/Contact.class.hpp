#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

#include "phonebook.hpp"

class Contact
{
	public:
		Contact(void);
		Contact(std::string *input);
		~Contact(void);
		const std::string&	get_first_name(void) const { return (this->first_name); }
		const std::string&	get_last_name(void) const { return (this->last_name); }
		const std::string&	get_nickname(void) const { return (this->nickname); }
		const std::string&	get_phone_num(void) const { return (this->phone_num); }
		const std::string&	get_darkest_secret(void) const { return (this->darkest_secret); }
		void	display(void) const;
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_num;
		std::string	darkest_secret;
};
#endif