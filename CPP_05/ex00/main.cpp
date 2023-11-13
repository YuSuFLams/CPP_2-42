/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:54:06 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/11/13 12:31:09 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat obj("Youssef", 20);
        
        std::cout << obj;
        obj.incrementGrade(41);
        std::cout << obj;
        obj.decrementGrade(3);
        std::cout << obj;
        obj.decrementGrade();
        std::cout << obj;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}