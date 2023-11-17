/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:08:24 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/11/17 15:54:20 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat obj("Youssef", 14);
        std::cout << obj;
        obj.incrementGrade(13);
        std::cout << obj;
        obj.incrementGrade(12);
        std::cout << obj;
        obj.decrementGrade();
        std::cout << obj;
        obj.decrementGrade(149);
        std::cout << obj;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}