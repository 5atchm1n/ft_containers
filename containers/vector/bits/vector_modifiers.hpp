/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_modifiers.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satchmin <satchmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:31:59 by satchmin          #+#    #+#             */
/*   Updated: 2022/02/02 01:25:31y satchmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

#ifndef FT_VECTOR_MODIFIERS_HPP
#define FT_VECTOR_MODIFIERS_HPP
namespace ft {

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
        this->_realloc_fill(size, val);
}
/**
 * @brief assign for iterator and replace content
 */
template <typename _Tp, typename _Alloc>
template<typename _Iterator>
void
vector<_Tp, _Alloc>::assign(_Iterator first, _Iterator last, typename ft::enable_if<!ft::is_integral<_Iterator>::value >::type*)
{
    difference_type size = std::distance(first, last);
    this->_dealloc();
    this->_reserve(static_cast<size_type>(size));
    for (iterator i = begin(); i < begin() + size; i++)
        this->_mem.construct(i, *first++);
    this->_size = size;
}
/**
 * @brief replace content with value n times
 */
template <typename _Tp, typename _Alloc>
void
vector<_Tp, _Alloc>::assign(size_type n, const value_type& val)
{
    this->_dealloc();
    this->reserve(n);
    for (iterator i = begin(); i < begin() + n; i++)
        this->_mem.construct(i, val);
    this->_size = n;
}
/**
 * @brief add element to end
 */
template <typename _Tp, typename _Alloc>
void
vector<_Tp, _Alloc>::push_back(const value_type &val)
{
    if (size() < capacity())
        this->_mem.construct(this->_start + this->_size, val);
    else if (size() == capacity())
        this->_insert_back(val);
    this->_size++;
}
/**
 * @brief remove last element
 */
template <typename _Tp, typename _Alloc>
void
vector<_Tp, _Alloc>::pop_back()
{
    if (!this->_size)
        return ;
    this->_mem.destroy(end() - 1);
    this->_size--;
}
/**
 * @brief insert n copies of val at position
 */
template <typename _Tp, typename _Alloc>
void
vector<_Tp, _Alloc>::insert(iterator position, size_type n, const value_type &val)
{
    const difference_type index = position - begin();
    const difference_type pos_end = end() - begin();
    if (this->_size + n >= capacity())
        this->_realloc(this->_size + n);
    iterator    new_pos = this->_start + index;
    iterator    old_end = this->_start + pos_end;
    this->_move(n, new_pos, old_end);
    this->_size += n;
    while (n--)
        this->_mem.construct(new_pos++, val);
}
/**
 * @brief insert single element at given position
 */
template <typename _Tp, typename _Alloc>
typename vector<_Tp, _Alloc>::iterator
vector<_Tp, _Alloc>::insert(iterator position, const value_type &val)
{
    const difference_type index = position - begin();
    insert(position, 1, val);
    return begin() + index;
}
/**
 * @brief insert range of elements
 */
template <typename _Tp, typename _Alloc>
template <typename _Iterator>
void
vector<_Tp, _Alloc>::insert(iterator position, _Iterator first, _Iterator last,typename ft::enable_if<!ft::is_integral<_Iterator>::value >::type*)
{
    const   difference_type index = position - begin();
    const   difference_type pos_end = end() - begin();
    const   difference_type csize = std::distance(first, last);
    if (size() + csize > capacity())
        this->_realloc(size() + csize);
    iterator    cpos = begin() + index;
    iterator    cend = begin() + pos_end;
    if (cpos == cend)
    {
        while (first != last)
            push_back(*first++);        
        return ;
    }
    this->_move(csize, cpos, cend);
    while (first != last)
        this->_mem.construct(cpos++, *first++);
    this->_size += csize;        
}
/**
 * @brief erase element at position 
 */
template <typename _Tp, typename _Alloc>
typename vector<_Tp, _Alloc>::iterator
vector<_Tp, _Alloc>::erase(iterator position)
{
    iterator last = end() - 1;
    for (iterator i = position; i != last; i++)
    {
        this->_mem.destroy(i);
        if (i != last)
            this->_mem.construct(i, *(i + 1));
    }
    this->_size--;
    return position;
}
/**
 * @brief erase range of elements
 */
template <typename _Tp, typename _Alloc>
typename vector<_Tp, _Alloc>::iterator
vector<_Tp, _Alloc>::erase(iterator first, iterator last)
{
    difference_type size = std::distance(first, last);
    iterator old_last = end() - 1;
    for (iterator i = first; i < old_last; i++)
    {
        this->_mem.destroy(i);
        if (i + size <= old_last)
            this->_mem.construct(i, *(i + size));
    }
    this->_size -= size;
    return first;
}
/**
 * @brief swap vectors
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
/**
 * @brief clear vector
 */
template <typename _Tp, typename _Alloc>
void
vector<_Tp, _Alloc>::clear()
{
    for (size_type i = 0; i < size(); ++i)
        this->_mem.destroy(begin() + i);
    this->_size = 0;
}
/**
 * @brief get allocator
 */
template <typename _Tp, typename _Alloc>
typename vector<_Tp, _Alloc>::allocator_type
vector<_Tp, _Alloc>::get_allocator() const
{
    return this->_mem;
}

} // END NAMESPACE FT

#endif // FT_VECTOR_MODIFIERS_HPP