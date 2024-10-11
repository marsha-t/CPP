#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
////////////////////////////////////////////////////////
/// ADD validation for permissions in file; empty line in file; 
// tabs and spaces in file 
////////////////////////////////////////////////////////
int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Invalid input" << std::endl;
		return (EXIT_FAILURE);
	}
	
	std::string input[3]; 
	for (int i = 0; i < 3; ++i)
	{
		input[i] = argv[i + 1];
	}
	input[0] += ".replace";
	std::ifstream	input_file(argv[1]);
	if (!input_file.is_open())
	{
		std::cerr << "Error opening " << argv[1] << std::endl;
		return (EXIT_FAILURE);
	}
	std::ofstream	output_file(input[0].c_str(), std::ios::out | std::ios::trunc);
	if (!output_file.is_open())
	{
		input_file.close();
		std::cerr << "Error opening " << input[0] << std::endl;
		return (EXIT_FAILURE);
	}
	std::string	line;
	if (std::getline(input_file, line, '\0')) // don't use while becuase s1 could contain new line also 
	{
		size_t	position = line.find(input[1]);
		while (position != std::string::npos)
		{
			line.erase(position, input[1].length());
			line.insert(position, input[2]);
			position = line.find(input[1], position + input[2].length());
		}
		output_file << line << std::flush;
	}
	else
	{
		std::cerr << input[0] << "is empty" << std::endl;
	}
	input_file.close();
	output_file.close();

	return (EXIT_SUCCESS);
}

