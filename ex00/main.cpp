/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 17:11:23 by jvenkata          #+#    #+#             */
/*   Updated: 2026/04/02 16:22:39 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>   // std::cout
#include <string>     // std::string, std::stoi
#include "ScalarConverter.hpp"

int main ()
{
  std::string number;

  std::cout << "give a number : char, int, double or float" << std::endl;
  std::cin >> number;
  try {
    ScalarConverter::convert(number);
  }
  catch (std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
}