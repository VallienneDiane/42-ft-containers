# Implement containers : vector, map and stack

<p align="center">
<img src="https://iq.opengenus.org/content/images/2019/05/c1.JPG" width="500">
</p>


## Vector

Vectors are sequence containers representing arrays that can change in size.

Just like arrays, vectors use contiguous storage locations for their elements, which means that their elements can also be accessed using offsets on regular pointers to its elements.
But unlike arrays, their size can change dynamically, with their storage being handled automatically by the container.

<p align="center">
<img src="https://www.mycplus.com/mycplus/wp-content/uploads/2018/03/vectors.jpg" width="500">
</p>


## General use cases for C++ containers

<p align="center">
<img src="https://i.stack.imgur.com/HNMy4.png" width="900">
</p>

## Iterators

An iterator is any object that, pointing to some element in a range of elements (such as an array or a container), has the ability to iterate through the elements of that range using a set of operators (such increment (++)).

### Iterator_traits
iterator_traits is a template class in the C++ Standard Library that provides a way to obtain information about the properties of an iterator type. It is defined in the <iterator> header.

The iterator_traits template has a single template parameter, which is the type of the iterator. It defines several member types and constants that provide information about the iterator type, such as its value_type, difference_type, reference, pointer, and iterator_category.

### Reverse iterator

Reverse_iterator is an iterator adaptor that reverses the direction of a given iterator.
It produces a new iterator that moves from the end to the beginning of the sequence defined by the underlying bidirectional iterator.

<p align="center">
<img src="https://i.stack.imgur.com/5p7DE.png" width="400">
</p>



## Sources

vector
https://cplusplus.com/reference/vector/vector/

iterators
https://www.youtube.com/watch?v=F9eDv-YIOQ0
https://cplusplus.com/reference/iterator/

allocator
https://cplusplus.com/reference/memory/allocator/
https://medium.com/@vgasparyan1995/what-is-an-allocator-c8df15a93ed

size & capacity & max_size
https://www.fluentcpp.com/2017/10/13/size-capacity-stl-containers/
https://en.cppreference.com/w/cpp/container/vector/max_size
