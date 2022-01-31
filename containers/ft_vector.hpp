/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:32:40 by satchmin          #+#    #+#             */
/*   Updated: 2022/01/31 08:59:34 by sshakya          ###   ########.fr       */
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
// custom iterator
#include "vector.iterator.hpp"
#include "ft_vector_base.hpp"

// NAMESPACE
namespace ft
{
    template <typename _Tp, typename _Alloc = std::allocator<_Tp> >
    class vector : protected _vector_base<_Tp, _Alloc>
    {
    public:
        typedef _Tp value_type;
        typedef _Alloc allocator_type;
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;
        typedef _Tp *iterator;
        typedef const _Tp *const_iterator;
        typedef ft::reverse_iterator<iterator> reverse_iterator;
        typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
        typedef typename _Alloc::pointer pointer;
        typedef typename _Alloc::reference reference;
        typedef typename _Alloc::const_reference const_reference;

    public:
/**
 *  CONSTRUCTORS
 */
        vector() : _vector_base<_Tp, _Alloc>() {}                                            // default
        vector(size_type size, const _Tp &value) : _vector_base<_Tp, _Alloc>(size, value) {} // size and value
        vector(const vector<_Tp, _Alloc> &copy) : _vector_base<_Tp, _Alloc>(copy) {}         // copy
        template <class InputIterator>
        vector(InputIterator first, InputIterator last); // range
        ~vector();
/**
 *  ASSIGNEMENT OPERATOR
 */
        vector &operator=(const vector &x);

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
        reverse_iterator        rend(); // points to one-past-Iast element ofreverse sequence
        const_reverse_iterator  rend() const;

/*
 *  ACCESSORS
 */
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
            void    insert(iterator position, _Iterator first, _Iterator last);
        iterator    erase(iterator position);
        iterator    erase(iterator first, iterator last);
        void        swap(vector &val);
        void        clear();
        allocator_type  get_allocator() const;
    };

} // END NAMESPACE

#include "ft_vector.cpp"

#endif // FT_VECTOR_HPP