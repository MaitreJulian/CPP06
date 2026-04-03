/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 16:29:13 by jvenkata          #+#    #+#             */
/*   Updated: 2026/04/03 20:34:16 by jvenkata         ###   ########.fr       */
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
        if (t == POSITIVE_INF || t == NEGATIVE_INF || t == NANF)
        {
            printspec(t);
            return ;
        }
        if (t == CHAR || t == INT)
        {
            if (t == CHAR)
                toChar(str[0]);
            else if (t == INT)
            {
                long n = toLong(str);
                toInt(n);
            }
        } 
        else if (t == FLOAT || t == DOUBLE)
        {
            double d = strtod(str.c_str(), NULL);
            if (t == FLOAT)
                toFloat(d);
            else if (t == DOUBLE)
                toDouble(d);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

}