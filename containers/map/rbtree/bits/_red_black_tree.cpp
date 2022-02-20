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

#include "../_red_black_tree.hpp"

namespace ft
{

/**
template <typename _Tp, typename _Cmp, typename _Alloc>
_rbtree<_Tp, _Cmp, _Alloc>::_rbtree() : _key_compare()
{
    _size = 0;
    _nil = _node_alloc.allocate(SINGLE_NODE);
    _nil->isred = false;
    _nil->isnull = true;
    _nil->data = NULL;
    _root = _nil;

}
*/
/**
 * @brief contructor with default
 */
template <typename _Tp, typename _Cmp, typename _Alloc>
_rbtree<_Tp, _Cmp, _Alloc>::_rbtree(const _Cmp compare, const _Alloc allocator)
: _data_alloc(allocator), _key_compare(compare)
{
    _size = 0;
    _nil = _node_alloc.allocate(SINGLE_NODE);
    _nil->isred = false;
    _nil->isnull = true;
    _nil->data = NULL;
    _root = _nil;
}

/**
 * @brief destructor
 */
template <typename _Tp, typename _Cmp, typename _Alloc>
_rbtree<_Tp, _Cmp, _Alloc>::~_rbtree()
{
    if (_root != _nil)
        _clean_tree(_root);
    _node_alloc.deallocate(_nil, SINGLE_NODE);
}

template <typename _Tp, typename _Cmp, typename _Alloc>
bool
_rbtree<_Tp, _Cmp, _Alloc>::_is_duplicate(const value_type &val) const
{
    node_pointer check = _search_tree(val);
    if (check == _nil)
        return false;
    return true;
}

/**
 * @brief iterative search
 * 
 * @param val value to find
 * @return pointer to node
 */
template <typename _Tp, typename _Cmp, typename _Alloc>
typename _rbtree<_Tp, _Cmp, _Alloc>::node_pointer
_rbtree<_Tp, _Cmp, _Alloc>::_search_tree(const value_type &val) const
{
    node_pointer tmp = _root;
    while (tmp != _nil && !(!_key_compare(val, *tmp->data) && !_key_compare(*tmp->data, val)))
    {
        if (_key_compare(val, *tmp->data))
            tmp = tmp->left;
        else
            tmp = tmp->right;
    }
    return (tmp);
}

/**
 * @brief find smallest value in tree
 * 
 * @return poitner to node containing smallest value 
 */
template <typename _Tp, typename _Cmp, typename _Alloc>
typename _rbtree<_Tp, _Cmp, _Alloc>::node_pointer
_rbtree<_Tp, _Cmp, _Alloc>::_rbtree_minimum(node_pointer node) const
{
    if (node == _nil)
        return node;
    node_pointer tmp = node;
    while (tmp->left != _nil)
        tmp = tmp->left;
    return tmp;
}
/**
 * @brief find largest value in tree 
 * 
 * @return poitner to node containing largest value
 */
template <typename _Tp, typename _Cmp, typename _Alloc>
typename _rbtree<_Tp, _Cmp, _Alloc>::node_pointer
_rbtree<_Tp, _Cmp, _Alloc>::_rbtree_maximum(node_pointer node) const
{
    if (node == _nil)
        return node;
    node_pointer tmp = node;
    while (tmp->right != _nil)
        tmp = tmp->right;
    return tmp;
}

template <typename _Tp, typename _Cmp, typename _Alloc>
typename _rbtree<_Tp, _Cmp, _Alloc>::node_pointer
_rbtree<_Tp, _Cmp, _Alloc>::_rbtree_end(node_pointer node) const
{
    node_pointer tmp = node;
    while (tmp->right != _nil)
        tmp = tmp->right;
    return tmp->right;
}
/**
 * @brief find the in order successor
 * @return pointer to in order successor 
 */
template <typename _Tp, typename _Cmp, typename _Alloc>
typename _rbtree<_Tp, _Cmp, _Alloc>::node_pointer
_rbtree<_Tp, _Cmp, _Alloc>::_rbtree_successor(node_pointer node) const
{
    if (node->right != _nil)
        return _rbtree_minimum(node->right);
    node_pointer tmp = node->parent;
    while (tmp != _nil && node == tmp->right)
    {
        node = tmp;
        tmp = tmp->parent;
    }
    return tmp;
}

template <typename _Tp, typename _Cmp, typename _Alloc>
typename _rbtree<_Tp, _Cmp, _Alloc>::size_type
_rbtree<_Tp, _Cmp, _Alloc>::_get_size() const
{
    return _size;
}

template <typename _Tp, typename _Cmp, typename _Alloc>
typename _rbtree<_Tp, _Cmp, _Alloc>::size_type
_rbtree<_Tp, _Cmp, _Alloc>::_get_max_size() const
{
    return _node_alloc.max_size();
}

/**
 * @brief helper function to clean tree - recursive
 */ 
template <typename _Tp, typename _Cmp, typename _Alloc>
void
_rbtree<_Tp, _Cmp, _Alloc>::_clean_tree(node_pointer node)
{
    if (node != _nil)
    {
        _clean_tree(node->left);
        _clean_tree(node->right);
        _data_alloc.deallocate(node->data, SINGLE_NODE);
        _node_alloc.deallocate(node, SINGLE_NODE);
    }
}
/**
 * @brief print tree helper
 * @return std::ostream& 
 */

template <typename _Tp, typename _Cmp, typename _Alloc>
std::ostream &operator<<(std::ostream &stream, const _rbtree<_Tp, _Cmp, _Alloc> &val)
{
    stream << "root = " << val._root << "\n";
    stream << "nil = " << val._nil << "\n";
    stream << "node : " << *val._root << "\n";
    return stream;
}
}   // END NAMESPACE FT