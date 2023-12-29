
#include <iostream>
#include "stack_b.h"
/* PART B */
/* Dynamic Stacks */
using namespace std;

    // Constructor
Stack_B::Stack_B(){
    try{
        capacity = 1024;
        size = 0;
        stk = new int [capacity];
    }
    catch(const bad_alloc& e){
        cerr<<"Out of Memory";
    }
}
Stack_B::~Stack_B(){
        delete []stk;
    }

void Stack_B::push(int data){
        if (size<capacity){
        stk[size] = data;
        size++;}
        else {
            try{capacity *= 2;
                int *stk2;
                stk2 = new int [capacity];
                for (int i = 0; i<size;i++){
                    stk2[i] = stk[i];
                }
                stk2[size] = data;
                delete []stk;
                stk = stk2;
                size++;
            }
            catch(const std::bad_alloc& e){
                cerr<<"Out of Memory";
            }
        }
    }

int Stack_B::pop(){
        if (size==0){
            throw runtime_error("Empty Stack");
        }
        else if (size>capacity/4 || capacity <=1024){
            size--;
            return stk[size];
            
        }
        else{
            try{
                capacity /= 2;
                int *stk2;
                stk2 = new int [capacity];
                for (int i = 0; i<=size;i++){
                    stk2[i] = stk[i];
                }
                delete []stk;
                stk = stk2;
                size--;
                return stk[size];
                
            }
            catch(const std::bad_alloc& e){
                cerr<<"Out of Memory";
            }
            return 0;
        }
    }

int Stack_B::get_element_from_top(int idx){
        int arr_idx;
        arr_idx = size - idx-1;
        if (0<=arr_idx && arr_idx<size){
            return stk[arr_idx];
        }
        else{
            throw runtime_error("Index out of range");
        }
    }

int Stack_B::get_element_from_bottom(int idx){
        int arr_idx;
        arr_idx = idx;
        if (0<=arr_idx && arr_idx<size){
            return stk[arr_idx];
        }
        else{
            throw runtime_error("Index out of range");
        }
    }

void Stack_B::print_stack(bool top_or_bottom){
        if (top_or_bottom==0){
            for (int i  = 0; i<size; i++){
                cout<<stk[i]<<"\n";
            }}
        else {
            for (int i  = 1; i<=size; i++){
                cout<<stk[size-i]<<"\n";
                }
          }
    }

int Stack_B::add(){
        if (size>=2){
            int a = stk[size-1];
            int b = stk[size-2];
            stk[size-2] = a+b;
            size--;
            return stk[size-1];
        }
        else{
            throw runtime_error("Not Enough Arguments");
        }
    }
int Stack_B::subtract(){
        if (size>=2){
            int a = stk[size-1];
            int b = stk[size-2];
            stk[size-2] = b-a;
            size--;
            return stk[size-1];
        }
        else{
            throw runtime_error("Not Enough Arguments");
        }
    }
int Stack_B::multiply(){
        if (size>=2){
            int a = stk[size-1];
            int b = stk[size-2];
            stk[size-2] = a*b;
            size--;
            return stk[size-1];
        }
        else{
            throw runtime_error("Not Enough Arguments");
        }
    }
int Stack_B::divide(){
        if (size>=2){
            int a = stk[size-1];
            int b = stk[size-2];
            if (a*b>0){
                stk[size-2] = b/a;
                size--;
                return stk[size-1];
            }
            else{
                stk[size-2] = b/a-1;
                size--;
                return stk[size-1];
            }
        }
        else{
            throw runtime_error("Not Enough Arguments");
        }
    }

int *Stack_B:: get_stack(){
        return stk;
        
    } // Get a pointer to the array

int Stack_B::get_size(){
        return size;
        
    } // Get the size of the stack


