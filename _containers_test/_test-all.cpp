/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test-vector.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 03:34:44 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/01 17:1 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <map>
#include <set>
#include <vector>

// random number seed
#define _SEED 42
// max number of seeds to test
#define MAX_SEED 10

#ifndef _NAMESPACE
#define _NAMESPACE std
#endif


#include "_test-vector.cpp"
#include "_test-map.cpp"
#include "_test-set.cpp"

int main(void)
{
    int seed = _SEED;
    for (int i = 0; i < MAX_SEED; i++)
    {
#ifdef _TEST_VECTOR
        test_vector<_NAMESPACE::vector<std::string> >(seed++);
#endif
#ifdef _TEST_MAP
        test_map<_NAMESPACE::map<int, std::string> >(seed++);
#endif
#ifdef _TEST_SET
        test_set<_NAMESPACE::set<int> >(seed++);
#endif
    }
    return 0;
}