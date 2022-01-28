/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satchmin <satchmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:32:40 by satchmin          #+#    #+#             */
/*   Updated: 2022/01/28 01:45:05 by satchmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP
// STD library
#include <cstddef>
// custom iterator
#include "vector.iterator.hpp"
#include "ft_vector_base.hpp"

// NAMESPACE
namespace   ft
{
    template <typename _Tp, typename _Alloc = std::allocator<_Tp> >
    class vector : protected _Vector_base<_Tp, _Alloc>
    {
        public:
            typedef _Tp value_type;
            typedef _Alloc allocator_type;
            typedef size_t size_type;
            typedef ptrdiff_t difference_type;
            typedef _Tp* iterator;
            typedef const _Tp* const_iterator;
            typedef ft::reverse_iterator<iterator> reverse_iterator;
            typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
            typedef typename _Alloc::pointer pointer;
            typedef typename _Alloc::reference reference;
            typedef typename _Alloc::const_reference const_reference;

            iterator begin (); //points to first element
            const_iterator begin () const;
            iterator end (); //points to one-past last element
            const_iterator end () const;
            reverse_iterator rbegin () ; // points to first element ofreverse sequence
            const_reverse_iterator rbegin () const;
            reverse_iterator rend () ; // points to one-past-Iast element ofreverse sequence
            const_reverse_iterator rend () const;
    };
} // END NAMESPACE 