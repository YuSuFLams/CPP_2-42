/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:04:18 by ylamsiah          #+#    #+#             */
/*   Updated: 2024/02/06 18:27:16 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 3)
    {
        std::cerr << "Error: At least 2 numbers are required." << std::endl;
        return 1;
    }
    try
    {
        
        isAllpos(ac, av);
        if (isSorted(ac, av))
           throw std::invalid_argument("Error: The list is already sorted.");
        
        std::cout << "Before Sorting : ";
        for (int i = 1; i < ac; i++)
            std::cout << av[i] << " ";
        std::cout << std::endl;
        
        double a = clock();
        
        std::vector<int> s = sortArray<std::vector<int> >(ac, av);
        a = (clock() - a) / CLOCKS_PER_SEC;
        
        double b = clock();
        std::deque<int> tmp = sortArray<std::deque<int> >(ac, av);
        b = (clock() - b) / CLOCKS_PER_SEC;
        
        std::cout << "After Sorting  : ";
        affiche(s);
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "Time to process a range of " << ac - 1 << \
        " elements with std::vector : " << std::fixed << a << std::endl;
        std::cout << "Time to process a range of " << ac - 1 << \
        " elements with std::deque : " << std::fixed << a << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
