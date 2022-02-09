/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _red_black_tree.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satchmin <satchmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:25:49 by satchmin          #+#    #+#             */
/*   Updated: 2022/02/09 02:25:16 by satchmin         ###   ########.fr       */
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
        typedef typename _Alloc::template rebind<_rb_node<_Tp> >::other  node_allocator;
        typedef size_t                          size_type;
        typedef _Tp                             value_type;
        typedef _Alloc                          data_allocator;
        typedef _rb_node<_Tp>           node_type;
    
        node_allocator          _node_alloc;
        data_allocator          _data_alloc;
    public:
        node_type               *_root;
        node_type               *_nil;

        void _rbtree_rotate_left(const node_type *current_node);
        void _rbtree_rotate_right(const node_type *current_node);


    public: 
        _rbtree();
        _rbtree(const _Tp &value);
        ~_rbtree();
};

}   // END NAMESPACE FT

#include <_red_black_tree.cpp>

#endif // END _RED_BLACK_TREE_H