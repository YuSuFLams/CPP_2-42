/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:06:56 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/11/20 19:47:06 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::~Serializer(){}

uintptr_t Serializer::serialize(Data *ptr){return reinterpret_cast<uintptr_t>(ptr);}

Data *Serializer::deserialize(uintptr_t raw){return reinterpret_cast<Data *>(raw);}