#include "ScalarConverter.hpp"

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		return (1);
	}

	try
	{
		ScalarConverter::convert(argv[1]);
	}
	catch(std::exception &e)
	{
		std::cerr << "error" << std::endl;
	}
}