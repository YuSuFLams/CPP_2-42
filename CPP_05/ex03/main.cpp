/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 00:29:08 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/11/18 00:31:56 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    try
    {
        Intern intern;
        Bureaucrat obj("Youssef", 1);

        std::cout << "\n\033[96m*****==> PresidentialPardonForm <==*****\033[0m\n" << std::endl;
        AForm *Presidential = intern.makeForm("PresidentialPardonForm", "FIRST");

        obj.executeForm(*Presidential);
        obj.signForm(*Presidential);

        delete Presidential;	

        std::cout << "\n\033[95m*****==> ShrubberyCreationForm <==*****\033[0m\n" << std::endl;
        AForm *Shrubbery = intern.makeForm("ShrubberyCreationForm", "SECOND");

        obj.executeForm(*Shrubbery);
        obj.signForm(*Shrubbery);

        delete Shrubbery;

        std::cout << "\n\033[92m*****==> RobotomyRequestForm <==*****\033[0m\n" << std::endl;
        AForm *Robotomy = intern.makeForm("RobotomyRequestForm", "THIRD");

        obj.executeForm(*Robotomy);
        obj.signForm(*Robotomy);
        obj.executeForm(*Robotomy);
        obj.signForm(*Robotomy);
        obj.executeForm(*Robotomy);

        delete Robotomy;

        std::cout << "\n\033[91m*****==> Extra Case <==*****\033[0m\n" << std::endl;
        AForm *extraform = intern.makeForm("Youssef", "batcat");
        
        delete extraform;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl << std::endl;
    }
    

	return (0);
};