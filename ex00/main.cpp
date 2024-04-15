#include "ScalarConverter.hpp"

int	main()
{
	ScalarConverter::convert("42.0f");
	std::cout << std::endl;
	ScalarConverter::convert("nan");
	std::cout << std::endl;
	ScalarConverter::convert("-inf");
	std::cout << std::endl;
	ScalarConverter::convert("2147483648");
}