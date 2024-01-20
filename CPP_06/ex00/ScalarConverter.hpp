/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:45:22 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/11/23 19:07:54 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <cstdlib>
# include <cctype>
# include <string>
# include <iomanip>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &cpy);
        ScalarConverter &operator=(const ScalarConverter &obj);
    public:
        ~ScalarConverter();
        
        static void convert(const std::string &str);

        class InvalidInput : public std::exception
        {
            public:
                const char *what() const throw();
        };
};
