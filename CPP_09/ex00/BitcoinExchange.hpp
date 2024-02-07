/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:06:38 by ylamsiah          #+#    #+#             */
/*   Updated: 2024/02/07 18:18:47 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <cstdlib>
# include <iostream>
# include <fstream>
# include <list>
# include <string>
# include <fstream>
# include <sstream>

typedef struct date
{
    int day;
    int month;
    int year;
    date() : day(-1), month(-1), year(-1) {}
} Date;

struct Pair
{
    std::string key;
    std::string value;
};

std::list<Pair> read_second_file(char *file1);
std::list<Pair> read_first_file( void );
bool input_is_valid(std::string input);
float get_date(std::list<Pair> data, std::string input);

#endif