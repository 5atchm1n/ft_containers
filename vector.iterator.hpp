/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 04:02:51 by satchmin          #+#    #+#             */
/*   Updated: 2022/01/20 18:43:27 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft {
    template<typename T, bool B>
    class vectorIterator
    {
        public:
            typedef ptrdiff_t difference_type;
            typedef T value_type;
            typedef size_t size_type;
            
            typedef std::random_access_iterator_tag iterator_category;
            typedef typename chooseConst<B, T&, const T&>::type reference;
            typedef typename chooseConst<B, T*, const T*>::type pointer;
            typedef typename T* element_pointer;
        private:
            T* _val;
        public:
			//Coplien
            vectorIterator(T* val = 0) : _val(val) {}
			vectorIterator(const vectorIterator<T, false> &copy);
			value_type operator=(const vectorIterator<T, false> &assign);
			// Destructor
			~vectorIterator<T, B>(){}
			//Get pointer
			element_pointer	getPointer(void) const;
			//operator
			value_type operator*(void) const;
			element_pointer operator->(void) const;
			value_type operator++(void);
			
    };
	
}