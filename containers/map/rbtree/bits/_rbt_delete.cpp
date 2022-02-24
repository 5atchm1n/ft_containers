/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _rbt_delete.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:32:29 by sshakya           #+#    #+#             */
/*   Updated: 2022/02/24 02:39:27 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_red_black_tree.hpp"

namespace ft
{

template<typename _Tp, typename _Cmp, typename _Alloc>
void
_rbtree<_Tp, _Cmp, _Alloc>::_clean_node(node_pointer node)
{
    _data_alloc.destroy(node->data);
    _data_alloc.deallocate(node->data, SINGLE_NODE);    
    _node_alloc.deallocate(node, SINGLE_NODE);
}

template <typename _Tp, typename _Cmp, typename _Alloc>
void
_rbtree<_Tp, _Cmp, _Alloc>::_rbtree_transplant(node_pointer node_a, node_pointer node_b)
{
    if (node_a->parent == _nil)
        _root = node_b;
    else if (node_a == node_a->parent->left)
        node_a->parent->left = node_b;
    else
        node_a->parent->right = node_b;
    node_b->parent = node_a->parent;
}

template <typename _Tp, typename _Cmp, typename _Alloc>
void
_rbtree<_Tp, _Cmp, _Alloc>::_delete_node(node_pointer node)
{
    node_pointer tmp_x;
    node_pointer tmp_y;
    tmp_y = node;
    bool node_isred = tmp_y->isred;
    if (node->left == _nil)
    {
        tmp_x = node->right;
        _rbtree_transplant(node, node->right);
    }
    else if (node->right == _nil)
    {
        tmp_x = node->left;
        _rbtree_transplant(node, node->left);
    }
    else
    {
        tmp_y = _rbtree_minimum(node->right);
        node_isred = tmp_y->isred;
        tmp_x = tmp_y->right;
        if (tmp_y== node)
            tmp_x->parent = tmp_y;
        else
        {
            _rbtree_transplant(tmp_y, tmp_y->right);
            tmp_y->right = node->right;
            tmp_y->right->parent = tmp_y;
        }
        _rbtree_transplant(node, tmp_y);
        tmp_y->left = node->left;
        tmp_y->left->parent = tmp_y;
        tmp_y->isred = node->isred;
    }
    if (node_isred == false)
        _delete_node_fix(tmp_x);
    _clean_node(node);
    _size--;
}

template <typename _Tp, typename _Cmp, typename _Alloc>
void
_rbtree<_Tp, _Cmp, _Alloc>::_delete_node_fix(node_pointer node)
{
    while (node != _root && node->isred == false)
    {
        if (node == node->parent->left)
        {
            node_pointer tmp_w = node->parent->right;
            if (tmp_w->isred == true)
            {
                tmp_w->isred = false;
                node->parent->isred = true;
                _rbtree_rotate_left(node->parent);
                tmp_w = node->parent->right;
            }
            if (tmp_w->left->isred == false && tmp_w->right->isred == false)
            {
                tmp_w->isred = true;
                node = node->parent;
            }
            else
            {   if (tmp_w->right->isred == false)
                {
                    tmp_w->left->isred = false;
                    tmp_w->isred = true;
                    _rbtree_rotate_right(tmp_w);
                    tmp_w = node->parent->right;
                }
                tmp_w->isred = node->parent->isred;
                node->parent->isred = false;
                tmp_w->right->isred = false;
                _rbtree_rotate_left(node->parent);
                node = _root;
            }
        }
        else
        {
            node_pointer tmp_w = node->parent->left;
            if (tmp_w->isred == true)
            {
                tmp_w->isred = false;
                node->parent->isred = true;
                _rbtree_rotate_right(node->parent);
                tmp_w = node->parent->left;
            }
            if (tmp_w->right->isred == false && tmp_w->left->isred == false)
            {
                tmp_w->isred = true;
                node = node->parent;
            }
            else
            {
                
                if (tmp_w->left->isred == false)
                {
                    tmp_w->right->isred = false;
                    tmp_w->isred = true;
                    _rbtree_rotate_left(tmp_w);
                    tmp_w = node->parent->left;
                }
                tmp_w->isred = node->parent->isred;
                node->parent->isred = false;
                tmp_w->right->isred = false;
                _rbtree_rotate_right(node->parent);
                node = _root;
            }
        }
    }
    node->isred = false;
}

}   // END NAMESPACE FT