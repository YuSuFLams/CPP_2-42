/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 22:56:28 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/11/15 23:36:12 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
    {
        try
        {
            Array<int> obj(9);
            
            int obj1[9] = {15, -9, -8, 5, 0, 7, -99, 26, 11};
            
            for(unsigned int i = 0; i < obj.size(); i++)
                obj[i] = obj1[i];
            std::cout << "Range Of Array is : " << obj.size() << std::endl;
            for(unsigned int i = 0; i < obj.size(); i++)
                std::cout << obj[i] << "\n";
            obj[11];
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
    {
        try
        {
            Array<std::string> obj(7);
            
            std::string obj1[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
            
            for(unsigned int i = 0; i < obj.size(); i++)
                obj[i] = obj1[i];
            std::cout << "Range Of Array is : " << obj.size() << std::endl;
            for(unsigned int i = 0; i < obj.size(); i++)
                std::cout << obj[i] << "\n";
            std::cout << obj[-21] << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        
    }
    return 0;
}