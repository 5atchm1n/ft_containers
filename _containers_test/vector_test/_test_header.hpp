/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_header.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:12:15 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/11 14:55:49 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _VECTOR_HEADER_HPP
#define _VECTOR_HEADER_HPP

#include "vector.hpp"
#include <string>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <climits>

#ifndef _NAMESPACE
#define _NAMESPACE ft
#endif

// random number seed
#define _SEED 42
// max number of seeds to test
#define MAX_SEED 10

namespace _test_vector
{
    
// Total number of cases
#define _TEST_BASIC 5
// Test cases
#define _DEFAULT_CONSTRUCTOR 0
#define _COPY_CONSTRUCTOR 1
#define _ASSIGNMENT_OP 2
#define _MIXED_0_3 3
#define _REL_OP 4

// Total number of cases
#define _TEST_MAIN 8
// Test cases
#define _INSERT 0
#define _ASSIGN 1
#define _PUSH 2
#define _POP 3
#define _ERASE 4
#define _RESIZE 5
#define _SWAP 6
#define _CLEAR 7

// MAX amount of values to assign/insert
#define _MAX_TEST_SIZE 10

// Number of iterations of test suite
#define _NTESTS 5000
#define _NTESTS_BASIC 50

// For debugging
static int test_no = 0;
static int main_test_no = 0;

}

// Tests
#include "_test_tools.hpp"
#include "_test_basic.hpp"
#include "_test_modify.hpp"


#endif  //_VECTOR_HEADER_HPP