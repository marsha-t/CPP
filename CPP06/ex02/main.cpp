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
	return 0;
}

void	identify(Base *p)
{
	std::cout << "Pointer identifier: " << std::flush;
	if (p == 0)
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
		(void) dynamic_cast<A &>(p);
		std::cout << "Class A" << std::endl;
		return ;
	}
	catch (...) {}
	try
	{
		(void) dynamic_cast<B &>(p);
		std::cout << "Class B" << std::endl;
		return ;
	}
	catch (...) {}
	try
	{
		(void) dynamic_cast<C &>(p);
		std::cout << "Class C" << std::endl;
		return ;
	}
	catch (...) {}
	std::cout << "Unknown" << std::endl;
	return ;
}

int	main(void)
{
	Base	*ptr = generate();
	identify(ptr);
	identify(*ptr);
	
	Base	*basePtr = new Base();
	identify(basePtr);
	identify(*basePtr);
	delete basePtr;
	
	identify (0);
	return (EXIT_SUCCESS);
}