#ifndef MY_QUEUE_H
#define MY_QUEUE_H


#include "../../includes/linked_list_functions/linked_list_functions.h"

template <typename T>
class Queue
{
public:
    class Iterator{
    public:
        friend class Queue;          //give access to list to access _ptr
        Iterator(){
            _ptr = nullptr; //doesn't point to anything

        }                  //default ctor
        Iterator(node<T>* p){
            _ptr = p;
        }        //Point Iterator to where p is pointing to
                                                    //Point Iterator to where                                              //  is pointing to
        T &operator*(){                             //dereference operator
            return _ptr ->_item; 
            
        }

        T *operator->(){
            T *ptr;
            ptr = &(_ptr ->_item);
            return ptr;

        }                            //member access operator
        bool is_null(){

            if (_ptr == nullptr){
                return true;
            }
            return false;

        }                             //true if _ptr is NULL
        friend bool operator!=(const Iterator &left, const Iterator &right){
            if (left._ptr != right._ptr){
                return true;
            }
            return false;

        } //true if left != right

        friend bool operator==(const Iterator &left, const Iterator &right){
            if (left._ptr == right._ptr){
                return true;
            }
            return false;

        } //true if left == right

        Iterator &operator++(){
            _ptr = _ptr -> _next;
            return Iterator(_ptr);       //member operator:
        }                     //  ++it; or
                                                        //  ++it = new_value

        friend Iterator operator++(Iterator &it, int unused){
            Iterator hold;
            hold = it;
            it._ptr = it._ptr ->_next; 
            return hold;
            
        }          //friend operator: it++

    
    private:
        node<T>* _ptr;               //pointer being encapsulated
    };

    Queue(){

        _front = nullptr;
        _rear = nullptr;
        _size = 0;
    }

    Queue(const Queue<T>& copyMe){
       
        _size = copyMe._size;

        _rear = _copy_list(_front, copyMe._front);

    }
    ~Queue(){

        _clear_list(_front);

    }
    Queue& operator=(const Queue<T>& RHS){
        if(this == &RHS){
            return *this;
        }
        _clear_list(_front);
        _rear = _copy_list(_front, RHS._front);
        _size = RHS._size;

        return *this;

    }

    bool empty(){
        if(_front == nullptr){

            return true;
        }
        return false;
    }
    T front(){

        return _front->_item;
    }
    T back(){
        return _rear->_item;
       
    }


    void push(T item){

        
        _rear = _insert_after(_front, _rear, item);
        _size++;

    }
    T pop(){
        _size--;
        return _delete_node(_front, _front);

    }

    Iterator begin() const{
        Iterator _ptr;
        _ptr = _front;
        return _ptr;
    }            //Iterator to the head node
    Iterator end() const{

        return Iterator(nullptr);
    }

    void print_pointers();


    int size() const { return _size; }
    
    friend ostream& operator << (ostream& outs, const Queue& printMe){
         _print_list(printMe._front);
        return outs;
    }
private:
    node<T>* _front;
    node<T>* _rear;
    int _size;
};

#endif