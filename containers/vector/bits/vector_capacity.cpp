/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_capacity.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satchmin <satchmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 23:21:36 by satchmin          #+#    #+#             */
/*   Updated: 2022/02/01 23:25:23 by satchmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

namespace ft {
    
/**
 * @brief return the max allocation size
 */
    template <typename _Tp, typename _Alloc>
    typename vector<_Tp, _Alloc>::size_type
    vector<_Tp, _Alloc>::max_size(void) const
    {
        return this->_mem.max_size();
    }
    /**
 * @brief return the capacity
 */
    template <typename _Tp, typename _Alloc>
    typename vector<_Tp, _Alloc>::size_type
    vector<_Tp, _Alloc>::capacity() const
    {
        return this->_capacity;
    }

/**
 * @brief true if vector is empty
 */
    template <typename _Tp, typename _Alloc>
    bool
    vector<_Tp, _Alloc>::empty() const
    {
        return this->_size ? false : true;
    }

/**
 * @brief return the amount of objects
 */
    template <typename _Tp, typename _Alloc>
    typename vector<_Tp, _Alloc>::size_type
    vector<_Tp, _Alloc>::size() const
    {
        return this->_size;
    }

}