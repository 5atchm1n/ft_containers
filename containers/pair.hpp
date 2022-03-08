/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:06:52 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/08 23:53:28 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <memory>

#ifndef FT_PAIR_HPP
#define FT_PAIR_HPP

namespace ft
{

template <typename _T1, typename _T2>
struct pair
{
    typedef _T1 first_type;
    typedef _T2 second_type;

    _T1 first;
    _T2 second;

    pair() : first(), second() {}
    pair(const _T1 &fval, const _T2 &sval) : first(fval), second(sval) {}
    template <typename _U1, typename _U2>
    pair(const pair<_U1, _U2> &val) : first(val.first) , second(val.second) {}

    pair    &operator=(const pair &val)
    {
        first = val.first;
        second = val.second;
        return *this;
    }

};

template <typename _T1, typename _T2>
inline bool operator==(const pair<_T1, _T2> &x, const pair<_T1, _T2> &y)
{
    return x.first == y.first && x.second == y.second;
}

template <typename _T1, typename _T2>
inline bool operator!=(const pair<_T1, _T2> &x, const pair<_T1, _T2> &y)
{
    return !(x == y);
}

template <typename _T1, typename _T2>
inline bool operator<(const pair<_T1, _T2> &x, const pair<_T1, _T2> &y)
{
    return x.first < y.first || (!(y.first<x.first) && x.second<y.second);
}

template <typename _T1, typename _T2>
inline bool operator<=(const pair<_T1, _T2> &x, const pair<_T1, _T2> &y)
{
    return !(y < x);
}

template <typename _T1, typename _T2>
inline bool operator>(const pair<_T1, _T2> &x, const pair<_T1, _T2> &y)
{
    return y < x;
}

template <typename _T1, typename _T2>
inline bool operator>=(const pair<_T1, _T2> &x, const pair<_T1, _T2> &y)
{
    return !(x < y);
}

template <typename _T1, typename _T2>
inline pair<_T1, _T2>
make_pair(_T1 x, _T2 y)
{
    return pair<_T1, _T2>(x, y);
}

template <typename _T1, typename _T2>
std::ostream &operator<<(std::ostream &os, const pair<_T1, _T2> &val)
{
    os << "key = " << val.first;
    os << " value = " << val.second;
    return os;
}

}  // END NAMESPACE FT

#endif  // FT_PAIR_HPP