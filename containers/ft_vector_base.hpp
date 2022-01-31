/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_base.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 15:36:28 by satchmin          #+#    #+#             */
/*   Updated: 2022/01/31 05:14:17 by sshakya          ###   ########.fr       */
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
        _iterator _start;
        _alloc_type _mem;
        _size_type _size;
        _size_type _capacity;

        void    _realloc_empty(_size_type size);
        void    _realloc(_size_type size);
        void    _realloc(_size_type size, const _Tp& value);
        
        _vector_base();
        _vector_base(_size_type size, const _Tp &value);
        _vector_base(const _vector_base<_Tp, _Alloc>& copy);
        ~_vector_base();
    };

/**
 * @brief default contructor
 * start with a default capacity
 */
    template <typename _Tp, typename _Alloc>
    _vector_base<_Tp, _Alloc>::_vector_base(void) : _size(), _capacity(DFLT_CAPACITY)
    {
        _start = _mem.allocate(_capacity);
    }

/**
 * @brief Construct a new vector base object
 * @param size  the size of the of vector
 * @param value the value to fill
 */
    template <typename _Tp, typename _Alloc>
    _vector_base<_Tp, _Alloc>::_vector_base(_size_type size, const _Tp &value) : _size(size), _capacity(size * DFLT_SCALE)
    {
        _start = _mem.allocate(_capacity);
        for (_size_type i = 0; i < size; i++)
            _mem.construct(_start + i, value);
    }

/**
 * @brief Construct a new vector base
 * @param copy  a vector to duplicate
 */
    template <typename _Tp, typename _Alloc>
    _vector_base<_Tp, _Alloc>::_vector_base(const _vector_base &copy) : _size(copy.size()), _capacity(copy.capacity())
    {
        _start = _mem.allocate(_capacity);
        std::uninitialized_copy(copy.begin(), copy.end(), _start);
    }

/**
 * @brief   allocation helper
 * Allocate memory if the the vector is empty
 */
    template <typename _Tp, typename _Alloc>
    void
    _vector_base<_Tp, _Alloc>::_realloc_empty(_size_type size)
    {
        this->_mem.deallocate(this->_start, this->_capacity);
        this->_start = this->_mem.allocate(size);
    }

/**
 * @brief allocation helper function
 * @param 
 */
    template <typename _Tp, typename _Alloc>
    void
    _vector_base<_Tp, _Alloc>::_realloc(_size_type size)
    {
        if (this->_size == 0)
            _realloc_empty(size)
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
 * @brief Destroy the vector base object
 */
    template <typename _Tp, typename _Alloc>
    _vector_base<_Tp, _Alloc>::~_vector_base()
    {
        _mem.deallocate(_start, _capacity);
    }

} // end namespace

#endif // FT_VECTOR_BASE_H