/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:17:19 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/11/20 20:32:59 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
    std::cout << "\033[95m******* First Case *******\033[0m" << std::endl;
    srand(time(NULL));
    Base *ex = generate();
    std::cout << "Ptr: " ; identify(ex);
    std::cout << "Add: " ; identify(*ex);
    
    std::cout << "\033[92m******* Second Case *******\033[0m" << std::endl;
    srand(time(NULL));
    Base *ex1 = generate();  
    std::cout << "Ptr: " ; identify(ex1);
    std::cout << "Add: " ; identify(*ex1);
    
    std::cout << "\033[93m******* Third Case *******\033[0m" << std::endl;
    srand(time(NULL));
    Base *ex2 = generate();  
    std::cout << "Ptr: " ; identify(ex2);
    std::cout << "Add: " ; identify(*ex2);
    
    std::cout << "\033[94m******* Fourth Case *******\033[0m" << std::endl;
    srand(time(NULL));
    Base *ex3 = generate();  
    std::cout << "Ptr: " ; identify(ex3);
    std::cout << "Add: " ; identify(*ex3);
    
    delete ex;
    delete ex1;
    delete ex2;
    delete ex3;

    return 0;
}