#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>

class	ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &scalar);
		ScalarConverter &operator=(const ScalarConverter &scalar);
		~ScalarConverter();
		static void convert(const std::string &str);
};

#endif