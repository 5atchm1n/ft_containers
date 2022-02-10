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
    _nil = _node_alloc.allocate(SINGLE_TREE);
    _nil->_init_node(_nil);
    _root = _nil;
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
    _node_alloc.deallocate(_nil, SINGLE_TREE);
    if (_root != _nil)
    {
        _data_alloc.deallocate(_root->data, SINGLE_TREE);
        _node_alloc.deallocate(_root, SINGLE_TREE);
    }
}

template <typename _Tp, typename _Alloc>
void
_rbtree<_Tp, _Alloc>::_rbtree_rotate_left(const node_type *current)
{
    node_type   *tmp = current->right;
    
    current->right = tmp->left;
    if (tmp->left != _nil)
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
    if (tmp->right != _nil)
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
typename _rbtree<_Tp, _Alloc>::node_pointer
_rbtree<_Tp, _Alloc>::_create_node(const value_type &val)
{
    node_pointer    new_node;
    new_node = _node_alloc.allocate(SINGLE_NODE);
    new_node->_init_node(_nil);
    new_node->data = _data_alloc.allocate(SINGLE_NODE);
    _data_alloc.construct(new_node->data, val);
    return new_node;
}

template <typename _Tp, typename _Alloc>
void
_rbtree<_Tp, _Alloc>::_insert_node(node_pointer parent, node_pointer new_node)
{
    if (*new_node->data > *parent->data)
    {
        if (parent->right == _nil)
        {
            parent->right = new_node;
            new_node->parent = parent;
        }
        return _insert_node(parent->right, new_node);
    }
    if (parent->left == _nil)
    {
        parent->left = new_node;
        new_node->parent = parent;
        return ;
    }
    return _insert_node(parent->left, new_node);
}

template <typename _Tp, typename _Alloc>
void
_rbtree<_Tp, _Alloc>::_check_color(node_pointer node)
{
    if (node == _root)
        return ;
    if (node->isred = true && node->parent->isred = true)
        _correct_tree(node);
    _check_color(node->parent);
}

template <typename _Tp, typename _Alloc>
void
_rbtree<_Tp, _Alloc>::_correct_tree(node_pointer node)
{
    if (node->parent->parent->left == node->parent)
    {
        if (node->parent->parent->right == _nil && node->parent->parent->right->isred = false)
            return _rotate(node);
        if (node->parent->parent->right != _nil)
            node->parent->parent->right->isred = false;
        node->parent->parent->isred = true;
        node->parent->isred = false;
    
    }
    if (node->parent->parent->right == node->parent)
    {
        if (node->parent->parent->left == _nil && node->parent->parent->left->isred = false)
            return _rotate(node);
        if (node->parent->parent->left != _nil)
            node->parent->parent->left->isred = false;
        node->parent->parent->isred = true;
        node->parent->isred = false; 
    }

}

template <typename _Tp, typename _Alloc>
void
_rbtree<_Tp, _Alloc>::_rotate(node_pointer node)
{
    if (node->parent->left = node)
    {
        if (node->parent->parent->left == node->parent)
        {
            _rbtree_rotate_right(node->parent->parent);
            node->isred = true;
            node->parent->isred = true;
            if (node->parent->right != _nil)
                node->parent->right->isred = true;
            return ;
        }
        _right_left_rotate(node->parent->parent);
        node->isred = false;
        node->right->isred = true;
        node->left->isred = true;
        return ;
    }
}

template <typename _Tp, typename _Alloc>
void
_rbtree<_Tp, _Alloc>::_insert_node(const value_type &val)
{
    node_pointer new_node = _create_node(val);
    if (_root == _nil)
    {
        _root = new_node;
        _root->isred = false;
        _size++;
        return ;
    }
    _insert_node(_root, new_node);
}

template <typename _Tp, typename _Alloc>
std::ostream& operator<<(std::ostream& stream, const _rbtree<_Tp, _Alloc> &val)
{
    stream << "root = " << val._root << "\n";
    stream << "nil = " << val._nil << "\n";
    stream << "node : " << *val._root;
    return stream;
}

}   // END NAMESPACE FT