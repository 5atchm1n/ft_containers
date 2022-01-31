/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:31:59 by satchmin          #+#    #+#             */
/*   Updated: 2022/01/31 05:18:17 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.hpp"
#include <limits>
#include <stdexcept>

namespace ft {

/**
 * @brief   construct a vector for a range
 * @param   first     start of the range to copy
 * @param   last      end of the range to copy
 * First we allocate a default amount of memory and we then copy then
 * use push back to add elements to the end.
 */
template <typename _Tp, typename _Alloc>
template <typename _Iterator>
vector<_Tp, _Alloc>::vector(_Iterator first, _Iterator last)
{
    this->_size = 0;
    this->_capacity = DFLT_CAPACITY;
    this->_start = this->_mem.allocate(DFLT_CAPACITY);
    while (first != last)
        this->push_back(*first++);
}

/**
 * @brief Destructor
 * 
 * Destroys the objects (dealloation is done by base class)
 */
template <typename _Tp, typename _Alloc>
vector<_Tp, _Alloc>::~vector(void)
{
    for (size_type i = 0; i < this->_size; i++)
        this->_mem.destroy(this->_start + i);
}

/**
 * @brief   Reserves a block of memory for future use
 * @param size      size of memory block to allocated
 */
template <typename _Tp, typename _Alloc>
void
vector<_Tp, _Alloc>::reserve(size_type size)
{
    if (this->_capacity > size)
        return ;
    if (size > max_size())
        throw std::lenght_error("vector");
    else
        this->_realloc(size);
}

/**
 * @brief resize vector so it contains n elements
 * 
 */
    template <typename _Tp, typename _Alloc>
    void
    vector<_Tp, _Alloc>::resize(size_type size, value_type val = value_type())
    {
        if (size < size())
            for (reverse_iterator it = end(); it < size; it++)
                this->_mem.destroy(it);
        if (size > this->_capacity)
            this->_realloc(size);
        if (size > size())
            this->_realloc(size);
    }
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

/*******
 * @brief return the max allocation size
 */
    template <typename _Tp, typename _Alloc>
    typename vector<_Tp, _Alloc>::size_type
    vector<_Tp, _Alloc>::max_size(void) const
    {
        return (std::numeric_limits<size_type>::max() / sizeof(value_type));
    }

} // end namespace