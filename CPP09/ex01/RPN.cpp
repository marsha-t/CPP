#include "RPN.hpp"

RPN::RPN(void)
{
	debugMsg("RPN initialised");
}

RPN::RPN(const RPN &obj)
{
	debugMsg("RPN initialised via copy");
	_tokens = obj._tokens;
}

RPN	&RPN::operator=(const RPN &obj)
{
	if (this != &obj)
	{
		debugMsg("RPN copied via assignment");
		_tokens = obj._tokens;
	}
	return (*this);	
}

RPN::~RPN(void)
{
	debugMsg("RPN destroyed");
}

void	RPN::evaluate(std::string const &exp)
{
	std::istringstream	expression(exp);
	std::string			token;
	std::string			operators = "+-*/";

	while (expression >> token)
	{
		if (token.length() == 1 && isdigit(token[0]))
			_tokens.push(std::atoi(token.c_str()));
		else if (token.length() == 1 && operators.find(token) != std::string::npos)
		{
			if (_tokens.size() < 2)
				throw std::runtime_error("Not enough operands");
			int	b = _tokens.top();
			_tokens.pop();
			int a = _tokens.top();
			_tokens.pop();
			switch (token[0])
			{
				case '+':
				_tokens.push(a + b);
					break;
				case '-':
					_tokens.push(a - b);
					break;
				case '*':
					_tokens.push(a * b);
					break ;
				case '/':
					if (b == 0)
						throw std::runtime_error("Division by zero");
					_tokens.push(a / b);
					break;
			}
		}
		else
			throw std::invalid_argument("Invalid token");
	}
	printResult();
}

void	RPN::printResult(void) const
{
	if (_tokens.size() == 1)
		std::cout << _tokens.top() << std::endl;
	else
		throw std::runtime_error("Invalid expression");
}
