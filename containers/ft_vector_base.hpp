/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_base.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satchmin <satchmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 15:36:28 by satchmin          #+#    #+#             */
/*   Updated: 2022/01/31 02:42:58 by satchmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_BASE_H
#define FT_VECTOR_BASE_H

#include <memory>

#define DFLT_CAPACITY 32
#define DFLT_SCALE 2

/****************************************************************
 VECTOR_BASE CLASS -- Template parameters
 
 * @param _Tp       Object to be Allocated
 * @param _Alloc    allocator to use std::allocator
 
 Vector base class that will deal with memory allocation this
 class declares the private member variables that contain the
 information related to the allocator
 
 * @param _start    pointer to start of memory block
 * @param _mem      allocator Object
 * @param _size     number of objects in the vector
 * @param _capacity number of objects that the vector can hold


**************************************************************/ 

namespace ft
{
    template <typename _Tp, typename _Alloc = std::allocator<_Tp> >
    class _vector_base
    {
        typedef _Tp* _iterator;
        typedef _Alloc _alloc_type;
        typedef size_t _size_type;

    public:
        _iterator _start;     // start of continuous memory block
        _alloc_type _mem; // object std::allocator
        _size_type _size;     // amount of constructed elements
        _size_type _capacity; // capacity of memory block

        /***
         *   CONSTRUCTORS
         */
    public:
        _vector_base();                                 // default
        _vector_base(_size_type size, const _Tp &value); // size and value
        _vector_base(const _vector_base<_Tp, _Alloc>& copy);
        ~_vector_base();         // copy
    };

    template <typename _Tp, typename _Alloc>
    _vector_base<_Tp, _Alloc>::_vector_base(void) : _size(), _capacity(DFLT_CAPACITY)
    {
        _start = _mem.allocate(_capacity);
    }

    template <typename _Tp, typename _Alloc>
    _vector_base<_Tp, _Alloc>::_vector_base(_size_type size, const _Tp &value) : _size(size), _capacity(size * DFLT_SCALE)
    {
        _start = _mem.allocate(_capacity);
        for (_size_type i = 0; i < size; i++)
            _mem.construct(_start + i, value);
    }

    template <typename _Tp, typename _Alloc>
    _vector_base<_Tp, _Alloc>::_vector_base(const _vector_base &copy) : _size(copy.size()), _capacity(copy.capacity())
    {
        _start = _mem.allocate(_capacity);
        std::uninitialized_copy(copy.begin(), copy.end(), _start);
    }

    template <typename _Tp, typename _Alloc>
    _vector_base<_Tp, _Alloc>::~_vector_base()
    {
        _mem.deallocate(_start, _capacity);
    }

} // end namespace

#endif // FT_VECTOR_BASE_H