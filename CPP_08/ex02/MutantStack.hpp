/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 05:30:14 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/11/18 05:59:25 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include <list>
# include <stack>
# include <iterator>
# include <algorithm>
# include <stdexcept>

template<typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack();
        MutantStack(const MutantStack &cpy);
        MutantStack &operator=(const MutantStack &obj);
        ~MutantStack();

    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin(); 
    iterator end(); 
};

#include "MutantStack.tpp"