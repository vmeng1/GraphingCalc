#ifndef LINKED_LIST_FUNCTIONS_H__
#define LINKED_LIST_FUNCTIONS_H__


#include <cassert>
#include "../../includes/node/node.h"
using namespace std;


//Linked List General Functions:
template <typename ITEM_TYPE>
void _print_list(node<ITEM_TYPE>* head);

//recursive fun! :)
template <typename ITEM_TYPE>
void _print_list_backwards(node<ITEM_TYPE> *head);

//return ptr to key or NULL
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _search_list(node<ITEM_TYPE>* head, ITEM_TYPE key);


template <typename ITEM_TYPE>
node<ITEM_TYPE>* _insert_head(node<ITEM_TYPE> *&head, ITEM_TYPE insert_this);

//insert after ptr
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _insert_after(node<ITEM_TYPE>*& head,node<ITEM_TYPE> *after_this, ITEM_TYPE insert_this);

//insert before ptr
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _insert_before(node<ITEM_TYPE>*& head, node<ITEM_TYPE>* before_this, ITEM_TYPE insert_this);

//ptr to previous node
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _previous_node(node<ITEM_TYPE>* head, node<ITEM_TYPE>* prev_to_this);

//delete, return item
template <typename ITEM_TYPE>
ITEM_TYPE _delete_node(node<ITEM_TYPE>*&head, node<ITEM_TYPE>* delete_this);

//duplicate the list...
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _copy_list(node<ITEM_TYPE>* head);

//duplicate list and return the last node of the copy
template <typename ITEM_TYPE>
node<ITEM_TYPE> *_copy_list(node<ITEM_TYPE>* &dest, node<ITEM_TYPE> *src);


//delete all the nodes
template <typename ITEM_TYPE>
void _clear_list(node<ITEM_TYPE>*& head);

//_item at this position
template <typename ITEM_TYPE>
ITEM_TYPE& _at(node<ITEM_TYPE>* head, int pos);



//-----------Functions Def-------------------//


//Linked List General Functions:
template <typename ITEM_TYPE>
void _print_list(node<ITEM_TYPE>* head){
    node<ITEM_TYPE> *walker = head;
    while (walker!=nullptr){
    //if you are here, walker is not nullptr:
    cout << *walker;
    walker = walker->_next;
    }
    cout << "|||" << endl;



}

//recursive fun! :)


template <typename ITEM_TYPE>
void _print_list_backwards(node<ITEM_TYPE> *head){

    node<ITEM_TYPE>* new_head = nullptr; //empty

    node<ITEM_TYPE>* walker = head;

    node<ITEM_TYPE>* new_head_ptr = new_head; //ptr points to what new_head is pointing to

    while (walker != nullptr){

    new_head_ptr = insert_head(new_head, walker->_item);
    walker = walker ->_next;
   

  }
    _print_list(new_head);
    _clear_list(new_head);



}


//return ptr to key or NULL
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _search_list(node<ITEM_TYPE>* head, ITEM_TYPE key){
    node<ITEM_TYPE> *walker = head;

    while (walker != nullptr && walker->_item != key){

      walker = walker -> _next;
    }


    if (walker == nullptr){ //check if item is in the list

      return nullptr; 
    }

    return walker;


}


template <typename ITEM_TYPE>
node<ITEM_TYPE>* _insert_head(node<ITEM_TYPE> *&head, ITEM_TYPE insert_this){

  node<ITEM_TYPE> *temp = new node<ITEM_TYPE>(insert_this);
  temp->_next = head;
  head = temp;
  return head;



}

//insert after ptr
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _insert_after(node<ITEM_TYPE>*& head,node<ITEM_TYPE> *after_this, ITEM_TYPE insert_this){
    if(head == nullptr){ //if head is empty, insert head

      return _insert_head(head, insert_this);

    }
    else if(after_this ==nullptr){
        return _insert_head(head, insert_this); //if after_this is at the end, insert head

    }

    _insert_head(after_this->_next, insert_this);
    return after_this->_next;

    /* 

  ---------------Based on Insert head -----------------------
  node<T> *temp = new node<T>(insert_this); //create new crate

  //I want temp ptr to point to what after_this is pointing to
  temp-> _next = after_this ->_next; 
  //I want after_this to point to the new guy
  after_this->_next = temp;
  
  return head;


*/

}

//insert before ptr
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _insert_before(node<ITEM_TYPE>*& head, node<ITEM_TYPE>* before_this, ITEM_TYPE insert_this){
    node <ITEM_TYPE> *ptr = _previous_node(head, before_this);
    _insert_after(head, ptr, insert_this); 
    return ptr;


}

//ptr to previous node
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _previous_node(node<ITEM_TYPE>* head, node<ITEM_TYPE>* prev_to_this){
    node<ITEM_TYPE> *walker = head;

    if(prev_to_this == head){ //the node is first
        return nullptr;
    }

    while (walker!= nullptr && walker->_next != prev_to_this){
        walker = walker -> _next;

    }
    assert(walker != nullptr);
  
    return walker;

}

//delete, return item
template <typename ITEM_TYPE>
ITEM_TYPE _delete_node(node<ITEM_TYPE>*&head, node<ITEM_TYPE>* delete_this){
    assert (delete_this != nullptr);

    if (delete_this == head){

        ITEM_TYPE delete_item = delete_this->_item;
        head = delete_this->_next;
        return delete_item;

    }

    //Get the previous node of delete this
    node<ITEM_TYPE> * prev_ptr = _previous_node(head, delete_this); 

    //I want the ptr of previous node to point to what delete_this ptr is pointing to
    prev_ptr -> _next = delete_this ->_next;
    ITEM_TYPE delete_item = delete_this->_item;

    delete delete_this;
    return delete_item;



}

//duplicate the list...
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _copy_list(node<ITEM_TYPE>* head){
    node<ITEM_TYPE>* walker = head;

    node<ITEM_TYPE>* new_head = nullptr; //empty
    node<ITEM_TYPE>* new_head_ptr = new_head; //ptr points to what new_head is pointing to


    while (walker != nullptr){

        new_head_ptr = _insert_after(new_head, new_head_ptr, walker->_item);
        walker = walker ->_next;

    }

  return new_head;


}

//duplicate list and return the last node of the copy
template <typename ITEM_TYPE>
node<ITEM_TYPE> *_copy_list(node<ITEM_TYPE>* &dest, node<ITEM_TYPE> *src){

    
    dest = nullptr; //empty

    node<ITEM_TYPE>* walker = src;

    node<ITEM_TYPE>* dest_ptr = dest; 

    while (walker != nullptr){

        dest_ptr = _insert_after(dest, dest_ptr, walker->_item);
        walker = walker ->_next;

    }

  return dest_ptr;


}


//delete all the nodes
template <typename ITEM_TYPE>
void _clear_list(node<ITEM_TYPE>*& head){
    node<ITEM_TYPE>* walker = head;
  
    while (walker != nullptr){

        node<ITEM_TYPE>* delete_this = walker;
        head = walker->_next;
        walker = walker->_next;
        delete delete_this;

    }

    delete head;




}

//_item at this position
template <typename ITEM_TYPE>
ITEM_TYPE& _at(node<ITEM_TYPE>* head, int pos){

    node<ITEM_TYPE>* walker = head;
    int i = 0;
    while (walker != nullptr){

        if (i == pos){

            return walker ->_item;
        }
    
        walker = walker ->_next;
        i++;

    }

  assert(walker!=nullptr);

    return walker -> _item;


}





#endif


    