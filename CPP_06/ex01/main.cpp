/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:17:19 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/11/20 19:47:18 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
    
    std::string name = "Youssef";
    int         number = 42;

    Data* obj = new Data(name, number);

    std::cout << "Name : " << Serializer::deserialize(Serializer::serialize(obj))->str << std::endl;    
    std::cout << "Number : " << Serializer::deserialize(Serializer::serialize(obj))->number << std::endl;

    delete obj;

    return 0;
}
