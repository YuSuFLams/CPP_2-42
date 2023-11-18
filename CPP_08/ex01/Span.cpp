/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 03:53:01 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/11/18 05:13:05 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): N(50){vec.reserve(50);}

Span::~Span(){}

Span::Span(unsigned int N): N(N){vec.reserve(N);}

Span::Span(const Span &cpy){*this = cpy;}

Span &Span::operator=(const Span &obj)
{
    if (this != &obj)
    {
        this->N = obj.N;
        this->vec = obj.vec;
    }
    return (*this);
}

void Span::addNumber(int n)
{
    if (this->vec.size() >= (size_t)this->N)
        throw std::logic_error("Array is Full");
    this->vec.push_back(n);
}

unsigned int Span::longestSpan( void ) const
{
    if (this->vec.size() < 2)
        throw std::logic_error("Cannot find span with less 2 number in array.");
    return (*std::max_element(vec.begin(), vec.end()) - *std::min_element(vec.begin(), vec.end()));
}

unsigned int Span::ShortestSpan( void ) const
{
    if (this->vec.size() < 2)
        throw std::logic_error("Cannot find span with less 2 number in array.");
    std::vector<int> array(vec);
    std::sort(array.begin(), array.end());
    int min_span = array[1] - array[0];
    int new_min;
    for (size_t i = 0; i < array.size(); i++)
    {
        new_min = array[i] - array[i - 1];
        min_span = std::min(min_span, new_min);
    }
    return (min_span);
}

void Span::addNumber(std::vector<int>::iterator b, std::vector<int>::iterator e)
{
    if (vec.size() >= this->N)
        throw std::logic_error("Array is Full");
    this->vec.insert(vec.end(), b, e);
}