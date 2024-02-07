/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:03:13 by ylamsiah          #+#    #+#             */
/*   Updated: 2024/02/07 02:53:33 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>
#include <deque>
#include <ctime>
#include <iomanip>


bool isSorted(int ac, char **av);
bool isAllDigit(std::string str);
void isAllpos(int ac, char **str);


template <typename T>
void affiche(T &s)
{
    for (typename T::iterator it = s.begin(); it != s.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

template <typename T>
T   firstSort(T tmp)
{
    for (int i = 2; i < (int)tmp.size(); i += 2) {
        for (int j = i - 2; j >= 0 && tmp[j + 2] < tmp[j]; j -= 2) {
            std::swap(tmp[j + 2], tmp[j]);
            std::swap(tmp[j + 3], tmp[j + 1]);
        }
    }
    return tmp;
}
template <typename T>
T  sortArray(int ac, char **av)
{
    T tmp;
    int lst = -1;
    if (!(ac % 2))
        ac--;
    for (int i = 1; i < ac; i+=2)
    {
        int a = std::atoi(av[i]);
        int b = std::atoi(av[i + 1]);
        if (a > b)
            std::swap(a, b);
        tmp.push_back(a);
        tmp.push_back(b);
    }
    if (av[ac])
        lst = std::atoi(av[ac]);
    tmp = firstSort(tmp);
    T tmp2;
    for (int i = 1; i < (int)tmp.size(); i++)
    {
        tmp2.push_back(tmp[i]);
        tmp.erase(tmp.begin() + i);
    }
    tmp2.insert(tmp2.begin(), tmp[0]);
    int a = 0;
    int b = 1;
    int c = a * 2 + b;
    int d = tmp2.size();
    for (int i = 0; c < d; i++)
    {
        a = b;
        b = c;
        b+(a*2) >= d? c = d : c = b+(a*2);
        for (int j = c; j > b; j--)
        {
            tmp.insert(std::lower_bound(tmp.begin(), tmp.end(), tmp2[j - 1]), \
            tmp2[j - 1]);
        }
    }
    if (lst != -1)
        tmp.insert(std::lower_bound(tmp.begin(), tmp.end(), lst), lst);
    return tmp;
}
