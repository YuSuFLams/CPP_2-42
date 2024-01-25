/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:56:47 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/11/23 19:02:08 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **str)
{
    try
    {
        if (ac != 2)
            throw "Invalid Arguments";
        std::string input(str[1]);
        if (input.empty())
            throw "Invalid Arguments";
        ScalarConverter::convert(input);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}