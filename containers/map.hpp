/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:02:15 by sshakya           #+#    #+#             */
/*   Updated: 2022/02/21 00:27:24 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/rbtree/_red_black_tree.hpp"
#include <functional>
#include "pair.hpp"

namespace ft
{

template <typename _Key, typename _Tp, typename _Cmp = std::less<_Key>, typename _Alloc = std::allocator<ft::pair<const _Key, _Tp> > >
class map
{
    public:
        typedef _Key                                            key_type;
        typedef _Tp                                             mapped_type;
        typedef ft::pair<const key_type, mapped_type>           value_type;
        typedef _Cmp                                            key_compare;
        typedef _Alloc                                          allocator_type;

        typedef ptrdiff_t                                       difference_type;
        typedef size_t                                          size_type;
    
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

        key_compare _key_cmp;
        _tree_type  tree;

    public:
        typedef typename _Alloc::pointer                    pointer;
        typedef typename _Alloc::const_pointer              const_pointer;
        typedef typename _Alloc::reference                  reference;
        typedef typename _Alloc::const_reference            const_reference;
        typedef typename _tree_type::iterator               iterator;
        typedef typename _tree_type::const_iterator         const_iterator;
        typedef typename _tree_type::reverse_iterator       reverse_iterator;
        typedef typename _tree_type::const_reverse_iterator const_reverse_iterator;

        // CONSTRUCTORS
        //explicit map() : tree() {}
        explicit map (const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) : tree(comp, alloc) {}
        template <typename InputIterator>
        map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type());
        map(const map &copy) : tree(copy.key_comp(), copy.get_allocator())
        {
            insert(copy.begin(), copy.end());
        }

        /**
         * @brief 
         * 
         */
        map &operator=(const map &val)
        {
            if (this != &val)
                *this = val;
            return *this;
        }
		/**
		 *	ELEMENT ACCESS
		 */
		mapped_type			&operator[](const key_type &key)
		{
            value_type val = ft::make_pair(key, mapped_type());
            if (!tree._is_duplicate(val))
                tree._insert_node(val);
            return (tree._search_tree(val)->_get_data())->second;
		}

		mapped_type			&at(const key_type &key);
		const mapped_type	&at(const key_type &key) const;

        /**
		 *	CAPACITY
		 */
        bool        empty() const {return (size() ? false : true) ;}
        size_type   size() const { return tree._get_size(); }
        size_type   max_size() const { return tree._get_max_size();}
        
		/**
		 *	ITERATORS
		 */
        iterator begin() { return tree._begin(); }
        const_iterator begin() const { return tree._begin(); }
        iterator end() { return tree._end(); }
        const_iterator end() const { return tree._end(); }
		//reverse
        reverse_iterator rbegin() { return tree._rbegin(); }
        reverse_iterator rend() { return tree.rend(); }
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
		void		swap(map &val);
		// clear
		void		clear();
		/**
		 *	OBSERVERS
		 */
		key_compare		key_comp() const { return _key_cmp ; }
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
		pair<const_iterator, const_iterator>	equal_range(const key_type &key) const;
		pair<iterator, iterator>				equal_range(const key_type &key);
		/**
		 *	ALLOCATOR
		 */
		allocator_type	get_allocator() const { return tree._get_data_allocator(); }
};

template <typename _Key, typename _Tp, typename _Cmp, typename _Alloc>
template <typename InputIterator>
map<_Key, _Tp, _Cmp, _Alloc>::map(InputIterator first, InputIterator last, const key_compare &comp, const allocator_type &alloc) : tree(comp, alloc)
{
    for (InputIterator tmp = first; tmp != last; tmp++)
    {
        if (!tree._is_duplicate(*tmp))
            tree._insert_node(*tmp);
    }
}

template <typename _Key, typename _Tp, typename _Cmp, typename _Alloc>
template <typename InputIterator>
void
map<_Key, _Tp, _Cmp, _Alloc>::insert(InputIterator first, InputIterator last)
{
    for (InputIterator tmp = first; tmp != last; tmp++)
    {
        tree._insert_node(*tmp);
    }
}

template <typename _Key, typename _Tp, typename _Cmp, typename _Alloc>
ft::pair<typename ft::map<_Key, _Tp, _Cmp, _Alloc>::iterator, bool>
map<_Key, _Tp, _Cmp, _Alloc>::insert(const value_type &value)
{
    bool    is_in = !tree._is_duplicate(value);
    iterator position = (tree._insert_search(value));
    ft::pair<iterator, bool> _value = ft::make_pair(position, is_in);
    return _value;
}

template <typename _Key, typename _Tp, typename _Cmp, typename _Alloc>
typename map<_Key, _Tp, _Cmp, _Alloc>::iterator
map<_Key, _Tp, _Cmp, _Alloc>::insert(iterator position, const value_type &value)
{
    (void)position;
    return iterator (tree._insert_search(value));
}

template <typename _Key, typename _Tp, typename _Cmp, typename _Alloc>
typename map<_Key, _Tp, _Cmp, _Alloc>::iterator
map<_Key, _Tp, _Cmp, _Alloc>::find(const key_type &key)
{
    value_type val = ft::make_pair(key, mapped_type());
    iterator pos(tree._search_tree(val));
    return pos == end() ? end() : pos;
}

template <typename _Key, typename _Tp, typename _Cmp, typename _Alloc>
typename map<_Key, _Tp, _Cmp, _Alloc>::const_iterator
map<_Key, _Tp, _Cmp, _Alloc>::find(const key_type &key) const
{
    value_type val = ft::make_pair(key, mapped_type());
    const_iterator pos(tree._search_tree(val));
    return pos == end() ? end() : pos;
}

}   // END NAMESPACE FT