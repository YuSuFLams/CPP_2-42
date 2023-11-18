/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 05:43:26 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/11/18 06:00:03 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T> 
MutantStack<T>::MutantStack(){}

template <typename T> 
MutantStack<T>::~MutantStack(){}

template <typename T> 
MutantStack<T>::MutantStack(const MutantStack &cpy){*this = cpy;}

template <typename T> 
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &obj)
{
    if (this != &obj)
        this->c = obj.c;
    return (*this);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(){return std::stack<T>::c.begin();}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(){return std::stack<T>::c.end();}
