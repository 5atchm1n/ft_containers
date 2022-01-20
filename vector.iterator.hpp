/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 04:02:51 by satchmin          #+#    #+#             */
/*   Updated: 2022/01/20 19:48:26 by sshakya          ###   ########.fr       */
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
			// POINTER AND REFERENCE
			value_type operator*(void) const;
			element_pointer operator->(void) const;
			// INCREMENT
            value_type operator++(void);
            // DECREMENT
            value_type operator--(void);
            // COMPARISON
            bool operator==(const vectorIterator &other) const;
            bool operator!=(const vectorIterator &other) const;
            bool operator<=(const vectorIterator &other) const;
            bool operator>=(const vectorIterator &other) const;
            bool operator<(const vectorIterator &other) const;
            bool operator>(const vectorIterator &other) const;
			
    };
	
}