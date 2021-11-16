// treesorter.h
// Solomon Himelbloom
// Benjamin Stream
// 2021-11-08
//
// For CS 311 Fall 2021
// Header for function template treesort
// There is no associated source file.

#ifndef FILE_TREESORTER_H_INCLUDED
#define FILE_TREESORTER_H_INCLUDED

#include <iterator> // For std::iterator_traits
#include <memory> // For std::unique_ptr

// struct BSTreeNode
template <typename Value>
struct BSTreeNode {
    Value _data; // Data for this node

    // TODO: pointer left & right nodes

    // Ctor
    explicit BSTreeNode(const Value & data):_data(data) {}

    // Dctor
    ~BSTreeNode() = default;

    // No other Big Five functions (copy/move operations)
    BSTreeNode(const BSTreeNode & other) = delete;
    BSTreeNode & operator=(const BSTreeNode & other) = delete;
    BSTreeNode(BSTreeNode && other) = delete;
    BSTreeNode & operator=(BSTreeNode && other) = delete;
};

// insert
template<typename Value>
void insert(std::unique_ptr<BSTreeNode<Value>> & head, const Value & item) {
    // TODO
}

// tree_traversal (inorder traversal)
template<typename Value, typename FDIter>
void tree_traversal() {
    // TODO
}

// TODO: treesort
// Sort a given range using Treesort.
// Pre:
//     ???
// Requirements on Types:
//     ???
// Exception safety guarantee:
//     ???
template<typename FDIter>
void treesort(FDIter first, FDIter last)
{
    // Value is the type that FDIter points to
    using Value = typename std::iterator_traits<FDIter>::value_type;

    // Forward Iterator
    for (FDIter it = first; it != last; ++it) {
        // DUMMY
    }

    // Finding the Value Type
    // FIXME: auto p = std::make_unique<BSTreeNode<<Value>>(...)
}


#endif //#ifndef FILE_TREESORTER_H_INCLUDED

