#include <iostream>
#include <cctype>
#include <string>
#include <cstdlib>

/**
 * @brief Converts arguments into uppercase
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::string str = argv[i];
			for (std::string::size_type j = 0; j < str.length(); j++)
			{
				std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(str[j])));
			}
		}
		std::cout << std::endl;
	}
	return (EXIT_SUCCESS);
}
