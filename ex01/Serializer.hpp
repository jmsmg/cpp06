#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>

struct	Data
{
	int data;
};

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &serializer);
		Serializer &operator=(const Serializer &serializer);
		~Serializer();

	public:
		static uintptr_t	serialize(Data *ptr);
		static Data			*deserialize(uintptr_t raw);
};

#endif