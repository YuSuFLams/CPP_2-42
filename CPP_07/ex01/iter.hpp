/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:28:39 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/11/15 17:23:04 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string.h>

template <typename T, typename F>
void iter(T *array, size_t length, F func)
{
    if (!array)
        return ;
    for (size_t i = 0; i < length; i++)
        func(array[i]);
}

#endif 