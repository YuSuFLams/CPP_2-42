/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:55:49 by ylamsiah          #+#    #+#             */
/*   Updated: 2024/02/07 18:18:53 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::list<Pair> read_second_file(char *file1)
{
    std::ifstream file(file1);
    if (!file.is_open())
    {
        std::cerr << "Error: Can't open file" << std::endl;
        exit (1);
    }
    std::list<Pair>  data;
    std::string line;
    std::getline(file, line);
    line.erase(0, line.find_first_not_of(" \t\n\r\f\v"));
    line.erase(line.find_last_not_of(" \t\n\r\f\v") + 1);
    if (line != "date | value")
    {
        std::cerr << "Error: Invalid file" << std::endl;
        exit (1);
    }
    while (std::getline(file, line))
    {
        Pair p;
        p.key = line.substr(0, line.find(" "));
        p.key.erase(0, p.key.find_first_not_of(" \t\n\r\f\v"));
        p.key.erase(p.key.find_last_not_of(" \t\n\r\f\v") + 1);
        p.value = line.substr(line.find("|") + 1);
        p.value.erase(0, p.value.find_first_not_of(" \t\n\r\f\v"));
        p.value.erase(p.value.find_last_not_of(" \t\n\r\f\v") + 1);
        if (p.value == p.key)
            p.value = "";  
        data.push_back(p);
    }
    file.close();
    return data;
}

std::list<Pair> read_first_file( void )
{
    std::ifstream file("data.csv");
    if (!file.is_open())
    {
        std::cout << "Error: Can't open file" << std::endl;
        exit (1);
    }
    std::list<Pair>  data;
    std::string line;
    std::getline(file, line);
    line.erase(0, line.find_first_not_of(" \t\n\r\f\v"));
    line.erase(line.find_last_not_of(" \t\n\r\f\v") + 1);
    if (line != "date,exchange_rate")
    {
        std::cout << "Error: Invalid file" << std::endl;
        exit (1);
    }
    while (std::getline(file, line))
    {
        Pair p;
        p.key = line.substr(0, line.find(","));
        p.key = p.key.substr(0, p.key.find(" \t\n\r\f\v"));
        p.key = p.key.substr(0, p.key.find_last_not_of(" \t\n\r\f\v") + 1);
        p.value = line.substr(line.find(",") + 1);
        p.value = p.value.substr(0, p.value.find(" \t\n\r\f\v"));
        p.value = p.value.substr(0, p.value.find_last_not_of(" \t\n\r\f\v") + 1);
        data.push_back(p);
    }
    file.close();
    return data;
}

bool input_is_valid(std::string input)
{
    if (input < "2009-01-02" || input > "2022-03-29" || input.size() != 10 \
    || input[4] != '-' || input[7] != '-')
        return false;
    std::list<Date> date;
    std::istringstream ss(input);
    std::string input1;
    while (getline(ss, input1, '-'))
    {
        Date d;
        if (input1.size() != 4)
            d.year = std::atof(input1.c_str());
        if (input1.size() != 0)
            d.year = std::atof(input1.c_str());
        getline(ss, input1, '-');
        if (input1.size() != 0)
            d.month = std::atof(input1.c_str());
        getline(ss, input1, '-');
        if (input1.size() != 0)
            d.day = std::atof(input1.c_str());
        date.push_back(d);
    }
    if (date.front().year == -1 || date.front().month == -1 || date.front().day == -1)
        return false;
    if (date.front().year < 2009 || date.front().year > 2022)
        return false;
    if (date.front().month < 1 || date.front().month > 12)
        return false;
    int month = date.front().month;
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        if (date.front().day < 1 || date.front().day > 31)
            return false;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (date.front().day < 1 || date.front().day > 30)
            return false;
    }
    else if (month == 2)
    {
        if (date.front().year % 4 == 0)
        {
            if (date.front().day < 1 || date.front().day > 29)
                return false;
        }
        else
        {
            if (date.front().day < 1 || date.front().day > 28)
                return false;
        }
    }
    return true;
}

float get_date(std::list<Pair> data, std::string input)
{
    float thatDate;
    std::list<Pair>::iterator it = data.begin();
    while (it != data.end())
    {
        if (it->key <= input)
            thatDate = std::atof(it->value.c_str());
        it++;
    }
    return thatDate;
}
