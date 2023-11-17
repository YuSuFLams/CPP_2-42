/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:08:43 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/11/17 16:18:47 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <stdlib.h>
# include <iostream>

template <typename T>
void swap(T &a, T &b)
{
    T  tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
T min(T a, T b)
{
    return (a > b)? b: a;
}

template <typename T>
T max(T a, T b)
{
    return (a > b)? a: b; 
}


#endif