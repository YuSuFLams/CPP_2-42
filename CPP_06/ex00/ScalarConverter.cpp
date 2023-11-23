/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:47:33 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/11/23 19:21:12 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &cpy){*this = cpy;}

ScalarConverter::~ScalarConverter(){}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj){(void)obj; return *this;}

bool is_all_digit(std::string s, int flag)
{
    size_t i = 0;
    if (s[i] == '-' || s[i] == '+')
        i++;
    for(; i < s.length() - 1; i++)
        if (!std::isdigit(s[i]) && s[i] != '.')
            return false;
    if (flag == 1)
    {
        if (!std::isdigit(s[s.length() - 1]) && s[s.length() - 1] != 'f' && s[s.length() - 1] != '.')
            return false;
    }
    else if(!std::isdigit(s[s.length() - 1]) && s[s.length() - 1] != '.')
            return false;
    return true;
}

void toChar(std::string s)
{
    if (std::isalpha(s[0]) && s.length() == 1 && std::isprint(s[0]))
    {
        std::cout << "Char  : " << s[0] << std::endl;

        std::cout << "Int   : " << static_cast<int>(s[0]) << std::endl;
        
        std::cout << "Float : " << static_cast<float>(s[0]) << "f" << std::endl;
        
        std::cout << "Double: " << static_cast<double>(s[0]) << std::endl;
    }
    else
        std::cout << "Invalid input For Char" << std::endl;
}

void toInt(std::string input) 
{
    int value = std::atoi(input.c_str());

    char c = static_cast<char>(value);
    
    if (std::isprint(c))
        std::cout << "Char   : " << c << std::endl;
    else
        std::cout << "Char   : Non Displayable" << std::endl;

    std::cout << "Int    : " << static_cast<int>(value) << std::endl;
    std::cout << "Float  : " << static_cast<float>(value) << "f" << std::endl;
    std::cout << "Double : " << static_cast<double>(value) << std::endl;
}

int countComma(const std::string& str)
{
    int count = 0;

    for (size_t i = 0; i < str.length(); i++)
        if (str[i] == '.')
            count++;
    return count;
}

void toFloat(std::string input)
{
    float value = std::stof(input);

    char c = static_cast<char>(value);
    
    if (std::isprint(c))
        std::cout << "Char   : " << c << std::endl;
    else
        std::cout << "Char   : Non Displayable" << std::endl;

    std::cout << "Int    : " << static_cast<int>(value) << std::endl;
    std::cout << "Float  : " << static_cast<float>(value) << "f" << std::endl;
    std::cout << "Double : " << static_cast<double>(value) << std::endl;
}

void toDouble(std::string input)
{
    double value = std::stod(input);

    char c = static_cast<char>(value);
    
    if (std::isprint(c))
        std::cout << "Char   : " << c << std::endl;
    else
        std::cout << "Char   : Non Displayable" << std::endl;

    std::cout << "Int    : " << static_cast<int>(value) << std::endl;
    std::cout << "Float  : " << static_cast<float>(value) << "f" << std::endl;
    std::cout << "Double : " << static_cast<double>(value) << std::endl;
}

bool SpecialInput(std::string input)
{
    std::string array[6] = {"-inf", "-inff", "+inf", "+inff", "nan", "nanf"};

    for(size_t i = 0; i < 6; i++)
        if (!input.compare(array[i]))
            return true;
    return false;
}

void ScalarConverter::convert(const std::string &str)
{
    if (SpecialInput(str) == true)
    {
        std::cout << "Char   : Impossible" << std::endl;
        std::cout << "Int    : Impossible" << std::endl;
        std::cout << "Float  : " << str << "f" << std::endl;
        std::cout << "Double : " << str << std::endl;
    }
    else if (is_all_digit(str, 0) && countComma(str) == 0)
        toInt(str);
    else if (is_all_digit(str, 1) && countComma(str) < 2)
        toFloat(str);
    else if (is_all_digit(str, 0) && countComma(str) < 2)
        toDouble(str);
    else if (str.length() == 1 && countComma(str) == 0)
        toChar(str);
    else
        throw ScalarConverter::InvalidInput();
}

const char *ScalarConverter::InvalidInput::what() const throw()
{
    return "Invalid Input To Converter (>_<)!";
}