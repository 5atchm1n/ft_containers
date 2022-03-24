# FT_CONTAINERS

My implementation of the STL containers. This library contains the containers VECTOR, MAP, STACK and SET
implemented according the the CPP-98 standard.
### CONCEPTS

This project has the aim of making us understand the syntax to use for template programmings and force us to understand
how to use the STL containers properly. For my implementation i decided to use split the different method definitions into
multiple files to allow for smaller and more readable files. This changes the classical syntax and makes for a slightly
more compicated syntax when defining methods to a templated class.
#### FILE STRUCTURE

* [_rbtree](https://github.com/5atchm1n/ft_containers/tree/master/containers/_rbtree)
    * [bits](https://github.com/5atchm1n/ft_containers/tree/master/containers/_rbtree/bits)
    * [RBT_header](https://github.com/5atchm1n/ft_containers/blob/master/containers/_rbtree/_red_black_tree.hpp)
* [iterators](https://github.com/5atchm1n/ft_containers/tree/master/containers/iterators)
    * [reverse_iterator](https://github.com/5atchm1n/ft_containers/blob/master/containers/iterators/reverse_iterator.hpp)
* [map](https://github.com/5atchm1n/ft_containers/tree/master/containers/map)
    * [bits](https://github.com/5atchm1n/ft_containers/tree/master/containers/map/bits)
* [vector](https://github.com/5atchm1n/ft_containers/tree/master/containers/vector)
    * [bits](https://github.com/5atchm1n/ft_containers/tree/master/containers/vector/bits)
* [set](https://github.com/5atchm1n/ft_containers/tree/master/containers/set)
    * [bits](https://github.com/5atchm1n/ft_containers/tree/master/containers/set/bits)
* [ft_type_traits.hpp](https://github.com/5atchm1n/ft_containers/blob/master/containers/ft_type_traits.hpp)
* [iterator_traits.hpp](https://github.com/5atchm1n/ft_containers/blob/master/containers/iterator_traits.hpp)
* [map.hpp](https://github.com/5atchm1n/ft_containers/blob/master/containers/map.hpp)
* [pair.hpp](https://github.com/5atchm1n/ft_containers/blob/master/containers/pair.hpp)
* [set.hpp](https://github.com/5atchm1n/ft_containers/blob/master/containers/set.hpp)
* [stack.hpp](https://github.com/5atchm1n/ft_containers/blob/master/containers/stack.hpp)
* [vector.hpp](https://github.com/5atchm1n/ft_containers/blob/master/containers/vector.hpp)



#### NOTE

For those of you who are looking for inspiration - the project is missing a couple of mandatory things but works ;)