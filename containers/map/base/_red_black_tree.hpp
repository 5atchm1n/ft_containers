/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _red_black_tree.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:25:49 by satchmin          #+#    #+#             */
/*   Updated: 2022/02/15 01:53:56 by sshakya          ###   ########.fr       */
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
        typedef _rb_node<_Tp>                   node_type;
        typedef _rb_node<_Tp>*                  node_pointer;
    
        node_allocator          _node_alloc;
        data_allocator          _data_alloc;

        node_pointer    _create_node(const value_type &val);
    
    public:
        node_type               *_root;
        node_type               *_nil;
        size_type               _size;
    private:
        // Helper Functions
        void            _rbtree_rotate_left(node_type *current_node);
        void            _rbtree_rotate_right(node_type *current_node);
        void            _insert_node_fix(node_pointer node);
        void            _rbtree_transplant(node_pointer node_a, node_pointer node_b);
        void            _delete_node_fix(node_pointer node);
        void            _clean_tree(node_pointer node);
        node_pointer    _increment(node_pointer node);
        node_pointer    _decrement(node_pointer node);

    public: 
        // Constructors
        _rbtree();
        _rbtree(const _Tp &value);
        // Member Functions
        void _insert_node(const value_type &val);
        void _delete_node(node_pointer node);
        node_pointer    _rbtree_successor(node_pointer node) const;
        node_pointer    _rbtree_minimum(node_pointer node) const;
        node_pointer    _rbtree_maximum(node_pointer node) const;
        node_pointer    _search_tree(const value_type &val) const;
        // Destructor
        ~_rbtree();
};

}   // END NAMESPACE FT

#include <_red_black_tree.cpp>
#include <_rbt_rotations.cpp>
#include <_rbt_insert.cpp>
#include <_rbt_delete.cpp>
#include <_rbt_traversal.cpp>

#endif // END _RED_BLACK_TREE_H