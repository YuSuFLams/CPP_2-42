/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:58:38 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/11/20 19:47:12 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include <stdint.h>

typedef struct s_data
{
    std::string str;
    int         number;
    s_data(std::string &name, int &num):str(name), number(num){}
} Data;

class Serializer
{
    private:
    public:
        Serializer();
        Serializer(const Serializer &cpy);
        Serializer &operator=(const Serializer &obj);
        ~Serializer();

        static uintptr_t serialize(Data *ptr);
        static Data *deserialize(uintptr_t raw);
};
