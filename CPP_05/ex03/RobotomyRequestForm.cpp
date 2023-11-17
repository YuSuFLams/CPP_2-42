/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 00:10:47 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/11/16 00:28:56 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():
    AForm("RobotomyRequestForm", 72, 45), target("RobotomyRequestForm"){}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm::RobotomyRequestForm(const std::string &name):
    AForm(name, 72, 45), target(name){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy):
    AForm(cpy.getName(), cpy.getGradeExecute(), cpy.getGradeSigned()), target(cpy.getTarget()){}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
    if (this != &obj)
        this->target = obj.getTarget();
    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (this->getGradeExecute() < executor.getGrade())
        throw RobotomyRequestForm::GradeTooLowException();
    else
    {
        static int i;
        if (!(i & 1))
            std::cout << this->target << " has been robotomized successfully." << std::endl;
        else
            std::cout << this->target << " has not been robotomized." << std::endl;
    }
}

std::string RobotomyRequestForm::getTarget( void ) const{return this->target;} 