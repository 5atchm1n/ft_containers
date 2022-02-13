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

namespace ft
{
/**
 * @brief default contructor
 */
template <typename _Tp, typename _Alloc>
_rbtree<_Tp, _Alloc>::_rbtree()
{
    _nil = _node_alloc.allocate(SINGLE_TREE);
    _nil->isred = false;
    _nil->left = _nil;
    _nil->right = _nil;
    _root = _nil;
}
/**
 * @brief contructor with default
 */
template <typename _Tp, typename _Alloc>
_rbtree<_Tp, _Alloc>::_rbtree(const _Tp &value)
{
    _root = _node_alloc.allocate(SINGLE_TREE);
    _nil = _node_alloc.allocate(SINGLE_TREE);
    _root->_init_node(_nil);
    _root->data = _data_alloc.allocate(SINGLE_TREE);
    _data_alloc.construct(_root->data, value);
}
/**
 * @brief destructor
 */
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
std::ostream &operator<<(std::ostream &stream, const _rbtree<_Tp, _Alloc> &val)
{
    stream << "root = " << val._root << "\n";
    stream << "nil = " << val._nil << "\n";
    stream << "node : " << *val._root << "\n";
    const _rb_node<_Tp> *tmp = val._root;
    const _rb_node<_Tp> *tmpR;
    const _rb_node<_Tp> *tmpL;
    tmpR = tmp->right;
    tmpL = tmp->left;
    if (tmpR != val._nil)
        stream << *tmpR << "\n";
    if (tmpL != val._nil)
        stream << *tmpL << "\n";
    tmpR = tmpR->right;
    tmp = tmpL;
    tmpL = tmpR->left;
    if (tmpR != val._nil)
        stream << *tmpR << "\n";
    if (tmpL != val._nil)
        stream << *tmpL << "\n";
    tmpL = tmp;
    tmpR = tmpL->right;
    tmpL = tmpL->left;
    if (tmpR != val._nil)
        stream << *tmpR << "\n";
    if (tmpL != val._nil)
        stream << *tmpL << "\n";
    return stream;
}
/ END NAMESPACE FT