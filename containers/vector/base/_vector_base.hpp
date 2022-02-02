/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _vector_base.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satchmin <satchmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 15:36:28 by satchmin          #+#    #+#             */
/*   Updated: 2022/02/02 17:37:13 by satchmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_BASE_H
#define FT_VECTOR_BASE_H

#include <memory>
#include <cstddef>
#include <stdexcept>

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
    public:
        typedef _Tp *_iterator;
        typedef _Alloc _alloc_type;
        typedef size_t _size_type;

        _iterator _start;
        _size_type _size;
        _alloc_type _mem;
        _size_type _capacity;

        _vector_base();
        _vector_base(_size_type size, const _Tp& value = _Tp(), const _Alloc &val = _Alloc());
        _vector_base(const _vector_base<_Tp, _Alloc> &copy);
        ~_vector_base();

    protected:
        void _dealloc();
        void _realloc_empty(_size_type size);
        void _realloc(_size_type size);
        void _realloc_fill(_size_type size, const _Tp &value);
        void _move(_size_type n, _iterator start, _iterator end);
        void _insert_back(const _Tp &value);
        void _range_check(_size_type n) const;
        void _bounds_check(_size_type n) const;
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
    _vector_base<_Tp, _Alloc>::_vector_base(_size_type size, const _Tp &value, const _Alloc &alloc) : _size(size), _mem(alloc) ,_capacity(size * DFLT_SCALE)
    {
        _start = _mem.allocate(_capacity);
        for (_size_type i = 0; i < size; i++)
            _mem.construct(&_start[i], value);
    }

    /**
 * @brief Construct a new vector base
 * @param copy  a vector to duplicate
 */
    template <typename _Tp, typename _Alloc>
    _vector_base<_Tp, _Alloc>::_vector_base(const _vector_base &copy) : _size(copy._size), _capacity(copy._size)
    {
        _start = _mem.allocate(copy._size);
        std::uninitialized_copy(copy._start, copy._start + copy._size, _start);
    }

/**
 * @brief   de-allocate helper 
 */
    template <typename _Tp, typename _Alloc>
    void
    _vector_base<_Tp, _Alloc>::_dealloc()
    {
        for (_size_type i = 0; i < _size; i++)
            _mem.destroy(_start + i);
        _mem.deallocate(_start, _capacity);
    }
    /**
 * @brief   Empty allocation helper
 */
    template <typename _Tp, typename _Alloc>
    void
    _vector_base<_Tp, _Alloc>::_realloc_empty(_size_type size)
    {
        _mem.deallocate(_start, _capacity);
        _start = _mem.allocate(size);
    }

    /**
 * @brief allocation helper
 * @param 
 */
    template <typename _Tp, typename _Alloc>
    void
    _vector_base<_Tp, _Alloc>::_realloc(_size_type size)
    {
        if (_size == 0)
        {
            _realloc_empty(size);
            _size = size;
        }
        else
        {
            _Tp *temp = _mem.allocate(size);
            std::uninitialized_copy(_start, _start + _size, temp);
            _dealloc();
            _start = temp;
            _capacity = size;
        }
    }

    /**
 * @brief reallocated and copy in value
 */
    template <typename _Tp, typename _Alloc>
    void
    _vector_base<_Tp, _Alloc>::_realloc_fill(_size_type new_size, const _Tp &value)
    {
        if (this->_size == 0)
            _realloc_empty(new_size);
        else
        {
            _Tp *temp = this->_mem.allocate(new_size);
            _size_type old_size(_size);
            std::uninitialized_copy(_start, _start + _size, temp);
            _dealloc();
            _start = temp;
            std::uninitialized_fill(_start + old_size, _start + new_size, value);
            _size = new_size;
            _capacity = new_size;
        }
    }

/**
 * @brief 
 * 
 */
    template <typename _Tp, typename _Alloc>
    void
    _vector_base<_Tp, _Alloc>::_move(_size_type n, _iterator start, _iterator end)
    {
        for (_iterator i = end; i >= start; --i)
        {
            _mem.construct(i + n, *i);
            _mem.destroy(i);
        }
    }


    /**
 * @brief 
 */
    template <typename _Tp, typename _Alloc>
    void
    _vector_base<_Tp, _Alloc>::_insert_back(const _Tp &value)
    {
        _size_type nsize;
        if (_size * DFLT_SCALE < _mem.max_size())
            nsize = _size * DFLT_SCALE;
        else
            nsize = _mem.max_size();
        _Tp* tmp = _mem.allocate(nsize);
        std::uninitialized_copy(_start, _start + _size, tmp);
        _dealloc();
        _capacity = nsize;
        _start = tmp;
        _mem.construct(_start + _size, value);
    }

    /**
 * @brief 
 */
    template <typename _Tp, typename _Alloc>
    void
    _vector_base<_Tp, _Alloc>::_range_check(_size_type n) const
    {
        if (n > _mem.max_size())
            throw std::out_of_range("vector");
    }
    /**
 * @brief 
 */
    template <typename _Tp, typename _Alloc>
    void
    _vector_base<_Tp, _Alloc>::_bounds_check(_size_type n) const
    {
        if (n > _size)
            throw std::out_of_range("vector");
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