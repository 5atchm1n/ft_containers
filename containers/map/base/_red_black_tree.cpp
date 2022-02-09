/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _red_black_tree.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satchmin <satchmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:15:26 by sshakya           #+#    #+#             */
/*   Updated: 2022/02/09 02:04:55by satchmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <_red_black_tree.hpp>

namespace ft {

template <typename _Tp, typename _Alloc>
_rbtree<_Tp, _Alloc>::_rbtree()
{
    _root = _node_alloc.allocate(SINGLE_TREE);
    _nil = _node_alloc.allocate(SINGLE_TREE);
    _root->_init_node(_nil);
    _root->data = _data_alloc.allocate(SINGLE_TREE);
}

template <typename _Tp, typename _Alloc>
_rbtree<_Tp, _Alloc>::_rbtree(const _Tp &value)
{
    _root = _node_alloc.allocate(SINGLE_TREE);
    _nil = _node_alloc.allocate(SINGLE_TREE);
    _root->_init_node(_nil);
    _root->data = _data_alloc.allocate(SINGLE_TREE);
    _data_alloc.construct(_root->data, value);
}

template <typename _Tp, typename _Alloc>
_rbtree<_Tp, _Alloc>::~_rbtree()
{
    _data_alloc.deallocate(_root->data, SINGLE_TREE);
    _node_alloc.deallocate(_root, SINGLE_TREE);
    _node_alloc.deallocate(_nil, SINGLE_TREE);
}

template <typename _Tp, typename _Alloc>
void
_rbtree<_Tp, _Alloc>::_rbtree_rotate_left(const node_type *current)
{
    node_type   *tmp = current->right;
    
    current->right = tmp->left;
    if (tmp->left != NULL)
        tmp->left->parent = current;
    tmp->parent = current->parent;
    if (current == _root)
        _root = tmp;
    else if (current == current->parent->left)
        current->parent->left = tmp;
    else
        current->parent->right = tmp;
    tmp->left = current;
    current->parent = tmp;
}

template <typename _Tp, typename _Alloc>
void
_rbtree<_Tp, _Alloc>::_rbtree_rotate_right(const node_type *current)
{
    node_type   *tmp= current->left;
    current->left = tmp->right;
    if (tmp->right != NULL)
        tmp->right->parent = current;
    tmp->parent = current->parent;
    if (current == _root)
        _root = tmp;
    else if (current == current->parent->right)
        current->parent->right = tmp;
    else
        current->parent->left = tmp;
    tmp->right = current;
    current->parent = tmp;
}

template <typename _Tp, typename _Alloc>
std::ostream& operator<<(std::ostream& stream, const _rbtree<_Tp, _Alloc> &val)
{
    stream << val._root << "\n";
    stream << val._nil << "\n";
    stream << *val._root;
    return stream;
}

}   // END NAMESPACE FT