/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _red_black_tree.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satchmin <satchmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:25:49 by satchmin          #+#    #+#             */
/*   Updated: 2022/02/08 03:07:25 by satchmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _RED_BLACK_TREE_H
#define _RED_BLACK_TREE_H

#include <cstddef>
#include <memory>
#include "_rbt_node.hpp"

#define SINGLE_TREE 1

namespace ft {

template <typename _Tp, typename _Alloc = std::allocator<_Tp> >
class _rbtree
{
    private:
        typedef typename _Alloc::template rebind<_rb_node<_Tp, _Alloc> >::other  node_allocator;
        typedef size_t  size_type;
        typedef _Tp     value_type;
        typedef _Alloc  data_allocator;
    
        node_allocator  _node_alloc;

    public:    
        _rb_node<_Tp, _Alloc>   *_root;
    
        _rbtree();
        ~_rbtree();
};

template <typename _Tp, typename _Alloc>
_rbtree<_Tp, _Alloc>::_rbtree()
{
    _root = _node_alloc.allocate(SINGLE_TREE);
}

template <typename _Tp, typename _Alloc>
_rbtree<_Tp, _Alloc>::~_rbtree()
{
    _node_alloc.deallocate(_root, SINGLE_TREE);
}

}   // END NAMESPACE FT

#endif // END _RED_BLACK_TREE_H