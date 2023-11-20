/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:50:41 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/11/20 20:30:02 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <cstdlib>
# include <ctime>
# include <unistd.h>

class Base{public: virtual ~Base(){}};

class A: public Base{};

class B: public Base{};

class C: public Base{};

Base * generate(void);
void identify(Base *p);
void identify(Base &p);
