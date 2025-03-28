#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <string>
#include <cstdlib>

void	debugMsg(std::string msg);
void	errorgMsg(std::string msg);

class RPN
{
	private:
		std::stack<int>	_tokens;
		void	printResult(void) const;
	public:
		RPN(void);
		RPN(const RPN &obj);
		RPN	&operator=(const RPN &obj);
		~RPN(void);
		void	evaluate(std::string const &exp);
};

#endif