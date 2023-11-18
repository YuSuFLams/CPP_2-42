/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 03:27:43 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/11/18 03:51:08 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

template <typename T>
std::string easyfind(T &container, int num)
{
    return ((std::find(container.begin(), container.end(), num) != container.end()) ? "Found" : "Not Found");
}
