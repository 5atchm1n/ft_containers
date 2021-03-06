/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 14:02:42 by satchmin          #+#    #+#             */
/*   Updated: 2022/03/10 02:32:46 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iterator_traits.hpp"

#ifndef VECTOR_ITERATOR_H
#define VECTOR_ITERATOR_H

namespace ft
{

template<typename _Iterator>
    class reverse_iterator
    {
        protected:
            _Iterator current;
            typedef iterator_traits<_Iterator>  __traits_type;

        public:
            typedef _Iterator   iterator_type;
            typedef typename __traits_type::difference_type difference_type;
            typedef typename __traits_type::pointer pointer;
            typedef typename __traits_type::reference reference;
            
            /*
            ** CONTRUCTORS
            */
            reverse_iterator() : current() { }; // default constructor
            explicit reverse_iterator(iterator_type __x) : current(__x) { } // Iterator constructor
            reverse_iterator(const reverse_iterator& __x) : current(__x.current) { } // Reverse constructor
            template <typename _IteratorOther>
            reverse_iterator(const reverse_iterator<_IteratorOther>& __x) : current(__x.base()) { } // Reverse constructor
            
           
            // Basic operators
            iterator_type base() const;
            reference operator*() const;
            pointer operator->() const;

            reverse_iterator& operator=(const reverse_iterator& __x);
            
            reverse_iterator& operator++();
            reverse_iterator operator++(int);
            reverse_iterator& operator--();
            reverse_iterator operator--(int);
            reverse_iterator operator+(difference_type __n);
            reverse_iterator &operator+=(difference_type __n);      
            reverse_iterator operator-(difference_type __n);
            reverse_iterator &operator-=(difference_type __n);      
            reference operator[](difference_type __n);

    };
}

#include "reverse_iterator.cpp"

#endif // VECTOR_ITERATOR_H