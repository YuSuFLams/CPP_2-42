/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:42:32 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/11/17 17:30:02 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){}

Intern::Intern(const Intern &cpy){*this = cpy;}

Intern &Intern::operator=(const Intern &obj)
{
    (void)obj;
    return (*this);
}

Intern::~Intern(){}

AForm *Intern::PresidentialPardon(const std::string &target) const
{
    return (new PresidentialPardonForm(target));
}

AForm *Intern::RobotomyRequest(const std::string &target) const
{
    return (new RobotomyRequestForm(target));
}

AForm *Intern::ShrubberyCreation(const std::string &target) const
{
    return (new ShrubberyCreationForm(target));
}

const char *Intern::FormNotFound::what() const throw(){return "Intern : Not Found A Form";}

AForm* Intern::makeForm(std::string name, std::string target)
{
    AForm* (Intern::*func[])(std::string const &target) const = {
        &Intern::PresidentialPardon, 
        &Intern::RobotomyRequest,
        &Intern::ShrubberyCreation
    };


    std::string array[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

    for(int i = 0; i < 3; i++)
        if (name == array[i])
            return (this->*func[i])(target);
    throw Intern::FormNotFound();
}
