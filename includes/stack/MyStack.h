#ifndef MY_STACK_
#define MY_STACK_

//like grid

#include "../../includes/linked_list_functions/linked_list_functions.h"

template <typename T>
class Stack{
public:
    class Iterator{
    public:
        friend class Stack;                     //give access to list to access _ptr
        Iterator(){_ptr = NULL;}                //default ctor
        Iterator(node<T>* p){_ptr =p;}          //Point Iterator to where
       
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
        node<T>* _ptr;                          //pointer being encapsulated
    };

    Stack(){
        _top = nullptr;
        _size = 0;
    }
    Stack(const Stack<T>& copyMe){

        _top = _copy_list(copyMe._top);
        _size = copyMe._size;
    }
    ~Stack(){

        _clear_list(_top);
        _size = 0;

    }
    Stack<T>& operator=(const Stack<T>& RHS){
        if(this == &RHS){
            return *this;
        }
        
        _clear_list(_top);
        _top = _copy_list(RHS._top);
        _size = RHS._size;

       
        return *this;
    

    }
    T top(){

        return _top->_item;
    }
    bool empty(){

        if (_top == nullptr){

            return true;
        }
        return false;
    }
    void push(T item){

        _top = _insert_head(_top,item);
        _size++;
    }
    T pop(){
         _size--;
        return _delete_node(_top, _top);
        

    }
    
    friend ostream& operator<<(ostream& outs, const Stack& printMe){
        _print_list(printMe._top);
        return outs;
    }

    Iterator begin() const{
        Iterator _ptr;
        _ptr = _top;
        return _ptr;
    }              //Iterator to the head node
    Iterator end() const{
        return Iterator(nullptr);
    }                //Iterator to NULL
    int size() const { return _size; }

private:
    node<T>* _top;
    int _size;
};

#endif