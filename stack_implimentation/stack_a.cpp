//
//  main.cpp
//  polish
//
//  Created by Naman Goyal on 13/08/23.
//

#include <iostream>
#include "stack_a.h"
using namespace std;
/* PART A */
/* Stacks using Fixed Size Arrays */


    // Constructor
Stack_A::Stack_A(){
     size = 0;
    }

void Stack_A:: push(int data){
        if (size<1024){
        stk[size] = data;
        size++;}
        else {
            throw runtime_error("Stack Full");
            
        }
    }

int Stack_A:: pop(){
        if (size==0){
            throw runtime_error("Empty Stack");
        }
        else{
            size--;
            return stk[size];
        }
    }

int Stack_A:: get_element_from_top(int idx){
        int arr_idx;
        arr_idx = size - idx-1;
        if (0<=arr_idx && arr_idx<size){
            return stk[arr_idx];
        }
        else{
            throw runtime_error("Index out of range");
        }
    }
int Stack_A:: get_element_from_bottom(int idx){
        int arr_idx;
        arr_idx = idx;
        if (0<=arr_idx && arr_idx<size){
            return stk[arr_idx];
        }
        else{
            throw runtime_error("Index out of range");
        }
        
    }

void Stack_A:: print_stack(bool top_or_bottom){
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

int Stack_A:: add(){
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

int Stack_A:: subtract(){
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

int Stack_A:: multiply(){
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

int Stack_A:: divide(){
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

int *Stack_A::get_stack(){
        return stk;
        
    } // Get a pointer to the array

int Stack_A:: get_size(){
        return size;
        
    } // Get the size of the stack


