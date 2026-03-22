/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 16:29:13 by jvenkata          #+#    #+#             */
/*   Updated: 2026/03/21 19:23:48 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int ScalarConverter::_int = 0;
char ScalarConverter::_char = '\0';
float ScalarConverter::_float = 0.0f;
double ScalarConverter::_double = 0.0;

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

const char* ScalarConverter::NonDisplayableException::what() const throw()
{
	return("Error! You typed not displaylable character!\n");
}


void ScalarConverter::convert(std::string str)
{

	type t = getType(str);
    try
    {
        char* end;
        long result = std::strtol(str.c_str(), &end, 10);
        if (*end != '\0') {
            throw std::invalid_argument("Invalid integer");
        }
        if (result > INT_MAX || result < INT_MIN) {
            throw std::out_of_range("Out of int range");
        }

	}
        
 
	else
	std::cout << "char: " << _char << std::endl;
	std::cout << "int: " << _int << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: " << _float << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double: " << _double << std::endl;
}