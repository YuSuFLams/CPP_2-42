/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:50:03 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/11/14 10:58:17 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("N/A"), grade(1){}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(const std::string &name, int grade): name(name){setGrade(grade);}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy): name(cpy.getName()) {setGrade(cpy.grade);}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
    if (this != &obj)
        setGrade(obj.getGrade());
    return (*this);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade Is Too High";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade Is Too Low";
}

void Bureaucrat::setGrade(int grade)
{
    try
    {
        if (grade > 150)
            throw Bureaucrat::GradeTooHighException();
        else if (grade < 1)
            throw Bureaucrat::GradeTooLowException();
        else
            this->grade = grade;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }   
}

std::string Bureaucrat::getName( void ) const
{
    return (this->name);
}

int Bureaucrat::getGrade( void ) const
{
    return (this->grade);
}

void Bureaucrat::incrementGrade(int grade)
{
    if (this->grade - grade < 1)
        throw Bureaucrat::GradeTooHighException();
    this->grade -= grade; 
}

void Bureaucrat::decrementGrade(int grade)
{
    if (this->grade + grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade += grade;
}

std::ostream &operator<<(std::ostream &output, const Bureaucrat &obj)
{
    output << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
    return (output);
}