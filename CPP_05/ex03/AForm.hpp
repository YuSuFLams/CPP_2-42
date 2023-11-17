/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:20:20 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/11/16 00:45:36 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool    isSigned;
        int     gradeSigned;
        int     gradeExecut;
    public:
        AForm();
        AForm(const std::string &name, int gradeSign, int gradeExec);
        AForm(const AForm &cpy);
        AForm &operator=(const AForm &obj);
        virtual ~AForm();

        const std::string getName( void ) const;
        int getIsSigned( void ) const;
        int getGradeSigned( void ) const;
        int getGradeExecute( void ) const;

        void beSigned(const Bureaucrat &obj);
        virtual void execute(Bureaucrat const & executor) const = 0;
        
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

std::ostream &operator<<(std::ostream &output, const AForm &obj);

#endif