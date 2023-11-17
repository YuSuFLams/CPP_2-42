/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 00:10:47 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/11/16 00:39:48 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():
    AForm("ShrubberyCreationForm", 145, 137), target("ShrubberyCreationForm"){}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &name):
    AForm(name, 145, 137), target(name){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy):
    AForm(cpy.getName(), cpy.getGradeExecute(), cpy.getGradeSigned()), target(cpy.getTarget()){}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
    if (this != &obj)
        this->target = obj.getTarget();
    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (this->getGradeExecute() < executor.getGrade())
        throw ShrubberyCreationForm::GradeTooLowException();
    else
    {
        std::string name = executor.getName() + "_shrubbery";
        std::ofstream file(name.c_str());
        if (!file.is_open())
            std::cout << "Cannot Open This " << name << std::endl, exit(EXIT_FAILURE);
        file << "               ,@@@@@@@," << std::endl;
        file << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
        file << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
        file << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
        file << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
        file << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
        file << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
        file << "       |o|        | |         | |" << std::endl;
        file << "       |.|        | |         | |" << std::endl;
        file << "       |o|        | |         | |" << std::endl;
        file << "       |.|        | |         | |" << std::endl;
        file << "     \\/ ._\\//_/__/  ,\\_//___\\/.  \\_//__/_" << std::endl;
        file.close();
    }
}

std::string ShrubberyCreationForm::getTarget( void ) const{return this->target;} 
