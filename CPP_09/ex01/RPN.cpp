/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 03:48:07 by ylamsiah          #+#    #+#             */
/*   Updated: 2024/02/05 05:42:39 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool checkInput(std::string input)
{
    std::string specialChar = "+-/*";

    for (size_t i = 0; i < input.length(); i++)
    {
        if (!std::isdigit(input[i]) && input[i] != ' ' && \
        specialChar.find(input[i]) == std::string::npos)
            return false;
    }
    return true;
}

bool checkInput1(std::string str)
{
    char* input = std::strtok(const_cast<char*>(str.c_str()), " ");
    while (input)
    {
        if (std::strlen(input) > 1)
            return false;
        input = std::strtok(NULL, " ");
    }
    return true;
}

int calcul(int a, int b, char op)
{
    switch(op)
    {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0)
                throw std::invalid_argument("Error: Division by zero");
            return a / b;
    }
    return 0;
}

void polishCalculate(std::string input)
{
    if (!checkInput(input) || !checkInput1(input))
    {
        throw std::invalid_argument("Error: Invalid input");
    }

    std::stack<int> stack;
    
    for (size_t i = 0; i < input.length(); i++)
    {
        if (input[i] == ' ')
            continue ;
        if (std::isdigit(input[i]))
        {
            stack.push(input[i] - '0');
        }
        else
        {
            if (stack.size() < 2)
                throw std::invalid_argument("Error: Invalid input");
            int b = stack.top();
            stack.pop();
            int a = stack.top();
            stack.pop();
            stack.push(calcul(a, b, input[i]));
        }
    }
    if (stack.size() != 1)
        throw std::invalid_argument("Error: Invalid Operation");
    std::cout << stack.top() << std::endl;
}
