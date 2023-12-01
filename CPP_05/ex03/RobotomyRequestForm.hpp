/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 00:07:55 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/11/16 00:15:56 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string &name);
        RobotomyRequestForm(const RobotomyRequestForm &cpy);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &cpy);
        ~RobotomyRequestForm();

        std::string &getTarget( void ) const;

        void execute(Bureaucrat const & executor) const;
};

#endif 