/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _vector_base.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 15:36:28 by satchmin          #+#    #+#             */
/*   Updated: 2022/03/01 16:19:10 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_BASE_HPP
#define FT_VECTOR_BASE_HPP

#include <memory>
#include <cstddef>
#include <stdexcept>

#define DFLT_CAPACITY 1
#define DFLT_SCALE 2
#define DFLT_REFACTOR 3

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

*****************************************************************/
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

        explicit _vector_base(const _alloc_type & alloc = _alloc_type());
        _vector_base(_size_type size, const _Tp& value = _Tp(), const _Alloc &val = _Alloc());
        _vector_base(const _vector_base<_Tp, _Alloc> &copy);
        
        _vector_base& operator=(const _vector_base &val);

        ~_vector_base();

    protected:
        void _dealloc();
        void _reserve(_size_type size);
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
_vector_base<_Tp, _Alloc>::_vector_base(const _alloc_type & alloc) :
_start(0),
_size(0),
_mem(alloc),
_capacity(0)
{}

/**
 * @brief Construct a new vector base object
 * @param size  the size of the of vector
 * @param value the value to fill
 */
template <typename _Tp, typename _Alloc>
_vector_base<_Tp, _Alloc>::_vector_base(_size_type size, const _Tp &value, const _Alloc &alloc) :
_mem(alloc)
{
    _range_check(size);
    if (size)
        _reserve(size);
    _start = NULL;
    for (_size_type i = 0; i < size; i++)
        _mem.construct(&_start[i], value);
}
/**
 * @brief Construct a new vector base
 * @param copy  a vector to duplicate
 */
template <typename _Tp, typename _Alloc>
_vector_base<_Tp, _Alloc>::_vector_base(const _vector_base &copy) : _size(copy._size), _capacity(copy._capacity)
{
    _start = NULL;
    if (copy._capacity)
        _start = _mem.allocate(_capacity);
    if (copy._capacity)
        std::uninitialized_copy(copy._start, copy._start + copy._size, _start);
}
/**
 * @brief   de-allocate helper 
 */
template <typename _Tp, typename _Alloc>
void
_vector_base<_Tp, _Alloc>::_dealloc()
{
    if (_capacity)
    {
        for (_size_type i = 0; i < _size; i++)
            _mem.destroy(_start + i);
        _mem.deallocate(_start, _capacity);
    }
    _capacity = 0;
    _size = 0;
}
/**
 * @brief   Empty allocation helper
 */
template <typename _Tp, typename _Alloc>
void
_vector_base<_Tp, _Alloc>::_reserve(_size_type size)
{
    _range_check(size);
    _start = _mem.allocate(size);
    _capacity = size;
}
/**
 * @brief allocation helper
 * @param 
 */
template <typename _Tp, typename _Alloc>
void
_vector_base<_Tp, _Alloc>::_realloc(_size_type size)
{
    _Tp *temp = _mem.allocate(size);
    std::uninitialized_copy(_start, _start + _size, temp);
    _dealloc();
    _start = temp;
    _capacity = size;
}

/**
 * @brief reallocated and copy in value
 */
template <typename _Tp, typename _Alloc>
void
_vector_base<_Tp, _Alloc>::_realloc_fill(_size_type new_size, const _Tp &value)
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
/**
 * @brief 
 * 
 */
template <typename _Tp, typename _Alloc>
void
_vector_base<_Tp, _Alloc>::_move(_size_type n, _iterator start, _iterator end)
{
    _iterator i = end;
    while (i != start)
    {
        _mem.construct(i + n, *i);
        _mem.destroy(i--);
    }
}
/**
 * @brief 
 */
template <typename _Tp, typename _Alloc>
void
_vector_base<_Tp, _Alloc>::_insert_back(const _Tp &value)
{
    if (!_capacity)
    {
        _start = _mem.allocate(DFLT_CAPACITY);
        _mem.construct(_start, value);
        _capacity = DFLT_CAPACITY;
        return ;
    }
    if (_size + 1 <= this->_capacity)
    {
        _mem.construct(_start + _size, value);
        return ;
    }
     _size_type nsize;
     _size_type osize = _size;
    _range_check(_size + 1);
    nsize = _size + 1;
    if (_size * DFLT_SCALE / DFLT_REFACTOR < _mem.max_size())
        nsize = _size * DFLT_SCALE / DFLT_REFACTOR;
    if (_size * DFLT_SCALE < _mem.max_size())
        nsize = _size * DFLT_SCALE;
    _iterator tmp;
    tmp = _mem.allocate(nsize);
    std::uninitialized_copy(_start, _start + _size, tmp);
    _mem.construct(tmp + osize, value);    
    _dealloc();
    _capacity = nsize;
    _start = tmp;
    _size = osize;
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
        if (_capacity)
            _mem.deallocate(_start, _capacity);
    }

} // end namespace

#endif // FT_VECTOR_BASE_HPP