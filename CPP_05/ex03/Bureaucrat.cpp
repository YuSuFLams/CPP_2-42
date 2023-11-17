/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:50:03 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/11/16 00:31:40 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(const std::string &name, int grade): name(name){setGrade(grade);}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy): name(cpy.name), grade(cpy.grade){}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
    if (this != &obj)
        setGrade(obj.getGrade());
    return (*this);
}

void Bureaucrat::incrementGrade(int grade)
{
    if (this->grade - grade < 1)
        throw Bureaucrat::GradeTooHighException();
    this->grade -= grade;
}

void Bureaucrat::setGrade(int grade)
{
    try
    {
        if (grade < 1)
            throw Bureaucrat::GradeTooLowException();
        else if (grade > 150)
            throw Bureaucrat::GradeTooHighException();
        else
            this->grade = grade;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
}

void Bureaucrat::decrementGrade(int grade)
{
    if (this->grade + grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade += grade;
}

const std::string Bureaucrat::getName( void ) const {return this->name;}

int Bureaucrat::getGrade( void ) const {return this->grade;}

const char *Bureaucrat::GradeTooHighException::what() const throw() { return ("Grade Is Too High"); }

const char *Bureaucrat::GradeTooLowException::what() const throw() {return ("Grade Is Too Low"); }

std::ostream &operator<<(std::ostream &output, const Bureaucrat &obj)
{
    output << obj.getName() << " , bureaucrat grade " << obj.getGrade() << "."<< std::endl;
    return (output);
}

void	Bureaucrat::signForm(AForm &obj){
	try
	{
        obj.beSigned(*this);
		std::cout << "\033[0;34m" << this->getName() << "\033[0m signed \033[0;31m" << obj.getName() << "\033[0m" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "\033[0;34m" << this->getName() << "\033[0m couldn't sign \033[0;31m" << obj.getName() << "\033[0m because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form){
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
	
}