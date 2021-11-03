// dp6.h
// Benjamin Stream
// Solomon Himelbloom
// 2021-10-29
// Function / class template for Project 6.

#ifndef PROJ6_DP6_H
#define PROJ6_DP6_H

#include "llnode2.h"

#include <functional> // For std::function

// Exercise A — Reversing a Linked List
template<typename ValType>
void reverseList(std::unique_ptr<LLNode2<ValType>> & head) {
    // TODO: WRITE THIS!!!
}

// Exercise B — Associative Dataset Class Template
template<typename Key, typename Val>
class LLMap {

    // key_type: type of key items
    using key_type = Key;

    // data_type: type of data items
    using data_type = Val;

public:

    // Ctor
    LLMap() : _data(nullptr) {

    }

    // Dctor
    ~LLMap() = default;

    // No other Big Five functions
    LLMap(const LLMap & other) = delete;
    LLMap & operator=(const LLMap & other) = delete;
    LLMap(LLMap && other) = delete;
    LLMap & operator=(LLMap && other) = delete;

    // size
    [[nodiscard]] size_t size() const {
        return 42; // DUMMY
        // TODO: WRITE THIS!!!
    }

    // empty
    [[nodiscard]] bool empty() const {
        return false; // DUMMY
        // TODO: WRITE THIS!!!
    }

    // find (non-const & const)
    data_type * find(const key_type & key) {
        return nullptr; // DUMMY
        // TODO: WRITE THIS!!!
    }

    const data_type * find(const key_type & key) const {
        return nullptr; // DUMMY
        // TODO: WRITE THIS!!!
    }

    // insert
    void insert(key_type key, data_type value) {
        // TODO: WRITE THIS!!!
    }

    // erase
    void erase(key_type key) {
        // TODO: WRITE THIS!!!
    }

    // traverse
    void traverse(const std::function<void(key_type, data_type)> example) const {
        // TODO: WRITE THIS!!!
    }

private:
    std::unique_ptr<LLNode2<std::pair<key_type, data_type>>> _data;
};

#endif //PROJ6_DP6_H
