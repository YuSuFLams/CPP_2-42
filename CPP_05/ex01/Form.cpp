/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:40:31 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/11/17 16:07:15 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form():name("N/A"), isSigned(false), gradeSigned(1), gradeExecut(1){}

Form::~Form(){}

Form::Form(const std::string &name, int gradeSigned, int gradeExecut):name(name), isSigned(false), gradeSigned(gradeSigned), gradeExecut(gradeExecut)
{
    if (this->gradeSigned < 1 || this->gradeSigned < 1)
        throw Form::GradeTooHighException();
    else if (this->gradeSigned > 150 || this->gradeExecut > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &cpy):name(cpy.getName()), isSigned(cpy.getIsSigned()), gradeSigned(cpy.getGradeSigned()), gradeExecut(cpy.getGradeExecute()) {
    if (this->gradeSigned < 1 || this->gradeSigned < 1)
        throw Form::GradeTooHighException();
    else if (this->gradeSigned > 150 || this->gradeExecut > 150)
        throw Form::GradeTooLowException();
    *this = cpy;
}

const std::string &Form::getName( void ) const {return this->name;}

int Form::getIsSigned( void ) const {return this->isSigned;}

int Form::getGradeSigned( void ) const {return this->gradeSigned;}

int Form::getGradeExecute( void ) const {return this->gradeExecut;}

Form & Form::operator=(const Form &obj)
{
    if (this != &obj)
    {
        this->isSigned = obj.getIsSigned();
        this->gradeSigned = obj.getGradeSigned();
        this->gradeExecut = obj.getGradeExecute();
    }
    return (*this);
}

void Form::beSigned(const Bureaucrat &obj)
{
    if (this->getGradeSigned() >= obj.getGrade())
        this->isSigned = true;
    else
        throw Form::GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw() { return ("`Form' : Grade Is Too High"); }

const char *Form::GradeTooLowException::what() const throw() {return ("`Form' : Grade Is Too Low"); }

std::ostream &operator<<(std::ostream &output, const Form &obj)
{
    output << "=================== Form ===================" << std::endl;
    output << "|| Form name       : " << std::setw(20) << obj.getName() << ".||"<< std::endl;
    output << "|| Grade to sign   : " << std::setw(20) << obj.getGradeSigned() << ".||" << std::endl;
    output << "|| Grade to execute: " << std::setw(20) << obj.getGradeExecute()  << ".||" << std::endl;
    output << "|| Signed          : " << std::setw(21) << ((obj.getIsSigned())? "Is Signed.": "Not Signed.") << "||"<< std::endl;
    output << "============================================"<< std::endl;
    return (output);
}