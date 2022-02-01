/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_accessors.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satchmin <satchmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 23:11:47 by satchmin          #+#    #+#             */
/*   Updated: 2022/02/01 23:20:55 by satchmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

namespace ft {

/**
 * @brief return a non const value at position ' n '
 */
    template<typename _Tp, typename _Alloc>
    typename vector<_Tp, _Alloc>::reference
    vector<_Tp, _Alloc>::operator[](size_type n)
    {
        return *(this->_start + n);
    }

/**
 * @brief return a const value at position ' n '
 */
    template<typename _Tp, typename _Alloc>
    typename vector<_Tp, _Alloc>::const_reference
    vector<_Tp, _Alloc>::operator[](size_type n) const
    {
        return *(this->_start + n);
    }

/**
 * @brief returns const value at ' n ' 
 * with range check
 */
    template <typename _Tp, typename _Alloc>
    typename vector<_Tp, _Alloc>::reference
    vector<_Tp, _Alloc>::at(size_type n)
    {
        this->_bounds_check(n);
        return (*this)[n];
    }

/**
 * @brief return value at ' n ' with range check
 */
    template <typename _Tp, typename _Alloc>
    typename vector<_Tp, _Alloc>::const_reference
    vector<_Tp, _Alloc>::at(size_type n) const
    {
        this->_bounds_check(n);
        return (*this)[n];
    }

/**
 * @brief returns value first value.
 */

    template <typename _Tp, typename _Alloc>
    typename vector<_Tp, _Alloc>::reference
    vector<_Tp, _Alloc>::front(void)
    {
        return *begin();
    }
/**
 * @brief return const value of first element.
 */
    template <typename _Tp, typename _Alloc>
    typename vector<_Tp, _Alloc>::const_reference
    vector<_Tp, _Alloc>::front(void) const
    {
        return *begin();
    }
/**
 * @brief returns the value of the last element
 */
    template <typename _Tp, typename _Alloc>
    typename vector<_Tp, _Alloc>::reference
    vector<_Tp, _Alloc>::back(void)
    {
        return *(end() - 1);
    }
  /**
 * @brief return the const value of the last element 
 */  
    template <typename _Tp, typename _Alloc>
    typename vector<_Tp, _Alloc>::const_reference
    vector<_Tp, _Alloc>::back(void) const
    {
        return *(end() - 1);
    }

}   // END NAMESPACE FT