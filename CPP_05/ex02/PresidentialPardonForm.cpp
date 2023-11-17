/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 23:52:50 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/11/16 00:58:09 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():
    AForm("PresidentialPardonForm", 25, 5), target("PresidentialPardonForm"){}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm::PresidentialPardonForm(const std::string &name):
    AForm(name, 25, 5), target(name){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cpy):
    AForm(cpy.getName(), cpy.getGradeExecute(), cpy.getGradeSigned()), target(cpy.getTarget()){}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj)
{
    if (this != &obj)
        this->target = obj.getTarget();
    return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (this->getGradeExecute() < executor.getGrade())
        throw PresidentialPardonForm::GradeTooLowException();
    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::string PresidentialPardonForm::getTarget( void ) const{return this->target;}
