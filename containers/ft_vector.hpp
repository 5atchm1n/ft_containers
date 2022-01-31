/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satchmin <satchmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:32:40 by satchmin          #+#    #+#             */
/*   Updated: 2022/01/31 02:44:06 by satchmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP
// STD library
#include <cstddef>
#include <memory>
// custom iterator
#include "vector.iterator.hpp"
#include "ft_vector_base.hpp"


// NAMESPACE
namespace   ft
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
            typedef const _Tp*                              const_iterator;
            typedef ft::reverse_iterator<iterator>          reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>    const_reverse_iterator;
            typedef typename _Alloc::pointer                pointer;
            typedef typename _Alloc::reference              reference;
            typedef typename _Alloc::const_reference        const_reference;

        public:
            /***
            *   CONSTRUCTORS
            */
            vector() : _vector_base<_Tp, _Alloc>() {} // default
            vector(size_type size, const _Tp& value) : _vector_base<_Tp, _Alloc>(size, value) {}// size and value
            vector (const vector<_Tp, _Alloc>& copy) : _vector_base<_Tp, _Alloc>(copy) {} // copy
            template <class InputIterator>
                vector (InputIterator first, InputIterator last); // range
            ~vector(); 
            /***
            *   ASSIGNEMENT OPERATOR
            */
            vector& operator=(const vector& x);

            /**
            *   METHODS 
            */
            void    reserve (size_type n);
            size_type capacity () const;
            size_type size () const;
            bool    empty() const;
            size_type max_size() const;
           
            /*
            *   ITERATORS
            */
            iterator begin ();
            const_iterator begin () const;
            iterator end ();
            const_iterator end () const;
            reverse_iterator rbegin ();
            const_reverse_iterator rbegin () const; 
            reverse_iterator rend () ; // points to one-past-Iast element ofreverse sequence
            const_reverse_iterator rend () const;
    };

} // END NAMESPACE

#include "ft_vector.cpp"

#endif // FT_VECTOR_HPP