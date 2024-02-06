/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:04:10 by ylamsiah          #+#    #+#             */
/*   Updated: 2024/02/06 18:26:53 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool isSorted(int ac, char **av)
{
    for (int i = 1; i < ac - 1; i++)
        if (std::atoi(av[i]) > std::atoi(av[i + 1]))
            return false;
    return true;
}

bool isAllDigit(std::string str)
{
    for (size_t i = 0; i < str.length(); i++)
        if (!std::isdigit(str[i]))
            return false;
    return true;
}

void isAllpos(int ac, char **str)
{
    for (int i = 1; i < ac; i++)
    {
        if (std::atoi(str[i]) < 0)
            throw std::invalid_argument("Error: `" + std::string(str[i]) + "' is not a positive number.");
        if (!isAllDigit(str[i]))
            throw std::invalid_argument("Error: `" + std::string(str[i]) + "' is not a number.");
        if (std::atol(str[i]) > INT_MAX)
            throw std::invalid_argument("Error: `" + std::string(str[i]) + "' is too big.");
    }
}
