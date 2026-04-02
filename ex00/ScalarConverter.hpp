/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 12:31:26 by julian            #+#    #+#             */
/*   Updated: 2026/03/28 17:42:11 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

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
		ScalarConverter(); // Private constructor -- the class is not meant to be instanciated
		static char _char;
		static int _int;
		static double _double;
		static float _float;

	public:
		ScalarConverter(const ScalarConverter &copy);
		~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &copy);

		static void convert(std::string str);
		void printall(type t, long n);
	

		class NonDisplayableException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

enum type getType(std::string str);
long converting(std::string str);
char toChar(long n);
int toInt(long n);
double toDouble(long n);
float toFloat(long n);
bool hasNonDisplayableChar(std::string str);


#endif
