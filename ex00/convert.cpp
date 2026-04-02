/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 17:19:43 by jvenkata          #+#    #+#             */
/*   Updated: 2026/03/29 18:57:14 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool hasNonDisplayableChar(std::string str)
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

char toChar(long n)
{	
	if (n < 32 || n >= 127)
		throw ScalarConverter::NonDisplayableException();
    char c = static_cast<char>(n);
    return c;
}

void ScalarConverter::printall(type t, long n)
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
    if (t == CHAR)
    {
		try
		{
			_char = toChar(n);
			std::cout << _char << std::endl;
		}
		catch(std::exception& e)
		{}
        _int = static_cast<int>(_char);
        _double = static_cast<double>(_char);
        _float = static_cast<float>(_char);
    }
    else if (t == INT)
    {
		try{std::cout << toChar(n) << std::endl;}
		catch(std::exception& e){}
        _char = static_cast<char>(n);
        _int = toInt(n);
        _double = static_cast<double>(n);
        _float = static_cast<float>(n);
    }
    else if (t == FLOAT)
    {
		try{std::cout << toChar(n) << std::endl;}
		catch(std::exception& e){}
        _float = std::stof(str);
        _char = static_cast<char>(_float);
        _int = static_cast<int>(_float);
        _double = static_cast<double>(_float);
    }
    else if (t == DOUBLE)
    {
		try{std::cout << toChar(n) << std::endl;}
		catch(std::exception& e){}
        _double = std::stod(str);
        _char = static_cast<char>(_double);
        _int = static_cast<int>(_double);
        _float = static_cast<float>(_double);
    }
}
long converting(std::string str)
{
	char* end;
	long result = std::strtol(str.c_str(), &end, 10);
	if (*end != '\0') 
	{
		throw std::invalid_argument("Invalid integer");
	}
	if (result > INT_MAX || result < INT_MIN) 
	{
		throw std::out_of_range("Out of int range");
	}
	if (hasNonDisplayableChar(str))
		throw ScalarConverter::NonDisplayableException();
	return result;
}

enum type getType(std::string str)
{
	int i = 0;
	int dot = 0;
	int afterDot = 0;
	int hasChar = 0;

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
		else 
			hasChar = 1;
		i++;
	}
	if (afterDot && str.back() != 'f')
		return (DOUBLE);
	else if (afterDot && str.back() == 'f')
		return (FLOAT);
	else if (hasChar)
		return (CHAR);
	else
		return (INT);
}



