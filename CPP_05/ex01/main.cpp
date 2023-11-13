/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:42:16 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/11/13 13:51:50 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat obj("\033[0;34mAttack\033[0m", 25);
        std::cout << obj;
        Form obj1("You!", 14, 112);
        obj.signForm(obj1);
        std::cout << obj1;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << std::endl;
    
    try
    {
        Bureaucrat obj("\033[0;34mAttack\033[0m", 25);
        std::cout << obj;
        Form obj1("You!.", 14, 162);
        obj.signForm(obj1);
        std::cout << obj1;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
};