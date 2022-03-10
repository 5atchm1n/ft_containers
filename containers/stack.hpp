/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 03:19:57 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/10 03:45:55 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft
{
    
template <typename _Tp, typename _Cnt = ft::vector<_Tp> >
class stack
{
    public:
        typedef _Cnt    container_type;
        typedef typename container_type::value_type value_type;
        typedef typename container_type::size_type  size_type;
        
        template <typename Tp, typename Cnt>
            friend bool ft::operator==(stack<Tp, Cnt> const &x, stack<Tp, Cnt> const &y);
        template <typename Tp, typename Cnt>
            friend bool ft::operator<(stack<Tp, Cnt> const &x, stack<Tp, Cnt> const &y);
    
    protected:
        container_type _cnt;
    
    public:
        explicit stack(container_type const &cnt = container_type ()) : _cnt(cnt) {}
        
        bool                empty() const { return _cnt.empty(); }
        size_type           size() const { return _cnt.size(); }
        value_type          &top() { return _cnt.back(); }
        const value_type    &top() const { return _cnt.back(); }
        void                push(value_type const &val) { _cnt.push_back(val); }
        void                pop() { _cnt.pop_back(); }
};

template <typename _Tp, typename _Cnt>
bool
operator==(stack<_Tp, _Cnt> const &x, stack<_Tp, _Cnt> const &y)
{
    return x._cnt == y._cnt;
}

template <typename _Tp, typename _Cnt>
bool
operator<(stack<_Tp, _Cnt> const &x, stack<_Tp, _Cnt> const &y)
{
    return x._cnt < y._cnt;
}

template <typename _Tp, typename _Cnt>
bool
operator!=(stack<_Tp, _Cnt> const &x, stack<_Tp, _Cnt> const &y)
{
    return !(x == y);
}

template <typename _Tp, typename _Cnt>
bool
operator>(stack<_Tp, _Cnt> const &x, stack<_Tp, _Cnt> const &y)
{
    return y < x;
}

template <typename _Tp, typename _Cnt>
bool
operator<=(stack<_Tp, _Cnt> const &x, stack<_Tp, _Cnt> const &y)
{
    return !(y < x);
}

template <typename _Tp, typename _Cnt>
bool
operator>=(stack<_Tp, _Cnt> const &x, stack<_Tp, _Cnt> const &y)
{
    return !(x < y);
}

}   // END NAMESPACE FT

#endif  // END STACK_HPP