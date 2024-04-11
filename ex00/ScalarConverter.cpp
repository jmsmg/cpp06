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
	char	*upcase;
	char	*endptr;
	double	value = strtod(str.c_str(), &endptr);

	if ((value == 0.0 && (str[0] != '-' && str[0] != '+' && !std::isdigit(str[0])))
		|| (*endptr && std::strcmp(endptr, "f")))
	{
		throw (std::bad_alloc());
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
	if (value < INT_MIN || INT_MAX < value)
	{
		std::cout << "impossible" << std::endl;
	}
	else
	{
		std::cout << static_cast<int>(value) << std::endl;
	}

	std::cout << "float: ";
	// nan inf 등 처리해야함
	if (value < FLT_MIN || FLT_MAX < value)
	{
		std::cout << "impossible" << std::endl;
	}
	else
	{
		std::cout << static_cast<float>(value) << std::endl;
	}

	std::cout << "double: " << value << std::endl;
}

// nan, nanf -inf, +inf, -inff, +inff 처리,
//함