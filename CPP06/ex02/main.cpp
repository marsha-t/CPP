#include "Ex02.hpp"
#include "Base.hpp"
#include "Derived.hpp"

Base	*generate(void)
{
	std::srand(time(0));
	int	num = std::rand() % 3;

	switch (num)
	{
		case 0:
		{
			std::cout << "Create A" << std::endl;
			return (new A());
		}
		case 1:
		{
			std::cout << "Create B" << std::endl;
			return (new B());
		}
		case 2:
		{
			std::cout << "Create C" << std::endl;
			return (new C());
		}
	}
	return NULL;
}

void	identify(Base *p)
{
	std::cout << "Pointer identifier: " << std::flush;
	if (p == NULL)
		std::cout << "Null pointer" << std::endl;
	else if (dynamic_cast<A *>(p))
		std::cout << "Class A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Class B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Class C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void	identify(Base &p)
{
	std::cout << "Reference identifier: " << std::flush;
	try 
	{
		dynamic_cast<A &>(p);
		std::cout << "Class A" << std::endl;
	}
	catch (...) {}
	try
	{
		dynamic_cast<B &>(p);
		std::cout << "Class B" << std::endl;
	}
	catch (...) {}
	try
	{
		dynamic_cast<C &>(p);
		std::cout << "Class C" << std::endl;
	}
	catch (...) {}
	std::cout << "Unknown" << std::endl;
}

int	main(void)
{
	Base *ptr = generate();
	identify(ptr);
	identify(*ptr);
	return (EXIT_SUCCESS);
}