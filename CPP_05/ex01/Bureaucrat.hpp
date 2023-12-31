/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:42:19 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/11/14 12:14:41 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <iomanip>
# include <stdexcept>
# include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat &cpy);
        Bureaucrat &operator=(const Bureaucrat &obj);
        Bureaucrat(const std::string &name, int grade);
        ~Bureaucrat();
        
        const std::string &getName( void ) const;
        int getGrade( void ) const;

        void setGrade(int grade);
        void incrementGrade(int grade = 1);
        void decrementGrade(int grade = 1);

        void signForm(Form &obj);

        class GradeTooHighException : public std::exception
        {
            public:
                const char *what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &output, const Bureaucrat &obj);

#endif