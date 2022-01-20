/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.iterator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 04:02:51 by satchmin          #+#    #+#             */
/*   Updated: 2022/01/20 19:52:53 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.iterator.hpp"

namespace ft {
	
	// COPLIEN FORM [ COPY ]
	template<typename T, bool B>
		vectorIterator<T, B>::vectorIterator(const vectorIterator<T, false> &copy)
		{
			_val = copy.getElemPtr();
		}

	// COPLIEN FORM [ ASSIGN ]
	template<typename T, bool B>
		vectorIterator<T, B>::value_type
		vectorIterator<T, B>::operator=(const vectorIterator<T, false> &assign)
		{
			if (this != &assign)
				_val = assign._val;
			return (*this);
		}
		
	// GET VALUE POINTER
	template<typename T, bool B>
		vectorIterator<T, B>::element_pointer
		vectorIterator<T, B>::getPointer(void) const
		{
			return (_val);
		}

	// OPERATOR [ * ] => return value
	template<typename T, bool B>
		vectorIterator<T, B>::value_type
		vectorIterator<T, B>::operator*(void) const
		{
			return (*_val);
		}

	// OPERATOR [ -> ] => return pointer
	template<typename T, bool B>
		vectorIterator<T, B>::element_pointer
		vectorIterator<T, B>::operator->(void) const
		{
			return (_val);
		}
	
	// OPERATOR [ * ] -> return value
	template<typename T, bool B>
		vectorIterator<T, B>::value_type
		vectorIterator<T, B>::operator++(void)
		{
			vectorIterator<T, B> temp(*this);
			++(*this);
			return (temp);
		}
	
	template<typename T, bool B>
		bool vectorIterator<T, B>::operator==(const vectorIterator &other) const
		{
			return (_val == other._val);
		}
	
	template<typename T, bool B>
		bool vectorIterator<T, B>::operator!=(const vectorIterator &other) const
		{
			return (!(_val == other._val));
		}

	template<typename T, bool B>
		bool vectorIterator<T, B>::operator<=(const vectorIterator &other) const
		{
			return (_val <= other._val);
		}
}