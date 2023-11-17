/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 22:36:17 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/11/17 16:21:49 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array(): nbr(0), array(new T[0]()){}

template <typename T>
Array<T>::Array(unsigned int n): nbr(n), array(new T[n]()){}

template <typename T>
Array<T>::~Array(){delete [] array;}

template <typename T>
Array<T> &Array<T>::operator=(const Array &obj)
{
    if (this != &obj)
    {
        delete[] this->array;
        this->nbr = obj.nbr;
        this->array = new T[obj.nbr]();
        for(unsigned int i = 0; i < obj.nbr; i++)
            this->array[i] = obj.array[i];
    }
    return (*this);
}

template <typename T>
Array<T>::Array(const Array &cpy)
{
    this->nbr = cpy.nbr;
    this->array = new T[cpy.nbr]();
    for(unsigned int i = 0; i < cpy.nbr; i++)
        this->array[i] = cpy.array[i];

}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index >= this->nbr)
        throw std::out_of_range("Your Index You gave Me Is Out Of Range");
    return (this->array[index]);
}

template <typename T>
unsigned int Array<T>::size()
{
    return (this->nbr);
}