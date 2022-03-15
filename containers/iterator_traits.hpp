/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 13:55:48 by satchmin          #+#    #+#             */
/*   Updated: 2022/03/15 17:37:39 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iterator>
#include <cstddef>

/**
*  Traits class for iterators.
*
*  This class does nothing but define nested typedefs.  The general
*  version simply forwards the nested typedefs from the Iterator
*  argument.  Specialized versions for pointers and pointers-to-const
*  provide tighter, more correct semantics.
*/
#ifndef ITERATOR_TRAITS_H
#define ITERATOR_TRAITS_H

namespace ft
{

template<typename _Iterator>
    struct iterator_traits
    {
        typedef typename _Iterator::iterator_category iterator_category;
        typedef typename _Iterator::value_type        value_type;
        typedef typename _Iterator::difference_type   difference_type;
        typedef typename _Iterator::pointer           pointer;
        typedef typename _Iterator::reference         reference;
    };

/// Partial specialization for pointer types.

template<typename _Tp>
    struct iterator_traits<_Tp*>
    {
        typedef std::random_access_iterator_tag iterator_category;
        typedef _Tp                         value_type;
        typedef ptrdiff_t                   difference_type;
        typedef _Tp*                        pointer;
        typedef _Tp&                        reference;
    };

/// Partial specialization for const pointer types.

template<typename _Tp>
    struct iterator_traits<const _Tp*>
    {
        typedef std::random_access_iterator_tag iterator_category;
        typedef _Tp                         value_type;
        typedef ptrdiff_t                   difference_type;
        typedef const _Tp*                  pointer;
        typedef const _Tp&                  reference;
    };

}
#endif  // ITERATOR_TRAITS_H