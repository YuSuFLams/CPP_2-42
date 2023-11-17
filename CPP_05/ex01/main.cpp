/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:08:24 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/11/17 16:07:32 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
    std::cout << "\n=****==> First Test <==***=\n" << std::endl;
    try
    {
        Bureaucrat obj("\033[0;34mAttack\033[0m", 25);
        std::cout << obj;
        Form obj1("You!", 114, 112);
        obj.signForm(obj1);
        std::cout << obj1;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=****==> Second Test <==***=\n" << std::endl;
    
    try
    {
        Bureaucrat obj("\033[0;34mAttack\033[0m", 25);
        std::cout << obj;
        Form obj1("You!.", 14, 12);
        obj.signForm(obj1);
        std::cout << obj1;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
};