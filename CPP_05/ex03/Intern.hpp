/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:20:20 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/11/17 23:06:50 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
    private:
        AForm *PresidentialPardon(const std::string &target) const;
        AForm *RobotomyRequest(const std::string &target) const;
        AForm *ShrubberyCreation(const std::string &target) const;
    public:
        Intern();
        Intern(const Intern &cpy);
        Intern &operator=(const Intern &obj);
         ~Intern();

        AForm *makeForm(const std::string &name, const std::string &target) const;
        
        class FormNotFound : public std::exception
        {
            public:
                const char *what() const throw();
        };
};

#endif