#include "whatever.hpp"

testClass::testClass(void): _value(0) {}

testClass::testClass(int value): _value(value) {}

testClass::testClass(const testClass &obj): _value(obj.getValue()) {}

testClass::~testClass(void) {}

testClass	&testClass::operator=(const testClass &obj)
{
	if (this != &obj)
	{
		_value = obj.getValue();
	}
	return (*this);
}

bool	testClass::operator>(const testClass &obj) const
{
	return (_value > obj.getValue());
}

bool	testClass::operator<(const testClass &obj) const
{
	return (_value < obj.getValue());
}

bool	testClass::operator<=(const testClass &obj) const
{
	return (!(*this > obj));
}

bool	testClass::operator>=(const testClass &obj) const
{
	return (!(*this < obj));
}

int	testClass::getValue(void) const
{
	return (_value);
}

void	subjectTests(void)
{
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}

void	classTest(void)
{
	testClass	a = testClass(42);
	testClass	b = testClass(21);
	std::cout << "Before: a = " << a.getValue() << ", b = " << b.getValue() << std::endl;
	::swap(a, b);
	std::cout << "After: a = " << a.getValue() << ", b = " << b.getValue() << std::endl;
	std::cout << "min (a, b) = " << ::min(a, b).getValue() << std::endl;
	std::cout << "max (a, b) = " << ::max(a, b).getValue() << std::endl;
}

int	main (int argc, char **argv)
{
	if (argc == 2)
	{
		int	test = atoi(argv[1]);
		switch (test)
		{
			case 0:
			{
				subjectTests();
				break ;
			}
			case 1:
			{
				classTest();
				break ;
			}
		}
	}
	return (EXIT_SUCCESS);
}
