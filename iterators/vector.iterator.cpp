/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.iterator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satchmin <satchmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 14:31:00 by satchmin          #+#    #+#             */
/*   Updated: 2022/01/23 14:43:49y satchmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.iterator.hpp"

namespace ft
{

/*
** BASE() method to access current element
*/

template<typename _Iterator>
    _Iterator
    reverse_iterator<_Iterator>::base(void) const
    {
        return current;   
    }

/*
** Define ' * ' to access the one-before 
** element that we are currently pointing to.
*/

template<typename _Iterator>
    typename reverse_iterator<_Iterator>::reference
    reverse_iterator<_Iterator>::operator*() const
    {
        _Iterator __tmp = current;
        return *--__tmp;
    }

/*
** Define ' -> ' to return the address returned
** by the operator ' * ' - the one-before element
** that we are currently pointing to.
*/

template<typename _Iterator>
   typename reverse_iterator<_Iterator>::pointer
    reverse_iterator<_Iterator>::operator->() const
    {
        return (&(operator*()));
    }

/*
** ASSIGNATION OPERATOR ' = ' 
*/
template<typename _Iterator>
    reverse_iterator<_Iterator>
    &reverse_iterator<_Iterator>::operator=(const reverse_iterator& __x)
    {
        if (this != &__x)
            current = __x.current;
        return (*this);
    }

/*
** define ' [ ] ' to return the object pointed to by
** the current iterator
*/

template<typename _Iterator>
    typename reverse_iterator<_Iterator>::reference
    reverse_iterator<_Iterator>::operator[](difference_type __n) const
    {
        return *(*this + __n);
    }

/*
** INCREMENT - reversed as this is a reverse iterator
*/
// pre-increment
template<typename _Iterator>
    reverse_iterator<_Iterator>
    &reverse_iterator<_Iterator>::operator++()
    {
        --current;
        return *this;
    }
// post-increment
template<typename _Iterator>
    reverse_iterator<_Iterator>
    reverse_iterator<_Iterator>::operator++(int)
    {
        reverse_iterator    __tmp = *this;
        --current;
        return __tmp;
    }

/*
** DECREMENT - again reversed
*/
// pre-decrement
template<typename _Iterator>
    reverse_iterator<_Iterator>
    &reverse_iterator<_Iterator>::operator--()
    {
        ++current;
        return *this;
    }
// post-decrement
template<typename _Iterator>
    reverse_iterator<_Iterator>
    reverse_iterator<_Iterator>::operator--(int)
    {
        reverse_iterator    __tmp = *this;
        ++current;
        return __tmp;
    }

/*
** ADDITION - reversed as this is a reverse iterator
*/

template<typename _Iterator>
    reverse_iterator<_Iterator>
    reverse_iterator<_Iterator>::operator+(difference_type __n)
    {
        return reverse_iterator(current - __n);
    }

template<typename _Iterator>
    reverse_iterator<_Iterator>
    &reverse_iterator<_Iterator>::operator+=(difference_type __n)
    {
        current -= __n;
        return *this;
    }

/*
** defining an operation such as :
**       _Iterator = difference_type + _Iterator
*/

template<typename _Iterator>
    inline reverse_iterator<_Iterator>
    operator+(typename reverse_iterator<_Iterator>::difference_type __n,
              const reverse_iterator<_Iterator>& __x)
    {
        return reverse_iterator<_Iterator>(__x.base() - __n);
    }
/*
** SUBTRACTION - reversed as this is a reverse iterator
*/

template<typename _Iterator>
    reverse_iterator<_Iterator>
    reverse_iterator<_Iterator>::operator-(difference_type __n)
    {
        return reverse_iterator(current + __n);
    }

template<typename _Iterator>
    reverse_iterator<_Iterator>
    &reverse_iterator<_Iterator>::operator-=(difference_type __n)
    {
        current += __n;
        return *this;
    }

/*
** Defining operation such as :
**      difference_type = _IteratorX - IteratorY
*/

  template<typename _Iterator>
    inline typename reverse_iterator<_Iterator>::difference_type
    operator-(const reverse_iterator<_Iterator>& __x,
              const reverse_iterator<_Iterator>& __y)
    {
        return __y.base() - __x.base();
    }
  
/*
** Defining operation such as :
**      difference_type = _Iterator<type_X> - Iterator<type_Y>
*/
  template<typename _IteratorL, typename _IteratorR>
    inline typename reverse_iterator<_IteratorL>::difference_type
    operator-(const reverse_iterator<_IteratorL>& __x,
              const reverse_iterator<_IteratorR>& __y)
    {
        return __y.base() - __x.base();
    }
  
/*
** LOGICAL OPERATORS
** These will all return a BOOL
** const vs const || non-const vs non-const
*/

template<typename _Iterator>
    bool
    operator==(const reverse_iterator<_Iterator>& __x, const reverse_iterator<_Iterator>& __y)
    {
        return __x.base() == __y.base();
    }

template<typename _Iterator>
    bool
    operator<(const reverse_iterator<_Iterator>& __x, const reverse_iterator<_Iterator>& __y)
    {
        return __y.base() < __x.base();
    }

template<typename _Iterator>
    bool
    operator!=(const reverse_iterator<_Iterator>& __x, const reverse_iterator<_Iterator>& __y)
    {
        return !(__x == __y);
    }

template<typename _Iterator>
    bool
    operator<=(const reverse_iterator<_Iterator>& __x, const reverse_iterator<_Iterator>& __y)
    {
        return !(__y < __x);
    }

template<typename _Iterator>
    bool
    operator>(const reverse_iterator<_Iterator>& __x, const reverse_iterator<_Iterator>& __y)
    {
        return __y < __x;
    }

template<typename _Iterator>
    bool
    operator>=(const reverse_iterator<_Iterator>& __x, const reverse_iterator<_Iterator>& __y)
    {
        return !(__x < __y);
    }

/*
** LOGICAL OPERTORS
** These all return a BOOL
** const vs non-const
*/

template<typename _IteratorL, typename _IteratorR>
    bool
    operator==(const reverse_iterator<_IteratorL>& __x, const reverse_iterator<_IteratorR>& __y)
    {
        return __x.base() == __y.base();
    }

template<typename _IteratorL, typename _IteratorR>
    bool
    operator<(const reverse_iterator<_IteratorL>& __x, const reverse_iterator<_IteratorR>& __y)
    {
        return __y.base() < __x.base();
    }

template<typename _IteratorL, typename _IteratorR>
    bool
    operator!=(const reverse_iterator<_IteratorL>& __x, const reverse_iterator<_IteratorR>& __y)
    {
        return !(__x == __y);
    }

template<typename _IteratorL, typename _IteratorR>
    bool
    operator<=(const reverse_iterator<_IteratorL>& __x, const reverse_iterator<_IteratorR>& __y)
    {
        return !(__y < __x);
    }

template<typename _IteratorL, typename _IteratorR>
    bool
    operator>(const reverse_iterator<_IteratorL>& __x, const reverse_iterator<_IteratorR>& __y)
    {
        return __y < __x;
    }

template<typename _IteratorL, typename _IteratorR>
    bool
    operator>=(const reverse_iterator<_IteratorL>& __x, const reverse_iterator<_IteratorR>& __y)
    {
        return !(__x < __y);
    }
}