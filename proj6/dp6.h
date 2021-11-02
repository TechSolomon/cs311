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

template<typename KVType>
class LLMap {
public:

// ***** LLMAP: ctors, dctors, ops *****
private:

//Default Constructor
//Strong Guarantee
    explicit LLMap()
        :_LLMapptr = unique_ptr<nullptr>;
    {}


//Deconstructor
//No-Throw Guarantee
    ~LLMap()
    {
        _LLMapptr.reset;
    }

// ***** LLMap: Data Member *****
private:
    auto _LLMapptr = unique_ptr<LLNode2<KVType>>;

// ***** LLMap: Public Functions *****
public:

    //size
    //TODO
    int size() {
        return 1;
    }

    //empty
    //No-Throw Guarantee
    bool empty() {
        if (this->size() != 0) {
            return false;
        }
        else return true;
    }

    //Non-Const Find
    //??? Guarantee

   auto find(auto DATA_TYPE) {
        //if Data_type found
        return DATA_TYPE*;
        //else
        //return nullptr
    }

    //Const Find
    //??? Guarantee
   auto const find(auto const DATA_TYPE) {
        //if Data_type found
        return const DATA_TYPE*;
        //else not found
        //return nullptr
    }

   //Insert
   //??? Guarantee
   void insert(auto KEY_TYPE, auto DATA_TYPE)
   {
       //goto keytype if exists
       //set value to data_type
       //else  _LLMapptr = unique_ptr<LLNode2<KVType>(KEY_TYPE,DATA_TYPE)>;
   }

   //Erase
   //No-Throw Guarantee
   void erase(auto KEY_TYPE)
   {
       //if keytype exists goto keytpe
       // _LLMAPPtr = nullptr;
       //else nothing
   }

   //Transverse
   // ??? Guarantee
   void transverse(auto someFunction(auto KEY_TYPE,auto DATA_TYPE))
   {
       //auto go through LLMAP
       //someFunction() works on data
       //end
   }

};

#endif //PROJ6_DP6_H
