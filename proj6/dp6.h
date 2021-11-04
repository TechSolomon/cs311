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

// Exercise B — Associative Dataset Class Template


// Class LLMap
// pair_type must be std::pair or struct (or any appropriate key-value type)


template<typename Key, typename Val>
class LLMap {

    // key_type: type of key items
    using key_type = Key;

    // data_type: type of data items
    using data_type = Val;

    using pair_type = std::pair<key_type, data_type>;


    // ***** LLMap: Data Member *****
private:
    std::unique_ptr<LLNode2<pair_type>> _data;

public:

    // ***** LLMAP: ctors, dctors, ops *****

    // Ctor
    LLMap() : _data(nullptr) {

    }

    // Dctor
    ~LLMap() = default;

    // No other Big Five functions
    LLMap(const LLMap& other) = delete;
    LLMap& operator=(const LLMap& other) = delete;
    LLMap(LLMap&& other) = delete;
    LLMap& operator=(LLMap&& other) = delete;



    // ***** LLMap: Public Functions *****
public:

    // size
    // No-Throw Guarantee
    [[nodiscard]] size_t size() const {
        return _data->size(_data.get());
      
    }

    // empty
    // No-Throw Guarantee
    [[nodiscard]] bool empty() const {
        if (!_data) //checks if _data (smart pointer) is null
            return true;
        else
            return false;
    }

    // Non-Const Find
    // No-Throw Guarantee
    data_type* find(const key_type& key) {

//        auto p = _data.get();
//        while (p != nullptr) {
//            if (key == p->_next())
//                return _data.get();
//           p = p->_next.get();
//        }
        return nullptr;
    }

    // Const Find
    // TODO: ??? Guarantee
    const data_type* find(const key_type& key) const {
       LLNode2<pair_type> *ptr = _data.get();
       
        while (_data) 
        {
            if (key == ptr->_data.first())  return * ptr->_data;
            else  ptr = ptr->_next.get();
        }
        return nullptr;
    }

   // Insert
   // TODO: ??? Guarantee
    void insert(key_type key, data_type value) {
        pair_type * ptr = find(key);
//        if (p != nullptr)
//            p.second() = value;
//        else
//            _data->push_front(_data, pair_type());
    }

    // Erase
    // No-Throw Guarantee
    void erase(key_type key) {
        auto p = find(key);
        if (p != nullptr) {
         // free data
        }
    }

    // Transverse
    // TODO: ??? Guarantee
    void traverse(const std::function<void(key_type, data_type)> example) const {
        // TODO: WRITE THIS!!!
        // auto go through LLMAP
        // someFunction() works on data
        // end
    }

};

#endif //PROJ6_DP6_H