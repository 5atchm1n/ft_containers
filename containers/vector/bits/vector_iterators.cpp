/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterators.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satchmin <satchmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 22:51:05 by satchmin          #+#    #+#             */
/*   Updated: 2022/02/01 23:18:15 by satchmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

namespace ft {

/**
 * @brief   Returns a pointer to _start 
 * non-const version
 */
    template <typename _Tp, typename _Alloc>
    typename vector<_Tp, _Alloc>::iterator
    vector<_Tp, _Alloc>::begin(void)
    {
        return this->_start;
    }

/**
 * @brief   Returns a pointer to _start
 * const version 
 */
    template <typename _Tp, typename _Alloc>
    typename vector<_Tp, _Alloc>::const_iterator
    vector<_Tp, _Alloc>::begin(void) const
    {
        return this->_start;
    }

/**
 * @brief returns a pointer to end 
 * non-const version
 */
    template <typename _Tp, typename _Alloc>
    typename vector<_Tp, _Alloc>::iterator
    vector<_Tp, _Alloc>::end(void)
    {
        return this->_start + this->_size;
    }

/**
 * @brief   return a pointer to end
 * const version 
 */
    template <typename _Tp, typename _Alloc>
    typename vector<_Tp, _Alloc>::const_iterator
    vector<_Tp, _Alloc>::end(void) const
    {
        return this->_start + this->_size;
    }

/**
 * @brief returns a reverse iterator
 * non-const version
 */
    template <typename _Tp, typename _Alloc>
    typename vector<_Tp, _Alloc>::reverse_iterator
    vector<_Tp, _Alloc>::rbegin(void)
    {
        return reverse_iterator (end());
    }

/**
 * @brief returns a reverse iterator
 * const version
 */
    template <typename _Tp, typename _Alloc>
    typename vector<_Tp, _Alloc>::const_reverse_iterator
    vector<_Tp, _Alloc>::rbegin(void) const
    {
        return const_reverse_iterator (end());
    }

/**
 * @brief returns a reverse iterator
 * non-const version
 */
    template <typename _Tp, typename _Alloc>
    typename vector<_Tp, _Alloc>::reverse_iterator
    vector<_Tp, _Alloc>::rend(void)
    {
        return reverse_iterator (begin());
    }
    
/**
 * @brief returns a reverse iterator rend
 * const-version 
 */
    template <typename _Tp, typename _Alloc>
    typename vector<_Tp, _Alloc>::const_reverse_iterator
    vector<_Tp, _Alloc>::rend(void) const
    {
        return const_reverse_iterator (begin());
    }

}   // END NAMESPACE FT