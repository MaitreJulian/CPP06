/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 17:19:43 by jvenkata          #+#    #+#             */
/*   Updated: 2026/03/21 19:31:28 by jvenkata         ###   ########.fr       */
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

std::string toChar(long n)
{
    char c = static_cast<char>(n);
    
    if (c < 32 || c > 126)
        return "char : Non displayable"
}

void printall(type t, long n)
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
        std::cout << toChar(n) << std::endl;
        _int = static_cast<int>(_char);
        _double = static_cast<double>(_char);
        _float = static_cast<float>(_char);
    }
    else if (t == INT)
    {
        _char = toChar(result);
        _int = static_cast<int>(result);
        _double = static_cast<double>(result);
        _float = static_cast<float>(result);
    }
    else if (t == FLOAT)
    {
        _float = std::stof(str);
        _char = static_cast<char>(_float);
        _int = static_cast<int>(_float);
        _double = static_cast<double>(_float);
    }
    else if (t == DOUBLE)
    {
        _double = std::stod(str);
        _char = static_cast<char>(_double);
        _int = static_cast<int>(_double);
        _float = static_cast<float>(_double);
    }
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



