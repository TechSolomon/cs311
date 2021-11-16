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

// *********************************************************************
// struct BSTreeNode - Struct definition
// *********************************************************************


// FIXME: BSTreeNode
// Invariants:
//     ???
// Requirements on Types:
//     ???
template <typename Value>
struct BSTreeNode {
    Value _data; // Data for this node.

    // Pointer to Left Node
    std::unique_ptr<BSTreeNode<Value>> _left = nullptr;

    // Pointer to Right Node
    std::unique_ptr<BSTreeNode<Value>> _right = nullptr;

    // Ctor
    explicit BSTreeNode(const Value & data) : _data(data) {}

    // Dctor
    ~BSTreeNode() = default;

    // No other Big Five functions (copy/move operations)
    BSTreeNode(const BSTreeNode & other) = delete;
    BSTreeNode & operator=(const BSTreeNode & other) = delete;
    BSTreeNode(BSTreeNode && other) = delete;
    BSTreeNode & operator=(BSTreeNode && other) = delete;
};

// FIXME: insert
// Pre:
//     ???
// Requirements on Types:
//     ???
// Exception safety guarantee:
//     ???
template<typename Value>
void insert(std::unique_ptr<BSTreeNode<Value>> & head, const Value & item) {
    if (head) {
        if (item < head->_data)
            insert(head->_left, item);
        else
            insert(head->_right, item);
    }
    else
        head = std::make_unique<BSTreeNode<Value>>(item);
}

// TODO: tree_traversal (inorder traversal)
// Pre:
//     ???
// Requirements on Types:
//     ???
// Exception safety guarantee:
//     ???
template<typename Value, typename FDIter>
void tree_traversal(std::unique_ptr<BSTreeNode<Value>> & head, FDIter & iter) {
    if (head) {
        tree_traversal(head->_left, iter);
        *iter++ = head->_data;
        tree_traversal(head->_right, iter);
    }
    else
        return;
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
void treesort(FDIter first, FDIter last) {
    // Value is the type that FDIter points to
    using Value = typename std::iterator_traits<FDIter>::value_type;

    // Declare Binary Search Tree (BST) with Value
    std::unique_ptr<BSTreeNode<Value>> ptrBST;

    // Forward Iterator
    for (FDIter it = first; it != last; ++it)
        insert(ptrBST, *it);

    tree_traversal(ptrBST, first);
}


#endif //#ifndef FILE_TREESORTER_H_INCLUDED

