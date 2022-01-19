/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satchmin <satchmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 04:02:51 by satchmin          #+#    #+#             */
/*   Updated: 2022/01/19 04:15:45 by satchmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft {
    template<typename T, bool B>
    class vector_iterator
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
            vector_iterator(T* val = 0) : _val(val) {}
            vector_iterator(const vector_iterator<T, false> &copy) { _val = copy.getElemPtr();}
            
    }   
}