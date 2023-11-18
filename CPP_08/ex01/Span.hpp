/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 03:53:30 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/11/18 05:13:12 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <vector>
# include <algorithm>
# include <string>
# include <stdexcept>

class Span
{
    private:
        std::vector<int> vec;
        unsigned int N;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span &cpy);
        Span &operator=(const Span &obj);
        ~Span();

        void addNumber(int n);
        void addNumber(std::vector<int>::iterator b, std::vector<int>::iterator e);

        unsigned int ShortestSpan( void ) const;
        unsigned int longestSpan( void ) const;
};
