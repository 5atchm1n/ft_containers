/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _red_black_tree.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:25:49 by satchmin          #+#    #+#             */
/*   Updated: 2022/02/22 18:20:45by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _RED_BLACK_TREE_H
#define _RED_BLACK_TREE_H

#include <cstddef>
#include <memory>
#include "map/rbtree/bits/_rbt_node.hpp"
#include "bits/_rbt_iterator.hpp"
#include "vector.iterator.hpp"

#define SINGLE_TREE 1
#define SINGLE_NODE 1

namespace ft {

template <typename _Tp, typename _Cmp, typename _Alloc>
class _rbtree
{

    private:
        typedef typename _Alloc::template rebind<_rb_node<_Tp> >::other  node_allocator;
        
        typedef size_t              size_type;
        typedef _Tp                 value_type;
        typedef _Alloc              data_allocator;
        typedef _rb_node<_Tp>       node_type;
        typedef _rb_node<_Tp>*      node_pointer;
    
    // Allocators 
        node_allocator  _node_alloc;
        data_allocator  _data_alloc;
    // Compare function
        _Cmp            _key_compare;
    
    // Key nodes
        node_type       *_root;
        node_type       *_nil;
        size_type       _size;
    // Helper functions
        void            _rbtree_rotate_left(node_type *current_node);
        void            _rbtree_rotate_right(node_type *current_node);
        void            _insert_node_fix(node_pointer node);
        void            _rbtree_transplant(node_pointer node_a, node_pointer node_b);
        void            _delete_node_fix(node_pointer node);
        void            _clean_node(node_pointer node);
        void            _clean_tree(node_pointer node);
        node_pointer    _create_node(const value_type &val);
        node_pointer    _increment(node_pointer node);
        node_pointer    _decrement(node_pointer node);

    public:
    
    // Iterators
        typedef ft::_rbtree_iterator<value_type>            iterator;
        typedef ft::_rbtree_const_iterator<value_type>      const_iterator;

        typedef ft::reverse_iterator<iterator>              reverse_iterator;
        typedef const ft::reverse_iterator<iterator>        const_reverse_iterator;
    
    //  Constructors    
        _rbtree();
        explicit _rbtree(const _Cmp compare,const _Alloc allocator);
        _rbtree(const _rbtree &copy);
        ~_rbtree();

    //  Methods
        node_pointer    _rbtree_successor(node_pointer node) const;
    //      
        node_pointer    _rbtree_minimum(node_pointer node) const;
        node_pointer    _rbtree_maximum(node_pointer node) const;
        node_pointer    _rbtree_end(node_pointer node) const;
    //    
        node_pointer    _search_tree(const value_type &val) const;
        node_pointer    _insert_search(const value_type &val);
        node_pointer    _insert_node(const value_type &val);
        void            _delete_node(node_pointer node);
    
        bool            _is_duplicate(const value_type &val) const;
    //
        size_type       _get_size() const;
        size_type       _get_max_size() const;
        _Cmp            _get_key_compare() const { return _key_compare ;}
        data_allocator  _get_data_allocator() const { return _data_alloc ;}
    //
        iterator        _begin() { return iterator(_rbtree_minimum(_root)); };
        const_iterator  _begin() const { return const_iterator(_rbtree_minimum(_root)); };
        iterator        _end() { return iterator(_rbtree_end(_root)); };
        const_iterator  _end() const { return const_iterator(_rbtree_end(_root)); };

};

}   // END NAMESPACE FT

#include "bits/_red_black_tree.cpp"
#include "bits/_rbt_rotations.cpp"
#include "bits/_rbt_insert.cpp"
#include "bits/_rbt_delete.cpp"
#include "bits/_rbt_traversal.cpp"

#endif // END _RED_BLACK_TREE_H