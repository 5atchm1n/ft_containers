/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:03:45 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/10 18:20:36 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
#define SET_HPP

#include <functional>
#include <memory>
#include "map/rbtree/_red_black_tree.hpp"

namespace ft
{

template < typename _Key, typename _Cmp = std::less<_Key>, typename _Alloc = std::allocator<_Key> >
class set 
{
    public:
        typedef _Key    key_type;
        typedef _Key    value_type;
        typedef _Cmp    key_compare;
        typedef _Cmp    value_compare;
        typedef _Alloc  allocator_type;
        typedef size_t      size_type;
        typedef ptrdiff_t   difference_type;
        
    private:
        typedef typename _Alloc::template rebind<_Key>::other  _key_alloc_type;
        typedef _rbtree<key_type, key_compare, allocator_type> _tree_type;
        
        _tree_type  _tree;
        key_compare _cmp;

    public:
        typedef typename allocator_type::pointer            pointer;
        typedef typename allocator_type::reference          reference;
        typedef typename allocator_type::const_pointer      const_pointer;
        typedef typename allocator_type::const_reference    const_reference;

        typedef typename _tree_type::const_iterator             iterator;
        typedef typename _tree_type::const_iterator             const_iterator;
        typedef typename _tree_type::const_reverse_iterator     reverse_iterator;
        typedef typename _tree_type::const_reverse_iterator     const_reverse_iterator;

        typedef typename _tree_type::pair_type               pair_type;
        typedef typename _tree_type::pair_range              pair_range;
        typedef typename _tree_type::const_pair_range        const_pair_range;

        explicit set(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) : _tree(comp, alloc) {}
        template <typename InputIterator>
            set(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type());
        set(const set &other);

        set& operator=(const set &);

        // Iterators
        iterator    begin() { return _tree._begin(); }
        const_iterator begin() const { return _tree._begin(); }
        iterator    end() { return _tree._end(); }
        const_iterator    end() const { return _tree._end(); }
        // Reverse Iterators
        reverse_iterator rbegin() { return _tree._rbegin(); }
        reverse_iterator rend() { return _tree._rend(); }
        const_reverse_iterator rbegin() const { return _tree._rbegin(); }
        const_reverse_iterator rend() const { return _tree._rend(); }

        // Capacity
        bool        empty() const { return size() ? false : true; }
        size_type   size() const { return _tree._get_size(); }
        size_type   max_size() const { return _tree._get_max_size(); }

        // Modifiers
        pair_type   insert(const value_type &value);
        iterator    insert(iterator position, const value_type &val);
        template <class InputIterator>
            void    insert(InputIterator first, InputIterator last);
        
        void        erase(iterator position);
        size_type   erase(const value_type &val);
        void        erase(iterator first, iterator last);
        
		void		swap(set &val) { _tree._swap(val._tree); };
        void        clear();

        // Observers
        key_compare     key_comp() const { return _tree._get_key_compare(); }
        value_compare   value_comp() const { return _tree._get_key_compare(); }
        allocator_type  get_allocator() const { return _tree._get_data_allocator(); }

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
        
};

}   // END NAMESPACE FT

#include "set/bits/_set_basic.hpp"
#include "set/bits/_set_bounds.hpp"
#include "set/bits/_set_logical_op.hpp"
#include "set/bits/_set_modifier.hpp"

#endif  // SET_HPP