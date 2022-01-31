/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satchmin <satchmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:31:59 by satchmin          #+#    #+#             */
/*   Updated: 2022/01/31 17:16:16 by satchmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.hpp"

namespace ft {

/**
 * @brief   construct a vector for a range
 * @param   first     start of the range to copy
 * @param   last      end of the range to copy
 * First we allocate a default amount of memory and we then copy then
 * use push back to add elements to the end.
 */

template<typename _Tp, typename _Alloc>
vector<_Tp, _Alloc>&
vector<_Tp, _Alloc>::operator=(const vector &val)
{
    if (this->_size)
        this->_dealloc();
    this->_start = this->_mem.allocate(val.capacity());
    std::uninitialized_copy(val.begin(), val.end(), this->_start);
    this->_size = val.size();
    this->_capacity = val.capacity();
    return *this;
    
}

template<typename _Tp, typename _Alloc>
typename vector<_Tp, _Alloc>::reference
vector<_Tp, _Alloc>::operator[](size_type n)
{
    return *(this->_start + n);
}

template<typename _Tp, typename _Alloc>
typename vector<_Tp, _Alloc>::const_reference
vector<_Tp, _Alloc>::operator[](size_type n) const
{
    return *(this->_start + n);
}

template <typename _Tp, typename _Alloc>
vector<_Tp, _Alloc>::vector(size_type size, const value_type &val, const allocator_type &alloc) : _vector_base<_Tp, _Alloc>(size, val, alloc)
{
    
}

template <typename _Tp, typename _Alloc>
template <typename _Iterator>
vector<_Tp, _Alloc>::vector(_Iterator first, _Iterator last, typename ft::enable_if<!ft::is_integral<_Iterator>::value >::type*)
{
    difference_type diff = last - first;
    
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
        throw std::out_of_range("vector");
    else
        this->_realloc(size);
}

/**
 * @brief resize vector so it contains n elements
 * 
 */
    template <typename _Tp, typename _Alloc>
    void
    vector<_Tp, _Alloc>::resize(size_type size, value_type val)
    {
        this->_range_check(size);
        if (size < this->_size)
        {
            for (size_type i = this->_size; i > size; i--)
                this->_mem.destroy(this->_start + i);
            this->_size = size;
        }
        if (size > this->_size)
            this->_realloc(size, val);
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
 * @brief
 */
    template <typename _Tp, typename _Alloc>
    typename vector<_Tp, _Alloc>::reference
    vector<_Tp, _Alloc>::at(size_type n)
    {
        this->_bounds_check(n);
        return (*this)[n];
    }

/**
 * @brief 
 */
    template <typename _Tp, typename _Alloc>
    typename vector<_Tp, _Alloc>::const_reference
    vector<_Tp, _Alloc>::at(size_type n) const
    {
        this->_bounds_check(n);
        return (*this)[n];
    }

    template <typename _Tp, typename _Alloc>
    typename vector<_Tp, _Alloc>::reference
    vector<_Tp, _Alloc>::front(void)
    {
        return *begin();
    }

    template <typename _Tp, typename _Alloc>
    typename vector<_Tp, _Alloc>::const_reference
    vector<_Tp, _Alloc>::front(void) const
    {
        return *begin();
    }

    template <typename _Tp, typename _Alloc>
    typename vector<_Tp, _Alloc>::reference
    vector<_Tp, _Alloc>::back(void)
    {
        return *(end() - 1);
    }
    
    template <typename _Tp, typename _Alloc>
    typename vector<_Tp, _Alloc>::const_reference
    vector<_Tp, _Alloc>::back(void) const
    {
        return *(end() - 1);
    }

    template <typename _Tp, typename _Alloc>
    template<typename _Iterator>
    void
    vector<_Tp, _Alloc>::assign(_Iterator first, _Iterator last)
    {
        while (first != last)
            push_back(*first++);
    }

    template <typename _Tp, typename _Alloc>
    void
    vector<_Tp, _Alloc>::assign(size_type n, const value_type& val)
    {
        for (size_type i = 0; i < n; i++)
            push_back(val.begin() + i);    
    }

    template <typename _Tp, typename _Alloc>
    void
    vector<_Tp, _Alloc>::push_back(const value_type &val)
    {
        if (size() < capacity())
            this->_mem.construct(this->_start + this->_size, val);
        else if (this->_size == capacity())
            this->_insert_back(val);
        this->_size++;
    }
/*    
    template <typename _Tp, typename _Alloc>
    void
    vector<_Tp, _Alloc>::pop_back()
    {
        
    }

    template <typename _Tp, typename _Alloc>
    typename vector<_Tp, _Alloc>::iterator
    vector<_Tp, _Alloc>::insert(iterator position, const value_type &val)
    {
        
    }

    template <typename _Tp, typename _Alloc>
    template <typename _Iterator>
    void
    vector<_Tp, _Alloc>::insert(iterator position, _Iterator first, _Iterator last)
    {

    }
    
    template <typename _Tp, typename _Alloc>
    typename vector<_Tp, _Alloc>::iterator
    vector<_Tp, _Alloc>::erase(iterator position)
    {
        
    }

    template <typename _Tp, typename _Alloc>
    typename vector<_Tp, _Alloc>::iterator
    vector<_Tp, _Alloc>::erase(iterator first, iterator last)
    {
        
    }
*/
    template <typename _Tp, typename _Alloc>
    void
    vector<_Tp, _Alloc>::swap(vector &val)
    {
        std::swap(this->_mem, val._mem);
        std::swap(this->_start, val._start);
        std::swap(this->_size, val._size);
        std::swap(this->_capacity, val._capacity);
    }
    
    template <typename _Tp, typename _Alloc>
    void
    vector<_Tp, _Alloc>::clear()
    {
        for (size_type i = 0; i < size(); ++i)
            this->_mem.destroy(begin() + i);
        this->_size = 0;
    }

    template <typename _Tp, typename _Alloc>
    typename vector<_Tp, _Alloc>::allocator_type
    vector<_Tp, _Alloc>::get_allocator() const
    {
        return this->_mem;
    }
} // end namespace