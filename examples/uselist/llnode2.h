// llnode2.h
// Glenn G. Chappell
// 2021-10-22
//
// For CS 311 Fall 2021
// Header for struct LLNode2
// Singly Linked List node using smart pointers
//  + associated functionality
// Based on llnode.h
// There is no associated source file.

#ifndef FILE_LLNODE2_H_INCLUDED
#define FILE_LLNODE2_H_INCLUDED

#include <cstddef>
// For std::size_t
#include <memory>
// For std::unique_ptr, std::make_unique
#include <utility>
// For std::move


// *********************************************************************
// struct LLNode2 - Struct definition
// *********************************************************************


// struct LLNode2
// Singly Linked List node, with client-specified value type
// Invariants:
//     Either _next is nullptr, or _next points to an LLNode2, allocated
//      with new, owned by *this.
// Requirements on Types:
//     ValType must have a copy ctor and a (non-throwing) dctor.
template <typename ValType>
struct LLNode2 {
    ValType    _data;  // Data for this node
    std::unique_ptr<LLNode2> _next;  // Ptr to next node, or nullptr if none

    // The following simplify creation & destruction

    // 1- & 2-param ctor
    // _data is set to data (given). _next is set to next, if given, or
    // nullptr if not.
    // Pre:
    //     theNext, if passed, is either nullptr, or else it points to
    //      an LLNode2 allocated with new, with ownership transferred to
    //      *this.
    explicit LLNode2(const ValType & data,
                     std::unique_ptr<LLNode2> & next = nullptr)
            :_data(data),
             _next(std::move(next))
    {}

    // dctor
    // Does delete on _next.
    ~LLNode2()
    {
        while(_next)
            pop_front(_next);
    }

    // No default ctor, no copy/move operations.
    LLNode2() = delete;
    LLNode2(const LLNode2 & other) = delete;
    LLNode2 & operator=(const LLNode2 & other) = delete;
    LLNode2(LLNode2 && other) = delete;
    LLNode2 & operator=(LLNode2 && other) = delete;

};  // End struct LLNode2


// *********************************************************************
// struct LLNode2 - Associated global functions
// *********************************************************************


// size
// Given ptr to Linked List, return its size (number of nodes).
// Pre:
//     head is ptr to nullptr-terminated Linked List, or nullptr for
//      empty Linked List.
// Requirements on Types:
//     ValType must have a copy ctor and a (non-throwing) dctor.
// NOTE: The above are the requirements for LLNode<ValType>; no member
// functions of ValType are actually used here.
template <typename ValType>
std::size_t size(const std::unique_ptr<LLNode2<ValType>> & head)
{
    auto p = head.get();            // Iterates through list
    std::size_t counter = 0;  // Number of nodes so far
    while (p != nullptr)
    {
        p = p->_next.get();
        ++counter;
    }
    return counter;
}


// push_front
template <typename ValType>
void push_front(std::unique_ptr<LLNode2<ValType>> & head,
                const ValType & item)
{
    head = std::make_unique<LLNode2<ValType>>(item, head);
}


// pop_front
// Given unique_ptr to Linked List, removes first item from list, if
// list is nonempty. If list is empty, does nothing.
// Requirements on Types:
//     ValType must have a copy ctor and a (non-throwing) dctor.
// NOTE: The above are the requirements for LLNode2<ValType>; no member
// functions of ValType are actually used here.
// No-Throw Guarantee
template <typename ValType>
void pop_front(std::unique_ptr<LLNode2<ValType>> & head) noexcept
{
    if (head)
    {
        auto tmp = std::move(head->_next);
        head = std::move(tmp);
    }
}



#endif  //#ifndef FILE_LLNODE2_H_INCLUDED

