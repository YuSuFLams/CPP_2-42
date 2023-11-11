/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:10:12 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/11/11 16:55:23 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool isSigned;
        int gradeSigned;
        int gradeExecut;
    public:
        Form();
        Form(const std::string &name, int gradeSigned, int gradeExecut);
        Form(const Form &cpy);
        Form &operator=(const Form &obj);
        ~Form();

        const std::string getName( void ) const;
        int getIsSigned( void ) const;
        int getGradeSigned( void ) const;
        int getGradeExecute( void ) const;

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

        void beSigned(const Bureaucrat &obj);
};

std::ostream &operator<<(std::ostream &output, const Form &obj);

#endif