/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 23:49:15 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/11/16 00:58:01 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string &name);
        PresidentialPardonForm(const PresidentialPardonForm &cpy);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &obj);
        ~PresidentialPardonForm();

        std::string getTarget( void ) const;

        void execute(Bureaucrat const & executor) const;
};

#endif