// dp6.h
// Benjamin Stream
// Solomon Himelbloom
// 2021-10-29
// Class template for Project 6.

#ifndef PROJ6_DP6_H
#define PROJ6_DP6_H

#include "llnode2.h"

#include <memory> // For std::unique_ptr, std::swap
#include <utility> // For std::move, std::pair
#include <functional> // For std::function

// Exercise A — Reversing a Linked List (reverseList)
// - newHead will point to this new list, which holds nodes that have been reversed.
// - head points to the nodes that are not reversed yet.
// - To finish, set head = newHead.
// Requirements on Types:
// - None.
// No-Throw Guarantee
template<typename ValType>
void reverseList(std::unique_ptr<LLNode2<ValType>> &head) noexcept {
    std::unique_ptr<LLNode2<ValType>> newHead;
    while (head) {
        newHead.swap(head->_next);
        head.swap(newHead);
    }
    head = std::move(newHead);
}

// Exercise B — Associative Dataset Class Template (LLMap)
// Invariants:
// - Nodes must have unique keys.
// Requirements on Types:
// - key_type must have op==
template<typename Key, typename Val>
class LLMap {

    // key_type: type of key items
    using key_type = Key;

    // data_type: type of data items
    using data_type = Val;

    // pair_type: a pair of specified key_type & data_type items
    using pair_type = std::pair<key_type, data_type>;

// ***** LLMap: Data Member *****
private:

    std::unique_ptr<LLNode2<pair_type>> _ptrNode;

// ***** LLMap: ctors, dctors, ops *****
public:

    // Ctor
    LLMap() : _ptrNode(nullptr) {}

    // Dctor
    ~LLMap() = default;

    // No other Big Five functions (copy/move operations)
    LLMap(const LLMap& other) = delete;
    LLMap& operator=(const LLMap& other) = delete;
    LLMap(LLMap&& other) = delete;
    LLMap& operator=(LLMap&& other) = delete;

// ***** LLMap: Public Functions *****
public:

    // size
    // No-Throw Guarantee
    // - Returns size of Linked List node(s).
    [[nodiscard]] size_t size() const {
        return ::size(_ptrNode);
    }

    // empty
    // No-Throw Guarantee
    // - checks if _data (smart pointer) is null.
    [[nodiscard]] bool empty() const {
        if (_ptrNode) return false;
        else return true;
    }

    // Non-Const Find
    // No-Throw Guarantee
    // - Returns pointer to the pair.second;
    data_type* find(const key_type& key) {
        LLNode2<pair_type>* ptr = _ptrNode.get();
        while (ptr != nullptr) {
            if (ptr->_data.first == key) return &ptr->_data.second;
            else ptr = ptr->_next.get();
        }
        return nullptr;
    }

    // Const Find
    // No-Throw Guarantee
    // - Returns const pointer to the pair.second;
    const data_type* find(const key_type& key) const {
        LLNode2<pair_type>* ptr = _ptrNode.get();
        while (ptr != nullptr) {
            if (ptr->_data.first == key) return &ptr->_data.second;
            else ptr = ptr->_next.get();
        }
        return nullptr;
    }

   // Insert
   // Strong Guarantee
    void insert(const key_type key, data_type value) {
        data_type *dummyPtr = find(key);
        if (dummyPtr != nullptr) dummyPtr = &value;
        else push_front(_ptrNode,pair_type{key,value});
    }

    // Erase
    // Strong Guarantee
    void erase(const key_type key) {
        auto ptr = _ptrNode.get();
        auto prevPtr = &_ptrNode;
        while (ptr != nullptr) {
            if (ptr->_data.first == key) {
                *prevPtr = std::move(ptr->_next);
                break;
            }
            prevPtr = &ptr->_next;
            ptr = ptr->_next.get();
        }
    }

    // Traverse
    // Basic Guarantee (example unknown)
    void traverse(const std::function<void(key_type, data_type)> example) const {
        auto ptr = _ptrNode.get();
        while (ptr != nullptr) {
            example(ptr->_data.first, ptr->_data.second);
            ptr = ptr->_next.get();
        }
    }

};

#endif //PROJ6_DP6_H