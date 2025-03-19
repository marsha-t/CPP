#include "MutantStack.hpp"
#include <iostream>
#include <cstdlib>

void	subjectTests(void)
{
	MutantStack<int>	mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int>s(mstack);
}

void	testMemberFunctions(void)
{
	MutantStack<int>	myStack;
	std::cout << std::boolalpha << "Stack is empty: " << myStack.empty() << std::endl;
	myStack.push(10);
	myStack.push(11);
	myStack.push(12);
	std::cout << "Top of stack: " << myStack.top() << std::endl;
	myStack.pop();
	std::cout << "Stack size: " << myStack.size() << std::endl;
	std::cout << "Top of stack: " << myStack.top() << std::endl;
}

void	testCopy(void)
{
	MutantStack<int>	stack1;
	stack1.push(1);
	std::cout << "Top of stack1: " << stack1.top() << std::endl;
	MutantStack<int>	stack2(stack1);
	std::cout << "Top of stack2: " << stack2.top() << std::endl;
	
	stack2.push(2);
	std::cout << "\nTop of stack2: " << stack2.top() << std::endl;
	std::cout << "Size of stack2: " << stack2.size() << std::endl;

	MutantStack<int>	stack3;
	stack3 = stack2;
	std::cout << "\nTop of stack3: " << stack3.top() << std::endl;
	std::cout << "Size of stack3: " << stack3.size() << std::endl;
}

void	testIterator(void)
{
	MutantStack<int>	myStack;
	myStack.push(10);
	myStack.push(11);
	myStack.push(12);
	for (MutantStack<int>::iterator it = myStack.begin(); it != myStack.end(); ++it)
	{
		std::cout << *it << std::endl;
	}

	const MutantStack<int>	myConstStack = myStack;
	for (MutantStack<int>::const_iterator it = myConstStack.begin(); it != myConstStack.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		int	test = std::atoi(argv[1]);
		if (test < 0 || test > 4)
			return (1);
		switch (test)
		{
			case 0:
				subjectTests();
				break ;
			case 1:
				testMemberFunctions();
				break ;
			case 2:
				testCopy();
				break ;
			case 3:
				testIterator();
				break ;
		}
		return (0);
	}
	return (1);
}

