#include "Serializer.hpp"

int	main()
{
	Data		first;
	uintptr_t	tmp;
	Data		*obj;

	first.data = 42;
	tmp = Serializer::serialize(&first);
	obj = Serializer::deserialize(tmp);

	std::cout << obj->data << std::endl;
}