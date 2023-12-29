#include <cstddef>
#include <iostream>
#include "stack_c.h"
#include "list.h"
/* PART B */
/* Stacks using Linked Lists */
using namespace std;

    // Constructor
Stack_C::Stack_C(){
     stk = new List();
}

    // Destructor
Stack_C::~Stack_C(){
    if(stk!=nullptr){
    delete stk;
    stk = nullptr;}
}

void Stack_C::push(int data){
        stk->insert(data);
        
    }

int Stack_C::pop(){
        int a = stk->get_size();
        if (a==0){
            throw runtime_error("Empty Stack");
        }
        else{
            return stk->delete_tail();
        }
    }

int Stack_C::get_element_from_top(int idx){
        int a = stk->get_size();
        if (idx<0 || idx>=a){
            throw runtime_error("Index out of range");
        }
        else{
            Node* temp = stk->get_head();
            for(int i = 0; i<=(a-idx-1); i++){
                temp = temp->next;
            }
            return temp->get_value();
        }
    }
int Stack_C::get_element_from_bottom(int idx){
        int a = stk->get_size();
        if (idx<0 || idx>=a){
            throw runtime_error("Index out of range");
        }
        else{
            Node*temp = stk->get_head();
            for(int i = 0; i<=idx; i++){
                temp = temp->next;
            }
            return temp->get_value();
        }
    }

void Stack_C::print_stack(bool top_or_bottom){
        if (stk->get_size()!=0){
            if (top_or_bottom==0){
                Node*temp = stk->get_head();
                temp = temp->next;
                while(temp->next != nullptr){
                    cout<<temp->get_value()<<" ";
                    temp = temp->next;
                }
                cout<<"\n";
            }
            else{
                Node*temp = stk->get_head();
                while(temp->next->next !=nullptr){
                    temp = temp->next;
                }
                while(temp->prev != nullptr){
                    cout<<temp->get_value()<<" ";
                    temp = temp->prev;
                }
                cout<<"\n";
            }
            
        }
        else{
            throw runtime_error("Empty Stack");
        }
    }

int Stack_C::add(){
        int a = stk->get_size();
        if (a<2){
            throw runtime_error("Not Enough Arguments");
        }
        else{
            int b = stk->delete_tail();
            int c = stk->delete_tail();
            stk->insert(b+c);
            return b+c;
        }
    }

int Stack_C::subtract(){
        int a = stk->get_size();
        if (a<2){
            throw runtime_error("Not Enough Arguments");
        }
        else{
            int b = stk->delete_tail();
            int c = stk->delete_tail();
            stk->insert(c-b);
            return c-b;
        }
    }

int Stack_C::multiply(){
        int a = stk->get_size();
        if (a<2){
            throw runtime_error("Not Enough Arguments");
        }
        else{
            int b = stk->delete_tail();
            int c = stk->delete_tail();
            stk->insert(b*c);
            return b*c;
        }
    }

int Stack_C::divide(){
        int a = stk->get_size();
        if (a<2){
            throw runtime_error("Not Enough Arguments");
        }
        else{
            int b = stk->delete_tail();
            int c = stk->delete_tail();
            if(c*b<0){
                stk->insert(c/b-1);
                return c/b-1;
            }
            else{
            stk->insert(c/b);
                return c/b;
            }
            
        }
    }

List* Stack_C::get_stack(){
        return stk;
    } // Get a pointer to the linked list representing the stack

int Stack_C::get_size(){
        return stk->get_size();
    } // Get the size of the stack

