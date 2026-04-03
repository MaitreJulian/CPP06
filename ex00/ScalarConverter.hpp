/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 12:31:26 by julian            #+#    #+#             */
/*   Updated: 2026/04/03 20:37:58 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <cmath>
#include <string>

#define INT_MAX 2147483647
#define INT_MIN -2147483648

enum type {
    CHAR = 0,           // Represents the type CHAR
    INT = 1,            // Represents the type INT
    DOUBLE = 2,         // Represents the type DOUBLE
    FLOAT = 3,          // Represents the type FLOAT
    POSITIVE_INF = 4,   // Represents the type POSITIVE_INF
    NEGATIVE_INF = 5,   // Represents the type NEGATIVE_INF
    NANF = 6             // Represents the type NAN
};

class ScalarConverter
{
	private:
		ScalarConverter(); // Private constructor -- the class is not meant to be instantiated

	public:
		ScalarConverter(const ScalarConverter &copy);
		~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &copy);

		static void convert(std::string str);
		
};
	
void printspec(type t);
enum type getType(std::string str);
long converting(std::string str);
void toChar(char c);
void toInt(long n);
void toDouble(double n);
void toFloat(double n);
long toLong(std::string str);

#endif
