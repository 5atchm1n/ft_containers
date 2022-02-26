/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_basic.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satchmin <satchmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 23:28:57 by satchmin          #+#    #+#             */
/*   Updated: 2022/02/01 23:55:09by satchmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

namespace ft
{
/**
 * @brief Assignment OPERATOR=
 * 
 * @param val   the value to be assigned
 * @return      the original object with val copied into it.
 */
    template <typename _Tp, typename _Alloc>
    vector<_Tp, _Alloc> &
    vector<_Tp, _Alloc>::operator=(const vector &val)
    {
        if (this->_size || this->_capacity)
            this->_dealloc();
        this->_start = this->_mem.allocate(val.capacity());
        std::uninitialized_copy(val.begin(), val.end(), this->_start);
        this->_size = val.size();
        this->_capacity = val.capacity();
        return *this;
    }

    template <typename _Tp, typename _Alloc>
    vector<_Tp, _Alloc>::vector(size_type size, const value_type &val, const allocator_type &alloc) : _vector_base<_Tp, _Alloc>(size, val, alloc)
    {
    }

/**
 * @brief Construct a new vector from range
 * 
 * @param first         start of elements to copy 
 * @param last          end of elements to copy 
 */
    template <typename _Tp, typename _Alloc>
    template <typename _Iterator>
    vector<_Tp, _Alloc>::vector(_Iterator first, _Iterator last, typename ft::enable_if<!ft::is_integral<_Iterator>::value>::type*)
    {
        difference_type diff = std::distance(first, last);
        this->_size = diff;
        this->_capacity = diff * DFLT_SCALE;
        this->_realloc_empty(diff);
        std::uninitialized_copy(first, last, this->_start);
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

    template <typename _Tp, typename _Alloc>
    inline bool
    operator==(const vector<_Tp, _Alloc>& lhs, const vector<_Tp, _Alloc>& rhs)
    {
        return lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin());
    }

    template <typename _Tp, typename _Alloc>
    inline bool
    operator!=(const vector<_Tp, _Alloc>& lhs, const vector<_Tp, _Alloc>& rhs)
    {
        return !(lhs == rhs);
    }

    template <typename _Tp, typename _Alloc>
    inline bool
    operator<(const vector<_Tp, _Alloc>& lhs, const vector<_Tp, _Alloc>& rhs)
    {
        return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }

    template <typename _Tp, typename _Alloc>
    inline bool
    operator>(const vector<_Tp, _Alloc>& lhs, const vector<_Tp, _Alloc>& rhs)
    {
        return !(rhs < lhs);
    }

    template <typename _Tp, typename _Alloc>
    inline bool
    operator<=(const vector<_Tp, _Alloc>& lhs, const vector<_Tp, _Alloc>& rhs)
    {
        return !(rhs < lhs);
    }

    template <typename _Tp, typename _Alloc>
    inline bool
    operator>=(const vector<_Tp, _Alloc>& lhs, const vector<_Tp, _Alloc>& rhs)
    {
        return !(lhs < rhs);
    }

}   // END NAMESPACE FT
