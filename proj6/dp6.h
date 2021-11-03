// dp6.h
// Benjamin Stream
// Solomon Himelbloom
// 2021-10-29
// Function / class template for Project 6.

#ifndef PROJ6_DP6_H
#define PROJ6_DP6_H

#include "llnode2.h"

// Exercise A — Reversing a Linked List
template<typename ValType>
void reverseList(std::unique_ptr<LLNode2<ValType>> & head) {
    // TODO: WRITE THIS!!!
}

// Exercise B — Associative Dataset Class Template


//Class LLMap
//KVType must be std::pair or struct (or any appropriate key-value type)


template<typename Key, typename Val>
class LLMap {

    // key_type: type of key items
    using key_type = Key;

    // data_type: type of data items
    using data_type = Val;

   using KVType = std::pair<key_type, data_type>;

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
    [[nodiscard]] size_t size() const {
        int counter = 0;
        while (true) {
            if(_data.)
            ++counter;
            
        }
    }

    //empty
    //No-Throw Guarantee
    [[nodiscard]] bool empty() const {
        if (!_data) //checks if _data (smartpointer) is null
        {
            return true;
        }
        else return false;
    }

    //Non-Const Find
    //??? Guarantee
    data_type* find(const key_type& key) {
        //TODO: WRITE THIS!!!
       //if Data_type found
        return _data*;
        //else not found
        return nullptr;
    }

    //Const Find
    //??? Guarantee
    const data_type* find(const key_type& key) const {
        //TODO: WRITE THIS!!!
        //if Data_type found
        return const _data*;
        //else not found
        return nullptr;
    }

   //Insert
   //??? Guarantee
    void insert(key_type key, data_type value) {
        // TODO: WRITE THIS!!!
        if (find(key) != nullptr)
        {
            
        }
        else
        {
            _data = unique_ptr<LLNode2<std::pair<key,value>>>;
        }
    }

    //Erase
    //No-Throw Guarantee
    void erase(key_type key) {
        if (find(key)) {

        }
    }

    //Transverse
    // ??? Guarantee
    void traverse(const std::function<void(key_type, data_type)> example) const {
        // TODO: WRITE THIS!!!
        //auto go through LLMAP
        //someFunction() works on data
        //end
    }


    // ***** LLMap: Data Member *****
private:
    std::unique_ptr<LLNode2<KVType>> _data;
};

#endif //PROJ6_DP6_H