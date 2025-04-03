#ifndef ARRAY_FUNCTIONS_H
#define ARRAY_FUNCTIONS_H
#include <iostream>

using namespace std;

const int MINIMUM_CAPACITY = 3;

template<class T>
T* allocate(int capacity= MINIMUM_CAPACITY);            //allocate 'capacity' 
                                                        //      elements. 
                                                        //  return array

template<class T>
T* reallocate(T* a, int size, int capacity);            //take array, resize it 
                                                        //  return new array. 
                                                        //  delete old array

template<class T>
void print_array(T* a, int size, 
            int capacity = 0, ostream& outs = cout);    //prints 
                                                        //  (size/capacity)
                                                        //  for debugging

template <class T>
void print(T* a, unsigned int how_many, 
                                ostream& outs = cout);  //print array

template<class T>
T* search_entry(T* a, int size, const T& find_me);      //search for 'find me'

template <class T>
int search(T* a, int size, const T& find_me);           //search for 'find_me' 

template <class T>
void shift_left(T* a, int& size, int shift_here);       //shift left @ pos:
                                                        //    erases @ pos
template <class T>
void shift_left(T* a, int& size, T* shift_here);        //shift left @ pos: 

template <class T>
void shift_right(T *a, int &size, int shift_here);      //shift right: 
                                                        //      make a hole

template <class T>
void shift_right(T *a, int &size, T* shift_here);       //shift right: 
                                                        //   make a hole

template<class T>
void copy_array(T *dest, T* src, 
                                int many_to_copy);      //copy from src to dest

template <class T>
T* copy_array(T const *src, int size);                  //return a 
                                                        //  copy of src

template <class T>
string array_string( T *a, int size);              //return array 
                                                        //  as a string








template<class T>
T *allocate(int capacity){
    T *array_ptr = new T[capacity];
    return array_ptr;
}                                                          //allocate 'capacity' 
                                                        //      elements. 
                                                        //  return array

template<class T>
T* reallocate(T* a, int size, int capacity){
    T *array_ptr = new T[capacity];
    T *array_start = array_ptr;
    T *a_start = a;
    for (int i = 0; i < size; i++){
        *array_ptr = *a;
        array_ptr++;
        a++; 
    }    
    delete[] a_start;
    return array_start;
}

                                                        //    erases @ pos
                                                    //take array, resize it 
                                                        //  return new array. 
                                                        //  delete old array

template<class T>
void print_array(T* a, int size, int capacity, ostream& outs){
    T *array_ptr = a;
    cout << "( " << size << "/" << capacity << " )";
    for (int i = 0; i < size; i++){
        cout <<  "[" << *array_ptr << "] ";
        array_ptr++;
        
    }
    cout << endl;

}

                                                   //prints 
                                                        //  (size/capacity)
                                                        //  for debugging

template <class T>
void print(T* a, unsigned int how_many, ostream& outs){
     T *array_ptr = a; 
     for (int i = 0; i < how_many; i++){
        cout <<  "[" << *array_ptr << "] ";
        array_ptr++;
    }
}                                                          //print array

template<class T>
T* search_entry(T* a, int size, const T& find_me){
    T *array_ptr = a;
    for (int i = 0; i < size; i++){
        if (*array_ptr == find_me){
            return array_ptr;
        }
        array_ptr++;
    }
    return nullptr;                                                         //search for 'find me' (address)
}


template <class T>
int search(T* a, int size, const T& find_me){
    T *array_ptr = a;
    for (int i = 0; i < size; i++){
        if (*array_ptr == find_me){
            return i;
        }
        array_ptr++;
    }
    return -1;  
}                                                        //search for 'find_me' (index)

template <class T>
void shift_left(T* a, int& size, int shift_here){
    T *array_ptr = a;
    T *temp;
    T *temp2;
    for (int i = shift_here; i < size - 1; i++){
        temp = array_ptr + i;
        temp2 = temp + 1;
        *temp = *temp2;
    }
    size--;
}                                                           //shift left @ pos:
                                                        //    erases @ pos

template <class T>
void shift_left(T* a, int& size, T* shift_here){
    T *array_ptr = a;
    T *temp;
    T *temp2;
    for (T *i = shift_here; i < array_ptr + size - 1; i++){
        temp = i;
        temp2 = temp + 1;
        *temp = *temp2;
    }
    size--;
}                                                           //shift left @ pos: 
                                                        //    erases @ pos


template <class T>
void shift_right(T *a, int &size, int shift_here){
    T *array_ptr = a;
    T *end_ptr = array_ptr + size - 1;
    T *temp;
    T *temp2;
    for (int i = size; i > shift_here; i--){
        temp = end_ptr;
        temp2 = temp - 1;
        *temp = *temp2;
        end_ptr--;
    }
    size++;
}                                                          //shift right: 
                                                        //      make a hole

template <class T>
void shift_right(T *a, int &size, T* shift_here){
    T *array_ptr = a;
    T *end_ptr = array_ptr + size - 1;
    T *temp;
    T *temp2;
    size++;
    for (T *i = end_ptr; i > shift_here; i--){
        temp = end_ptr;
        temp2 = temp - 1;
        *temp = *temp2;
        end_ptr--;
    }
}                                                       //shift right: 
                                                        //   make a hole


template<class T>
void copy_array(T *dest, T* src, int many_to_copy){
    T *src_ptr = src;
    T *dest_ptr = dest;
    T *temp;
    for (int i = 0; i < many_to_copy; i++){
        temp = src_ptr;
        *dest = *temp;
        src_ptr++;
        dest++;
    }
}
                                              //copy from src to dest

template <class T>
T* copy_array(T *src, int size){
    T *src_ptr = src;
    T *array_ptr = new T[size];
    T *start_ptr = array_ptr;
    T *temp;
    for (int i = 0; i < size; i++){
        temp = src_ptr;
        *array_ptr = *temp;
        src_ptr++;
        array_ptr++;
    }
    return start_ptr;
}                                                      //return a 
                                                        //  copy of src

template <class T>
string array_string(T *a, int size){
    T *array_ptr = a;
    string str;
    T *temp;
    for (int i = 0; i < size; i++){
        temp = array_ptr + i; 
        str += to_string(*temp);

    }
    return str;
}                                                          //return array 
                                                        //  as a string 
#endif