/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test-map.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 04:45:48 by sshakya           #+#    #+#             */
/*   Updated: 2022/02/23 02:13:10 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "map.hpp"

bool fncomp(char lhs, char rhs) { return lhs < rhs; }

struct classcomp
{
	bool operator()(const char &lhs, const char &rhs) const
	{
		return lhs < rhs;
	}
};

void	ft_print(ft::map<char, int> map)
{
	std::cout << "map contains:\n";
	ft::map<char, int>::const_iterator itt = map.begin();
		for (itt = map.begin(); itt != map.end(); ++itt)
		std::cout << itt->first << " => " << itt->second << '\n';
	std::cout << "size :" << map.size() << std::endl;
}

int main()
{
	ft::map<char, int> first;

	first['a'] = 10;
	first['b'] = 30;
	first['c'] = 50;
	first['d'] = 70;


	ft::map<char, int> second(first.begin(), first.end());

	ft::map<char, int> third(second);

	ft::map<char, int, classcomp> fourth; // class as Compare

	bool (*fn_pt)(char, char) = fncomp;
	ft::map<char, int, bool (*)(char, char)> fifth(fn_pt); // function pointer as Compare


	// TESTING INSERT

	ft::map<char, int> mymap;	

	// first insert function version (single parameter):
	mymap.insert(ft::pair<char, int>('a', 100));
	mymap.insert(ft::pair<char, int>('z', 200));

	ft::pair<ft::map<char, int>::iterator, bool> ret;
	ret = mymap.insert(ft::pair<char, int>('z', 500));
	if (ret.second == false)
	{
		std::cout << "element 'z' already existed";
		std::cout << " with a value of " << ret.first->second << '\n';
	}

	mymap['b'] = 20;
	mymap['c'] = 67;
	mymap['e'] = 67;
	mymap['x'] = 67;
	mymap['f'] = 90;

	// second insert function version (with hint position):
	ft::map<char, int>::iterator it = mymap.begin();
	// third insert function version (range insertion):
	ft::map<char, int> anothermap;
	anothermap.insert(mymap.begin(), mymap.find('c'));

	// showing contents:
	std::cout << "mymap contains:\n";
	for (it = mymap.begin(); it != mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "anothermap contains:\n";
	for (it = anothermap.begin(); it != anothermap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	ft_print(mymap);

	it=mymap.find('b');
	mymap.erase (it);                   // erasing by iterator
	std::cout << mymap.erase ('c') << std::endl;                  // erasing by key

	ft_print(mymap);

	it=mymap.find ('e');
	mymap.erase ( it, mymap.end() );
	
	ft_print(mymap);
	return 0;
}
