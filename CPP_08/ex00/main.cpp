/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 03:34:17 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/11/18 03:50:48 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(int ac, char **str)
{
    if (ac != 2) {
        std::cout << "Please give me a correct number as an argument." << std::endl;
        return 1;
    }

    int arr[] = {7, 5, 4, -1, 8, -4, 0, -5};
    int len = (sizeof(arr) / sizeof(arr[0]));

    std::vector<int> vec(arr, arr + len);

    std::cout << easyfind(vec, std::atoi(str[1])) << std::endl; 
    return 0;
}