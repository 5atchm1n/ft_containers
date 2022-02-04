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

    template <typename _Tp, typename _Alloc>
    template<typename _Iterator>
    void
    vector<_Tp, _Alloc>::assign(_Iterator first, _Iterator last, typename ft::enable_if<!ft::is_integral<_Iterator>::value >::type*)
    {
        difference_type size = last - first;
        this->_realloc_empty(static_cast<size_type>(size));
        for (iterator i = begin(); i < begin() + size; i++)
            this->_mem.construct(i, *first++);
        this->_size = static_cast<size_type>(size);
    }

    template <typename _Tp, typename _Alloc>
    void
    vector<_Tp, _Alloc>::assign(size_type n, const value_type& val)
    {
        if (n > capacity())
            this->_realloc_empty(n);
        for (iterator i = begin(); i < begin() + n; i++)
            this->_mem.construct(i, val);
        this->_size = n;
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
        
    template <typename _Tp, typename _Alloc>
    void
    vector<_Tp, _Alloc>::pop_back()
    {
        if (!this->_size)
            return ;
        this->_mem.destroy(end() - 1);
        this->_size--;
    }

    template <typename _Tp, typename _Alloc>
    void
    vector<_Tp, _Alloc>::insert(iterator position, size_type n, const value_type &val)
    {
        const difference_type index = position - begin();
        const difference_type pos_end = end() - begin();
        size_type old_size = size();

        if (old_size == 0)
            return push_back(val);
        if (this->_size + n > capacity())
            this->_realloc(this->_size + n);
        
        iterator    new_pos = this->_start + index;
        iterator    old_end = this->_start + pos_end;
        this->_move(n, new_pos, old_end);
        for (iterator i = new_pos; i < new_pos + n; i++)
            this->_mem.construct(i, val);
        this->_size += n; 
    }

    template <typename _Tp, typename _Alloc>
    typename vector<_Tp, _Alloc>::iterator
    vector<_Tp, _Alloc>::insert(iterator position, const value_type &val)
    {
        const difference_type index = position - begin();
        insert(position, 1, val);
        return begin() + index;
    }

    template <typename _Tp, typename _Alloc>
    template <typename _Iterator>
    void
    vector<_Tp, _Alloc>::insert(iterator position, _Iterator first, _Iterator last,typename ft::enable_if<!ft::is_integral<_Iterator>::value >::type*)
    {
        const   difference_type index = position - begin();
        const   difference_type pos_end = end() - begin();
        const   difference_type csize = last - first;
        if (size() + csize > capacity())
            this->_realloc(size() + csize);
        iterator    cpos = begin() + index;
        iterator    cend = begin() + pos_end;
        this->_move(csize, cpos, cend);
        while (first != last)
            this->_mem.construct(cpos++, *first++);
        this->_size += csize;        
    }

    template <typename _Tp, typename _Alloc>
    typename vector<_Tp, _Alloc>::iterator
    vector<_Tp, _Alloc>::erase(iterator position)
    {
        iterator last = end() - 1;
        for (iterator i = position; i < last; i++)
        {
            this->_mem.destroy(i);
            if (i != last)
                this->_mem.construct(i, *(i + 1));
        }
        this->_size--;
        return position;
    }

    template <typename _Tp, typename _Alloc>
    typename vector<_Tp, _Alloc>::iterator
    vector<_Tp, _Alloc>::erase(iterator first, iterator last)
    {
        difference_type size = last - first;
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