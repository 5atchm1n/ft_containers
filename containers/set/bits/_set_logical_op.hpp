/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _set_logical_op.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:08:37 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/10 17:05:05 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SET_LOGICAL_OP_HPP
#define _SET_LOGICAL_OP_HPP

/**
 * @brief Non Member overloads for logical operators
 * 
 */

namespace ft
{
    template <typename _Key, typename _Cmp, typename _Alloc>
	bool
	operator==(set<_Key, _Cmp, _Alloc> const &lhs,	set<_Key, _Cmp, _Alloc> const &rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		return (std::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <typename _Key, typename _Cmp, typename _Alloc>
	bool
	operator<(set<_Key, _Cmp, _Alloc> const &lhs, set<_Key, _Cmp, _Alloc> const &rhs)
	{
		return (std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <typename _Key, typename _Cmp, typename _Alloc>
	bool
	operator!=(set<_Key, _Cmp, _Alloc> const &lhs, set<_Key, _Cmp, _Alloc> const &rhs)
	{
		return (!(lhs == rhs));
	}

	template <typename _Key, typename _Cmp, typename _Alloc>
	bool
	operator>(set<_Key, _Cmp, _Alloc> const &lhs, set<_Key, _Cmp, _Alloc> const &rhs)
	{
		return (rhs < lhs);
	}

	template <typename _Key, typename _Cmp, typename _Alloc>
	bool
	operator<=(set<_Key, _Cmp, _Alloc> const &lhs, set<_Key, _Cmp, _Alloc> const &rhs)
	{
		return (!(rhs < lhs));
	}

	template <typename _Key, typename _Cmp, typename _Alloc>
	bool
	operator>=(set<_Key, _Cmp, _Alloc> const &lhs, set<_Key, _Cmp, _Alloc> const &rhs)
	{
		return (!(lhs < rhs));
	}

	template <typename _Key, typename _Cmp, typename _Alloc>
	void
	swap(set<_Key, _Cmp, _Alloc> &lhs, set<_Key, _Cmp, _Alloc> &rhs)
	{
		lhs.swap(rhs);
	}
}   // END NAMESPACE FT

#endif  // _SET_LOGICAL_OP_HPP