/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:27:44 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/11/15 20:03:48 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

// void upper_ca(char &c)
// {
//     if (c >= 'a' && c <= 'z')
//         c -= 32;
//     else if (c >= 'A' && c <= 'Z')
//         c += 32;
// }

// template <typename T>
// void test_case(T &pos)
// {
//     std::cout << pos << ((pos < 0) ? ": negative" : " : positive") << std::endl;
// }

// int main()
// {
//     std::cout << "**** First Test ****" << std::endl;
//     char str[] = "hello";

//     std::cout << str << std::endl;
//     ::iter(str, strlen(str), upper_ca);
//     std::cout << str << std::endl;

//     std::cout << "**** Second Test ****" << std::endl;
    
//     char *new_str = NULL;
    
//     ::iter(new_str, 3, upper_ca);
    
//     std::cout << "**** Third Test ****" << std::endl;
    
//     int array[] = {12, 23, 4, 34, -20};
//     int len = sizeof(array) / sizeof(*array); 

//     ::iter(array, len, &test_case<int>);
    
//     return 0;
// }


class Awesome
{
	public:
		Awesome( void ) : _n( 42 ) { return; }
		int get( void ) const { return this->_n; }
	private:
		int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
	o << rhs.get();
	return o;
}

template< typename T >
void print( T& x )
{
	std::cout << x << std::endl;
	return ;
}

int main()
{
	int tab[] = { 0, 1, 2, 3, 4 };

	Awesome tab2[5];

	iter( tab, 5, print<const int> );
	iter( tab2, 5, print<Awesome> );

	return 0;
}