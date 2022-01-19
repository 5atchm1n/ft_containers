/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satchmin <satchmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:32:40 by satchmin          #+#    #+#             */
/*   Updated: 2022/01/18 17:07:13 by satchmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <memory>
#include <iterator>

namespace   ft
{
    template <class T, class A = std::allocator<T>>
    class vector
    {
        public:
            typedef T value_type;
            typedef A allocator_type;
            typedef typename A::size_t size_type;
            typedef typename A::ptrdiff_t difference_type;
            typedef T* iterator;
            typedef const T* const_iterator;
            typedef std::reverse_iterator<iterator> reverse_iterator;
            typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
            typedef typename A::pointer pointer;
            typedef typename A::reference reference;
            typedef typename A::const_reference const_reference;

            iterator begin (); //points to first element
            const_iterator begin () const;
            iterator end (); //points to one-past last element
            const_iterator end () const;
            reverse_iterator rbegin () ; // points to first element ofreverse sequence
            const_reverse_iterator rbegin () const;
            reverse_iterator rend () ; // points to one-past-Iast element ofreverse sequence
            const_reverse_iterator rend () const;
    };
} 