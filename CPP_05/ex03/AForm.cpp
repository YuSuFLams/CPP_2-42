/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:40:31 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/11/17 23:40:22 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm():name("N/A"), isSigned(false), gradeSigned(1), gradeExecut(1){}

AForm::~AForm(){}

AForm::AForm(const std::string &name, int gradeSigned, int gradeExecut):name(name), isSigned(false), gradeSigned(gradeSigned), gradeExecut(gradeExecut)
{
    if (this->gradeSigned < 1 || this->gradeSigned < 1)
        throw AForm::GradeTooHighException();
    else if (this->gradeSigned > 150 || this->gradeExecut > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &cpy):name(cpy.getName()), isSigned(cpy.getIsSigned()), gradeSigned(cpy.getGradeSigned()), gradeExecut(cpy.getGradeExecute()) {
    if (this->gradeSigned < 1 || this->gradeSigned < 1)
        throw AForm::GradeTooHighException();
    else if (this->gradeSigned > 150 || this->gradeExecut > 150)
        throw AForm::GradeTooLowException();
    *this = cpy;
}

const std::string AForm::getName( void ) const {return this->name;}

int AForm::getIsSigned( void ) const {return this->isSigned;}

int AForm::getGradeSigned( void ) const {return this->gradeSigned;}

int AForm::getGradeExecute( void ) const {return this->gradeExecut;}

AForm & AForm::operator=(const AForm &obj)
{
    if (this != &obj)
    {
        this->isSigned = obj.getIsSigned();
        this->gradeSigned = obj.getGradeSigned();
        this->gradeExecut = obj.getGradeExecute();
    }
    return (*this);
}

void AForm::beSigned(const Bureaucrat &obj)
{
    if (this->getGradeSigned() >= obj.getGrade())
        this->isSigned = true;
    else
        throw AForm::GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw() { return ("`AForm' : Grade Is Too High"); }

const char *AForm::GradeTooLowException::what() const throw() {return ("`AForm' : Grade Is Too Low"); }

std::ostream &operator<<(std::ostream &output, const AForm &obj)
{
    output << "=================== AForm ==================" << std::endl;
    output << "|| Form name       : " << std::setw(20) << obj.getName() << ".||"<< std::endl;
    output << "|| Grade to sign   : " << std::setw(20) << obj.getGradeSigned() << ".||" << std::endl;
    output << "|| Grade to execute: " << std::setw(20) << obj.getGradeExecute()  << ".||" << std::endl;
    output << "|| Signed          : " << std::setw(21) << ((obj.getIsSigned())? "Is Signed.": "Not Signed.") << "||"<< std::endl;
    output << "============================================"<< std::endl;
    return (output);
}