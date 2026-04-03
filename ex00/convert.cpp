/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 17:19:43 by jvenkata          #+#    #+#             */
/*   Updated: 2026/04/03 15:53:09 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool nonDisplayableChar(std::string str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
			return (true);
		i++;
	}
	return (false);
}

void toChar(long n)
{	
	if (n < 32 || n >= 127)
		std::cout << "char: Non displayable" << std::endl;
    char c = static_cast<char>(n);
    {
		std::cout << "char: " << c << std::endl;
		std::cout << "int : " << static_cast<int>(c) << std::endl;
        std::cout << "float : " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double : " << static_cast<double>(c) << std::endl;
    }
}

void toInt(long n)
{
	int i = static_cast<int>(n);

	if (n < 32 || n >= 127)
		std::cout << "char: Non displayable" << std::endl;
	else if (n < 0 || n > 127)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(i) << std::endl;
	if (n < INT_MIN || n > INT_MAX)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void toFloat(long n)
{
	float f = static_cast<float>(n);
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void toDouble(long n)
{
	double d = static_cast<double>(n);
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void printspec(type t)
{
    if (t == POSITIVE_INF)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		return ;
	}
	else if (t == NEGATIVE_INF)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return ;
	}
	else if (t == NANF)
	{
        std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return ;
	}
}
long converting(std::string str)
{
	char* end;
	long result = strtol(str.c_str(), &end, 10);
	return result;
}

enum type getType(std::string str)
{
	int i = 0;
	int dot = 0;
	int afterDot = 0;
	int len = str.length();

	if (str.compare("+inff") == 0 || str.compare("+inf") == 0)
		return (POSITIVE_INF);
	else if (str.compare("-inff") == 0 || str.compare("-inf") == 0)
		return (NEGATIVE_INF);
	else if (str.compare("nanf") == 0 || str.compare("nan") == 0)
		return (NANF);
		
	if (str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (dot)
			afterDot++;
		if (str[i] >= '0' && str[i] <= '9')
			;
		else if (str[i] == '.')
			dot = 1;			
		i++;
	}
	if (afterDot && str[str.size()-1] != 'f')
		return (DOUBLE);
	else if (afterDot && str[str.size()-1] == 'f')
		return (FLOAT);
	else if (len == 1)
		return (CHAR);
	else
		return (INT);
}



