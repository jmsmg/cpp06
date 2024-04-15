#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &scalar)
{
	*this = scalar;
	std::cout << "copy constructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &scalar)
{
	*this = scalar;
	std::cout << "copy assignment operator called" << std::endl;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "default destructor called" << std::endl;
}

void	ScalarConverter::convert(const std::string &str)
{
	char	*endptr;
	double	value = strtod(str.c_str(), &endptr);
	int		value_int = static_cast<int>(value);

	if (str.c_str() == endptr)
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
	if (value < INT_MIN || INT_MAX < value || isnan(value) || isinf(value))
	{
		std::cout << "impossible" << std::endl;
	}
	else
	{
		std::cout << value_int << std::endl;
	}

	std::cout << "float: ";
	// nan inf 등 처리해야함
	if (value_int == value)
	{
		std::cout << static_cast<float>(value) << ".0f" << std::endl;
	}
	else if (!isinf(value) && !isnan(value) && (value < FLT_MIN || FLT_MAX < value))
	{
		std::cout << "impossible" << std::endl;
	}
	else
	{
		std::cout << static_cast<float>(value) << "f" << std::endl;
	}

	std::cout << "double: ";
	if (value_int == value)
	{
		std::cout << value << ".0" << std::endl;
	}
	else if (isinf(value) || isnan(value))
	{
		std::cout << value << std::endl;
	}
	else
	{
		std::cout << value << ".0" << std::endl;
	}

}