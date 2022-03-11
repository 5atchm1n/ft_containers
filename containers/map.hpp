/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 01:00:11 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/11 03:20:51 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MAP_HPP
#define _MAP_HPP

#include "_rbtree/_red_black_tree.hpp"
#include <functional>
#include "pair.hpp"

namespace ft
{
/**
 * @brief   A standard container made up of (key,value) pairs, which can be
 *          retrieved based on a key, in logarithmic time.
 * 
 * @tparam _Key     Key type of object
 * @tparam _Tp      Type of mapped object
 * @tparam _Cmp     Comparison function (default : std::less)
 * @tparam _Alloc   Allocator type (default : std::allocator)
 * 
 * Map supports bidirectional iteraots and the tree object is a RBT
 */
template <typename _Key, typename _Tp, typename _Cmp = std::less<_Key>, typename _Alloc = std::allocator<ft::pair<const _Key, _Tp> > >
class map
{
    // standard typedefs
    public:
        typedef _Key                                            key_type;
        typedef _Tp                                             mapped_type;
        typedef ft::pair<const key_type, mapped_type>           value_type;
        typedef _Cmp                                            key_compare;
        typedef _Alloc                                          allocator_type;

        typedef ptrdiff_t                                       difference_type;
        typedef size_t                                          size_type;
    
    // Helper class to handle Pair value type comparisons
    public:
        class value_compare : public std::binary_function<value_type, value_type, bool>
        {
            friend class map<_Key, _Tp, _Cmp, _Alloc>;
            protected:
                _Cmp    comp;
                value_compare(_Cmp val) : comp(val) {}
            public:
                bool operator()(const value_type &x, const value_type &y) const
                {
                    return comp(x.first, y.first);
                }
        };
    
    private:
        typedef typename _Alloc::value_type                         _alloc_value_type;
        typedef _rbtree<value_type, value_compare, allocator_type>  _tree_type;
        // PAIR RETURN TYPES
        typedef typename _tree_type::pair_type               pair_type;
        typedef typename _tree_type::pair_range              pair_range;
        typedef typename _tree_type::const_pair_range        const_pair_range;

        key_compare _key_cmp;
        _tree_type  tree;

    public:
        // TYPES
        typedef typename _Alloc::pointer                    pointer;
        typedef typename _Alloc::const_pointer              const_pointer;
        typedef typename _Alloc::reference                  reference;
        typedef typename _Alloc::const_reference            const_reference;
        // ITERATORS - bidirectional RBT iterator
        typedef typename _tree_type::iterator               iterator;
        typedef typename _tree_type::const_iterator         const_iterator;
        typedef typename _tree_type::reverse_iterator       reverse_iterator;
        typedef typename _tree_type::const_reverse_iterator const_reverse_iterator;

        /**
         * CONSTRUCTORS 
         */
        explicit map (const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) : tree(comp, alloc) {}
        template <typename InputIterator>
        map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type());
        map(const map &copy);

        /**
         *  OPERATORS
         */
        map & operator=(const map &val);
        mapped_type & operator[](const key_type &key);

        /**
		 *	CAPACITY
		 */
        bool        empty() const {return (size() ? false : true) ;}
        size_type   size() const { return tree._get_size(); }
        size_type   max_size() const { return tree._get_max_size();}
        
		/**
		 *	ITERATORS - bidirectional
		 */

        // forward
        iterator begin() { return tree._begin(); }
        const_iterator begin() const { return tree._begin(); }
        iterator end() { return tree._end(); }
        const_iterator end() const { return tree._end(); }
		// reverse
        reverse_iterator rbegin() { return tree._rbegin(); }
        reverse_iterator rend() { return tree._rend(); }
        const_reverse_iterator rbegin() const { return tree._rbegin(); }
        const_reverse_iterator rend() const { return tree._rend(); }

		/**
		 *	MODIFIERS
		 */

        // insert
        ft::pair<iterator, bool>    insert(const value_type &value);
        iterator                    insert(iterator position, const value_type &value);
        template <class InputIterator>
        void    insert(InputIterator first, InputIterator last);
		// erase
		void		erase(iterator position);
		size_type	erase(const key_type &k);
		void		erase(iterator first, iterator last);
		// swap
		void		swap(map &val) { tree._swap(val.tree); };
		// clear
		void		clear();
    
		/**
		 *	OBSERVERS
		 */
        // key
		key_compare		key_comp() const { return _key_cmp ; }
		// compare
        value_compare	value_comp() const { return value_compare(tree._get_key_compare()); }
		/**
		 *	OPERATIONS
		 */
        
		// find
		iterator		find(const key_type &key);
		const_iterator	find(const key_type &key) const;
		// cound
		size_type		count(const key_type &key) const;
		// lower_bound
		iterator		lower_bound(const key_type &key);
		const_iterator	lower_bound(const key_type &key) const;
		// upper bound
		iterator		upper_bound(const key_type &key);
		const_iterator	upper_bound(const key_type &key) const;
		// equal range
		pair_range          equal_range(const key_type &key);
		const_pair_range    equal_range(const key_type &key) const;
		// allocator
		allocator_type	get_allocator() const { return tree._get_data_allocator(); }
};

}   //  END NAMESPACE FT

#include "map/bits/_map_basic.hpp"
#include "map/bits/_map_modifier.hpp"
#include "map/bits/_map_bounds.hpp"
#include "map/bits/_map_logical_op.hpp"

#endif  //  _MAP_HPP