#include <cstddef>
#include <iostream>
#include "node.h"
#include "list.h"
using namespace std;

List::List(){
        sentinel_head = new Node(true);
        sentinel_tail = new Node(true);
        sentinel_head->next = sentinel_tail;
        sentinel_tail->prev = sentinel_head;
        sentinel_head->prev = nullptr;
        sentinel_tail->next = nullptr;
        size = 0;
}

List::~List(){
    Node*temp = sentinel_head->next;
    while(temp!=sentinel_tail){
        temp = temp->next;
        delete temp->prev;
    }
    sentinel_head->next = sentinel_tail;
    sentinel_tail->prev = sentinel_head;
}

    // Insert an element at the tail of the linked list
void List::insert(int v){
        if(size == 0){
            try{
                Node* A = new Node(v,sentinel_tail,sentinel_head);
                sentinel_head->next = A;
                sentinel_tail->prev = A;
                
                size++;
            }
            catch(const std::bad_alloc& e){
                cerr<<"Out of Memory";
            }
        }
        else{
            try{
            Node *C = sentinel_head;
            while(C->next != sentinel_tail){
                C = C->next;
            }
            
            Node *A = new Node(v,sentinel_tail,C);
            C->next = A;
            sentinel_tail->prev = A;
            size++;
        }
            catch(const std::bad_alloc& e){
                cerr<<"Out of Memory";
            }
        }
        
    }

    // Delete the tail of the linked list and return the value
    // You need to delete the valid tail element, not the sentinel
int List::delete_tail(){
    if(size>0){
        Node *C = sentinel_head;
        while(C->next != sentinel_tail){
            C = C->next;
        }
        C->prev->next = sentinel_tail;
        sentinel_tail->prev = C->prev;
        int a = C->get_value();
        delete C;
        size--;
        return a;
        
    }
    else{
        throw runtime_error("Empty Stack");
    }
    }

    // Return the size of the linked list
int List::get_size(){
        return size;
    }

    // Return a pointer to the sentinel head of the linked list
Node* List::get_head(){
        return sentinel_head;
    }


