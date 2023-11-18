/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 03:34:17 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/11/18 05:24:19 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(int ac, char **str)
{
    std::cout << "\n\033[96m****** First Test ******\n" << std::endl;
    try
    {
        if (ac != 2) {
            std::cout << "Please give me a correct number as an argument." << std::endl;
            return 1;
        }
        int N = std::atoi(str[1]);
        if (N > 10000 || N < 0) {
            std::cout << "Your Number Must Be Not Greater Than 10000 Or Less 0." << std::endl;
            return 1;
        }
        
        Span span(N);
        
        for (int i = 0; i < N; i++)
            span.addNumber(N * (2 + i));
        
        std::cout << "Longest Integer :" << span.longestSpan() << std::endl;
        std::cout << "Shortest Integer :" << span.ShortestSpan() << std::endl<< std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    std::cout << "\n\033[93m****** Second Test ******\n" << std::endl;
    try
    {
        std::vector<int> cont;

        Span sp(10000);
        for(int i = 0; i < 10000; i++)
            sp.addNumber(i * 2);
           
        std::cout << "Longest Integer :" << sp.longestSpan() << std::endl;
        std::cout << "Shortest Integer :" << sp.ShortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }


    std::cout << "\n\033[95m****** Third Test ******\n" << std::endl;
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.ShortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    
    std::cout << "\n\033[94m****** Fourth Test ******\n" << std::endl;
    try
    {
        Span sp(1);
        
        sp.addNumber(12);
        sp.addNumber(1);

        std::cout << "Longest Integer :" << sp.longestSpan() << std::endl;
        std::cout << "Shortest Integer :" << sp.ShortestSpan() << std::endl<< std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}