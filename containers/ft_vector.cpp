/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satchmin <satchmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:31:59 by satchmin          #+#    #+#             */
/*   Updated: 2022/01/31 02:48:45 by satchmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.hpp"
#include <limits>

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
    if (size > std::numeric_limits<size_type>::max())
        throw std::bad_alloc();
    if (this->_size == 0)
    {
        this->_mem.deallocate(this->_start, this->_capacity);
        this->_start = this->_mem.allocate(size);
    }
    else
    {
        _Tp* temp = this->_mem.allocate(size);
        std::uninitialized_copy(this->_start, this->_start + this->_size, temp);
        for (size_type i = 0; i < this->_size; i++)
            this->_mem.destroy(this->_start + i);
        this->_mem.deallocate(this->_start, this->_capacity);
        this->_start = temp;
    }
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


} // end namespace