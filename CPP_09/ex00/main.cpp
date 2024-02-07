/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:19:41 by ylamsiah          #+#    #+#             */
/*   Updated: 2024/02/07 18:18:43 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Usage: ./btc [file]" << std::endl;
        return 1;
    }
    std::list<Pair> data1 = read_first_file();
    std::list<Pair> data = read_second_file(av[1]);
    for (std::list<Pair>::iterator it = data.begin(); it != data.end(); it++)
    {
        std::string input = it->key;
        float value = std::atof(it->value.c_str());
        float thatDate = get_date(data1, input);
        if (!input_is_valid(input))
            std::cout << "Error: bad input => " + input + "." << std::endl;
        else if (value < 0)
            std::cout << "Error: not a positive number."<< std::endl;
        else if (value > 1000)
            std::cout << "Error: too large a number."<< std::endl;
        else
            std::cout << it->key << " => " << it->value << " = " << (thatDate * value) << std::endl;
    }
    return 0;
}