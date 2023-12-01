/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:20:20 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/11/14 12:21:49 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool    isSigned;
        int     gradeSigned;
        int     gradeExecut;
    public:
        Form();
        Form(const std::string &name, int gradeSign, int gradeExec);
        Form(const Form &cpy);
        Form &operator=(const Form &obj);
        ~Form();

        const std::string &getName( void ) const;
        int getIsSigned( void ) const;
        int getGradeSigned( void ) const;
        int getGradeExecute( void ) const;

        void beSigned(const Bureaucrat &obj);
        
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

std::ostream &operator<<(std::ostream &output, const Form &obj);

#endif