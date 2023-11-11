/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:18:35 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/11/11 17:00:56 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form():name("N/A"), isSigned(false), gradeSigned(0), gradeExecut(0){}

Form::~Form(){}

Form::Form(const std::string &name, int gradeSigned, int gradeExecut):name(name)
{
    this->gradeSigned = gradeSigned;
    this->gradeExecut = gradeExecut;
}

Form::Form(const Form &cpy):name(cpy.name){*this = cpy;}

const std::string Form::getName( void ) const {return this->name;}

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


const char *Form::GradeTooHighException::what() const throw() { return ("<Form>: Grade Is Too High"); }

const char *Form::GradeTooLowException::what() const throw() {return ("<Form>: Grade Is Too Low"); }

std::ostream &operator<<(std::ostream &output, const Form &obj)
{
    output << std::endl;
    return (output);
}