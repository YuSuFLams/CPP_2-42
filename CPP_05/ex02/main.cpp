/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 00:29:08 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/11/18 00:30:07 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    std::cout << "\n*****>> ShrubberyCreationForm <<*****" << std::endl;
    try
    {
        ShrubberyCreationForm from("You");

        Bureaucrat obj("Youssef", 100);
        
        obj.signForm(from);
        
        std::cout << from;

        obj.executeForm(from);

        obj.decrementGrade(110);

        obj.incrementGrade(57);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    std::cout << "\n\n*****>> RobotomyRequestForm <<*****" << std::endl;
    try
    {
        RobotomyRequestForm from("You");

        Bureaucrat obj("Youssef", 35);
        
        obj.signForm(from);
        
        std::cout << from;

        obj.executeForm(from);
        obj.executeForm(from);
        obj.executeForm(from);
        obj.executeForm(from);

        obj.decrementGrade(10);

        obj.incrementGrade(5);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    std::cout << "\n\n*****>> PresidentialPardonForm <<*****" << std::endl;
    try
    {
        PresidentialPardonForm from("You");

        Bureaucrat obj("Youssef", 16);
        
        obj.signForm(from);
        
        std::cout << from;

        obj.executeForm(from);

        obj.decrementGrade(160);

        obj.incrementGrade(36);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    return 0;
}