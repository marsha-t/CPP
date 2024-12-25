#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Ex01.hpp"

class Serializer
{
	public:
		static uintptr_t serialize(Data *ptr);
		static Data	*deserialize(uintptr_t raw);

	private:
		Serializer(void);
		Serializer(const Serializer &obj);
		~Serializer(void);
		Serializer &operator=(const Serializer &obj);
};
#endif
