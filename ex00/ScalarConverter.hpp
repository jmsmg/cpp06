#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>

class	ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &scalar);
		ScalarConverter &operator=(const ScalarConverter &scalar);
		~ScalarConverter();

	public:
		static void convert(const std::string &str);
};

#endif