/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satchmin <satchmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:02:15 by sshakya           #+#    #+#             */
/*   Updated: 2022/02/19 17:47:07 by satchmin         ###   ########.fr       */
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

        explicit map (const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) : tree(comp, alloc) {}
        template <typename InputIterator>
        map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type());
        map(const map &copy);

        size_type   size() const { return tree._get_size(); }
        size_type   max_size() const { return tree._get_max_size();}

        iterator begin() { return tree._begin(); }
        const_iterator begin() const { return tree._begin(); }
        iterator end() { return tree._end(); }
        const_iterator end() const { return tree._end(); }
    
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


}   // END NAMESPACE FT