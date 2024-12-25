#include "Serializer.hpp"

int	main(void)
{
	Data	data = {"abc", 42};
	std::cout << "Original: " << &data << std::endl;
	std::cout << "Word: " << data.word << std::endl;
	std::cout << "Number: " << data.num << std::endl;

	uintptr_t	serialized = Serializer::serialize(&data);
	std::cout << "\nSerialized: " << serialized << std::endl;
	
	Data	*deserialized = Serializer::deserialize(serialized);
	std::cout << "\nDeserialized: " << deserialized << std::endl;
	std::cout << "Word: " << deserialized->word << std::endl;
	std::cout << "Number: " << deserialized->num << std::endl;

	if (deserialized == &data)
		std::cout << "\nDeserialized and data address are the same" << std::endl;
	else
		std::cout << "\nDeserialized and data address are different" << std::endl;


	return (EXIT_SUCCESS);
}