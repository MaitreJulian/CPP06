/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 17:11:23 by jvenkata          #+#    #+#             */
/*   Updated: 2026/04/03 20:16:24 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>   // std::cout
#include <string>     // std::string, std::stoi
#include "ScalarConverter.hpp"

int main (int argc, char **argv)
{
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <number>" << std::endl;
    return 1;
  }

  std::string number = argv[1];
  try {
    ScalarConverter::convert(number);
  }
  catch (std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
}