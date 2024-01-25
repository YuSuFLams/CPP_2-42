/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:57:41 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/11/20 20:29:55 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base(){}

Base *generate() {
    switch (rand() % 3) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return NULL;
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "Type Is A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Type Is B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Type Is C" << std::endl;
    else
        std::cout << "Type Is Unknown" << std::endl;
}

void identify(Base& p) {
    try {
        A &a = dynamic_cast<A &>(p);

        (void)a;
        std::cout << "Type Is A" << std::endl;
    } catch (const std::exception& e) {
        try {
            B &b = dynamic_cast<B &>(p);

            (void)b;
            std::cout << "Type Is B" << std::endl;
        } catch (const std::exception& e) {
            try {
                C &c = dynamic_cast<C &>(p);

                (void)c;
                std::cout << "Type Is C" << std::endl;
            } catch (const std::exception& e) {
                std::cout << "Type Is Unknown" << std::endl;
            }
        }
    }
}