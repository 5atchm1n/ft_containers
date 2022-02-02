/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satchmin <satchmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:32:40 by satchmin          #+#    #+#             */
/*   Updated: 2022/02/02 01:12:33 by satchmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP
// STD library
#include <cstddef>
#include <memory>
#include <limits>
#include <stdexcept>
#include <iostream>
#include <algorithm>
// custom iterator
#include "vector.iterator.hpp"
#include "ft_type_traits.hpp"
#include "vector/base/_vector_base.hpp"

// NAMESPACE
namespace ft
{
    template <typename _Tp, typename _Alloc = std::allocator<_Tp> >
    class vector : protected _vector_base<_Tp, _Alloc>
    {
    public:
        typedef _Tp                                     value_type;
        typedef _Alloc                                  allocator_type;
        typedef size_t                                  size_type;
        typedef ptrdiff_t                               difference_type;
        typedef _Tp*                                    iterator;
        typedef const _Tp                               *const_iterator;
        typedef ft::reverse_iterator<iterator>          reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>    const_reverse_iterator;
        typedef typename _Alloc::pointer                pointer;
        typedef typename _Alloc::reference              reference;
        typedef typename _Alloc::const_reference        const_reference;
        
    public:
/**
 *  CONSTRUCTORS
 */
        explicit vector() : _vector_base<_Tp, _Alloc>() {}                                            // default
        explicit vector(size_type size,
                        const value_type &val = value_type(),
                        const allocator_type& alloc = allocator_type());
        template <typename _Iterator>
        vector(_Iterator first, _Iterator last,
                typename ft::enable_if<!ft::is_integral<_Iterator>::value >::type* = 0); // range
        vector( const vector &copy ) : _vector_base<_Tp, _Alloc>(copy) {}
        vector          &operator=(const vector &x);
/**
 *  DESTRUCTOR
 */
        ~vector();

/**
 *   METHODS 
 */
        size_type   size() const;
        size_type   max_size() const;
        void        resize(size_type size, value_type val = value_type());
        bool        empty() const;
        void        reserve(size_type n);
        size_type   capacity() const;

/*
 *  ITERATORS
 */
        iterator                begin();
        const_iterator          begin() const;
        iterator                end();
        const_iterator          end() const;
        reverse_iterator        rbegin();
        const_reverse_iterator  rbegin() const;
        reverse_iterator        rend();
        const_reverse_iterator  rend() const;

/*
 *  ACCESSORS
 */
        reference       operator[](size_type n);
        const_reference operator[](size_type n) const;
        reference       at(size_type size);
        const_reference at(size_type size) const;
        reference       front();
        const_reference front() const;
        reference       back();
        const_reference back() const;
/**
 *  MODIFIERS
 */
        template <typename _Iterator>
            void    assign(_Iterator first, _Iterator last);
        void        assign(size_type n, const value_type &val);
        void        push_back(const value_type &val);
        void        pop_back();
        iterator    insert(iterator position, const value_type &val);
        void        insert(iterator position, size_type n, const value_type &val);
        template <typename _Iterator>
            void    insert(iterator position, _Iterator first, _Iterator last, typename ft::enable_if<!ft::is_integral<_Iterator>::value >::type* = 0 );
        iterator    erase(iterator position);
        iterator    erase(iterator first, iterator last);
        void        swap(vector &val);
        void        clear();
        allocator_type  get_allocator() const;
    };

} // END NAMESPACE

#include "vector/bits/vector_basic.cpp"
#include "vector/bits/vector_iterators.cpp"
#include "vector/bits/vector_accessors.cpp"
#include "vector/bits/vector_capacity.cpp"
#include "vector/bits/vector_modifiers.cpp"

#endif // FT_VECTOR_HPP