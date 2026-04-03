/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 16:29:13 by jvenkata          #+#    #+#             */
/*   Updated: 2026/04/03 14:57:09 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarCoverter Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	*this = copy;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarCoverter Destructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
	if (this != &copy)
		*this = copy;
	return (*this);
}


void ScalarConverter::convert(std::string str)
{

    try
    {
     	type t = getType(str);
        long n = converting(str);
        if (t == CHAR)
            toChar(n);
        else if (t == INT)
            toInt(n);
        else if (t == FLOAT)
            toFloat(n);
        else if (t == DOUBLE)
            toDouble(n);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

}

const char *ScalarConverter::NonDisplayableException::what() const throw()
{
	return "Wrong format, your number has non displayable caracter";
}