/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 16:29:13 by jvenkata          #+#    #+#             */
/*   Updated: 2026/03/28 17:53:51 by julian           ###   ########.fr       */
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


void ScalarConverter::convert(std::string str)
{

	type t = getType(str);
    long n = converting(str);
	this->printall(t, n);

}

const char *ScalarConverter::NonDisplayableException::what() const throw()
{
	return "Wrong format, your number has non displayable caracter";
}