#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &scalar)
{
	std::cout << "copy constructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &scalar)
{
	std::cout << "copy assignment operator called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "default destructor called" << std::endl;
}

void	ScalarConverter::convert(const std::string &str)
{
	char	*endptr;
	double	value = strtod(str.c_str(), &endptr);

	if (endptr == str)
	{
		std::cout << "conversion is impossible" << std::endl;
		return ;
	}

	std::cout << "char: ";
	if (0 <= value && value <= 127)
	{
		if (32 <= value && value <= 126)
		{
			std::cout << '\'' << static_cast<char>(value) << '\'' << std::endl;
		}
		else
			std::cout << "Non displayable" << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;

	std::cout << "int: ";
	
	std::cout << "float: ";

	std::cout << "double: ";
}

// nan, nanf -inf, +inf, -inff, +inff 처리,
// 