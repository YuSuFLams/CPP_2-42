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

Bureaucrat::Bureaucrat() : name("N/A"), grade(1) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy): name(cpy.getName()) {setGrade(cpy.grade);}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
    if (this != &obj)
        setGrade(obj.getGrade());
    return (*this);
}

const char *Bureaucrat::GradeTooHighException::what() const throw() { return "Grade too high";}

const char *Bureaucrat::GradeTooLowException::what() const throw() { return "Grade too low";}

void        Bureaucrat::setGrade(int grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->grade = grade;
}

std::string const &Bureaucrat::getName() const { return this->name; }

int         Bureaucrat::getGrade() const { return this->grade; }

void Bureaucrat::incrementGrade(int grade)
{
    if (this->grade - grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else
        this->grade -= grade;
}

void Bureaucrat::decrementGrade(int grade)
{
    if (this->grade + grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->grade += grade;
}

std::ostream &operator<<(std::ostream &output, const Bureaucrat &obj)
{
    output << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
    return (output);
}