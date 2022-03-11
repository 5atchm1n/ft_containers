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

#include <sstream>
#include <cstddef>
#include <memory>
#include "pair.hpp"
#include "bits/_rbt_node.hpp"
#include "bits/_rbt_iterator.hpp"
#include "iterators/reverse_iterator.hpp"

#define SINGLE_TREE 1
#define SINGLE_NODE 1

namespace ft {

template <typename _Tp, typename _Cmp, typename _Alloc>
class _rbtree
{

    private:
        typedef typename _Alloc::template rebind<_rb_node<_Tp, _Alloc> >::other  node_allocator;
        typedef _rbtree<_Tp, _Cmp, _Alloc>  self;
        
        typedef size_t                      size_type;
        typedef ptrdiff_t                   difference_type;
        typedef _Tp                         value_type;
        typedef _Alloc                      data_allocator;
        typedef _rb_node<_Tp, _Alloc>       node_type;
        typedef _rb_node<_Tp, _Alloc>*      node_pointer;
    
    // Allocators 
        node_allocator  _node_alloc;
        data_allocator  _data_alloc;
    // Compare function
        _Cmp            _key_compare;
    // Helper functions
        bool            _is_equal(const value_type &val, const value_type &other) const;
        void            _rbtree_rotate_left(node_type *current_node);
        void            _rbtree_rotate_right(node_type *current_node);
        void            _insert_node_fix(node_pointer node);
        void            _rbtree_transplant(node_pointer node_a, node_pointer node_b);
        void            _delete_node_fix(node_pointer node);
        void            _clean_node(node_pointer node);
        node_pointer    _create_node(const value_type &val);
        void            _clean_tree(node_pointer node);
        int             _count_nodes(node_pointer node) const;
        void            _print(node_pointer node, std::stringstream &buffer, bool is_tail, std::string prefix);

    // Key nodes
        node_type       *_root;
        node_type       *_nil;
        size_type       _size;

    public:
    // Iterators
        typedef ft::_rbtree_iterator<value_type, node_type>                 iterator;
        typedef ft::_rbtree_iterator<value_type const, node_type const>     const_iterator;
        typedef ft::reverse_iterator<iterator>                              reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>                        const_reverse_iterator;

    // Pair return types
        typedef ft::pair<iterator, bool>                                pair_type;
        typedef ft::pair<iterator, iterator>                            pair_range; 
        typedef ft::pair<const_iterator, const_iterator>                const_pair_range; 
    //  Constructors    
        _rbtree();
        explicit _rbtree(const _Cmp compare,const _Alloc allocator);
        _rbtree(const _rbtree &copy);
        _rbtree & operator=(const _rbtree &copy);
        ~_rbtree();

    //  SWAP
        void            _swap(self &tree);
    //
        node_pointer    _rbtree_successor(node_pointer node) const;
        node_pointer    _rbtree_minimum(node_pointer node) const;
        node_pointer    _rbtree_maximum(node_pointer node) const;
    //  INSERT  
        pair_type       _insert(const value_type &val);
        iterator        _insert_pos(const_iterator start, const value_type &val);
        node_pointer    _search_tree(const value_type &val) const;
        pair_type       _insert_node(const value_type &val, node_pointer start_pos);
    //  DELETE
        void            _delete_node(node_pointer node);
        void            _clean();
    //  GETTERS
        size_type       _get_size() const;
        size_type       _get_max_size() const;
        _Cmp            _get_key_compare() const { return _key_compare ;}
        data_allocator  _get_data_allocator() const { return _data_alloc ;}
    //  ITERATORS
        iterator        _begin() { return iterator(_rbtree_minimum(_root)); };
        const_iterator  _begin() const { return const_iterator(_rbtree_minimum(_root)); };
        iterator        _end() { return iterator(_nil); };
        const_iterator  _end() const { return const_iterator(_nil); };

        reverse_iterator        _rbegin() { return reverse_iterator(_end()); };
        const_reverse_iterator  _rbegin() const { return const_reverse_iterator(_end()); };
        reverse_iterator        _rend() { return reverse_iterator(_begin()); };
        const_reverse_iterator  _rend() const { return const_reverse_iterator(_begin()); };
    // PRINT DEBUG    
        void            print(void);
    //
        iterator            _lower_bound(const value_type &val);
        const_iterator      _lower_bound(const value_type &val) const;
        iterator            _upper_bound(const value_type &val);
        const_iterator      _upper_bound(const value_type &val) const;
        pair_range          _equal_range(const value_type &val);
        const_pair_range    _equal_range(const value_type &val) const;
};

}   // END NAMESPACE FT

#include "bits/_rbt_basic.hpp"
#include "bits/_rbt_bounds.hpp"
#include "bits/_rbt_delete.hpp"
#include "bits/_rbt_helper.hpp"
#include "bits/_rbt_insert.hpp"
#include "bits/_rbt_rotations.hpp"

#endif // END _RED_BLACK_TREE_H