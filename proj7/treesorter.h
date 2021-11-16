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

    // Pointer to Left & Right Nodes (nullptr -> empty case)
    std::unique_ptr<BSTreeNode> _left = nullptr;
    std::unique_ptr<BSTreeNode> _right = nullptr;

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
    // TODO
    while (head) // while head is not null compare item against root value
    {
    // check root against item
    // root > item; go left
    // (recurse)
    // root < item; go right 
    // (recurse)
    // Set dummyptr = left node or right node based on results
    // then recures based on the ptr to the next node
    }
    if (!head) {
        //create node

    }
}

// tree_traversal (inorder traversal)
// Pre:
//     ???
// Requirements on Types:
//     ???
// Exception safety guarantee:
//     ???
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

