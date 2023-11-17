/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 22:32:33 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/11/15 23:34:17 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdexcept>
# include <iostream>
# include <string>

template <typename T>
class Array
{
    private:
        unsigned int nbr;
        T *array;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &cpy);
        Array &operator=(const Array &obj);
        T &operator[](unsigned int index);
        ~Array();
        
        unsigned int size();
};

#include "Array.tpp"
#endif