#ifndef NODE_H_
#define NODE_H_

#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <list>
using namespace std;


template <typename ITEM_TYPE>
struct node
{
public:
    node(const ITEM_TYPE& item = ITEM_TYPE(), node<ITEM_TYPE>* next = nullptr){
         _item = item; 
        _next = next;
    }

    
    friend ostream& operator <<(ostream& outs, const node<ITEM_TYPE> &printMe){
        outs<<"["<< printMe._item <<"]->";
        return outs;


    }
    ITEM_TYPE _item;
    node<ITEM_TYPE>* _next;
};


#endif 
