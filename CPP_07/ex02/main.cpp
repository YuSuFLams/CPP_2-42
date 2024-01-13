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

// int main()
// {
//     {
//         try
//         {
//             Array<int> obj(9);
            
//             int obj1[9] = {15, -9, -8, 5, 0, 7, -99, 26, 11};
            
//             for(unsigned int i = 0; i < obj.size(); i++)
//                 obj[i] = obj1[i];
//             std::cout << "Range Of Array is : " << obj.size() << std::endl;
//             for(unsigned int i = 0; i < obj.size(); i++)
//                 std::cout << obj[i] << "\n";
//             obj[11];
//         }
//         catch(const std::exception& e)
//         {
//             std::cerr << e.what() << std::endl;
//         }
//     }
//     std::cout << std::endl;
//     {
//         try
//         {
//             Array<std::string> obj(7);
            
//             std::string obj1[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
            
//             for(unsigned int i = 0; i < obj.size(); i++)
//                 obj[i] = obj1[i];
//             std::cout << "Range Of Array is : " << obj.size() << std::endl;
//             for(unsigned int i = 0; i < obj.size(); i++)
//                 std::cout << obj[i] << "\n";
//             std::cout << obj[-21] << std::endl;
//         }
//         catch(const std::exception& e)
//         {
//             std::cerr << e.what() << std::endl;
//         }
        
//     }
//     return 0;
// }
#define MAX_VAL 750

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}