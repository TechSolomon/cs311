// dp6.h
// Benjamin Stream
// Solomon Himelbloom
// 2021-10-29
// Function / class template for Project 6.

#ifndef PROJ6_DP6_H
#define PROJ6_DP6_H

#include "llnode2.h"

#include <memory> // For std::unique_ptr
#include <utility> // For std::move, std::pair
#include <functional> // For std::function

// Exercise A — Reversing a Linked List
template<typename ValType>
void reverseList(std::unique_ptr<LLNode2<ValType>> & head) {
    // TODO: WRITE THIS!!!
}

// Exercise B — Associative Dataset Class Template (LLMap)
// pair_type must be std::pair or struct (or any appropriate key-value type)
template<typename Key, typename Val>
class LLMap {

    // key_type: type of key items
    using key_type = Key;

    // data_type: type of data items
    using data_type = Val;

    // FIXME – pair_type: type of _____ items
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
    [[nodiscard]] size_t size() const {
        return ::size(_ptrNode);
    }

    // empty
    // No-Throw Guarantee
    [[nodiscard]] bool empty() const {
        if (_ptrNode)
            return false; // checks if _data (smart pointer) is null
        else
            return true;
    }

    // Non-Const Find
    // No-Throw Guarantee
    // FIXME: Returns pointer to the pair.second;
    data_type* find(const key_type& key) {
        LLNode2<pair_type>* ptr = _ptrNode.get();

        while (ptr != nullptr)
        {
            if (ptr->_data.first == key)  return  &ptr->_data.second;

            else  ptr = ptr->_next.get();
        }
        return nullptr;
    }

    // Const Find
    // TODO: No-Throw Guarantee
    const data_type* find(const key_type& key) const {
        LLNode2<pair_type>* ptr = _ptrNode.get();

        while (ptr != nullptr)
        {
            if (ptr->_data.first == key)  return  &ptr->_data.second;

            else  ptr = ptr->_next.get();
        }
        return nullptr;
    }

   // Insert
   // TODO: ??? Guarantee
    void insert(const key_type key, data_type value) {
        data_type * dummyPtr = find(key);
        // pair_type dummyPair{ key,value };
        if (dummyPtr != nullptr)
            dummyPtr = &value;
        else
            push_front(_ptrNode,pair_type{key,value});
    }

    // Erase
    // No-Throw Guarantee
    void erase(const key_type key) {

        auto ptr = _ptrNode.get();
        auto prevPtr = &_ptrNode;
        while (ptr != nullptr)
        {
            
            if (ptr->_data.first == key) 
            {
                *prevPtr = std::move(ptr->_next);
                break;
            }

            prevPtr = &ptr->_next;
            ptr = ptr->_next.get();
        }
    }

    // Transverse
    // TODO: ??? Guarantee
    void traverse(const std::function<void(key_type, data_type)> example) const {
        // TODO: WRITE THIS!!!
        // auto go through LLMap
        // someFunction() works on data
        // end
    }

};

#endif //PROJ6_DP6_H