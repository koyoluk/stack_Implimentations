#include <cstddef>
#include <iostream>
#include "node.h"
/* PART B */
/* Stacks using Linked Lists */
using namespace std;


    // Use to construct a sentinel node (see list.h)
    Node::Node(bool sentinel ){
        value  = 0;
        is_sentinel=true;
        prev=nullptr;
        next=nullptr;
    }

    // Use to construct a regular node
Node::Node(int v, Node* nxt, Node* prv){
        value  = v;
        is_sentinel=false;
        next = nxt;
        prev = prv;
    }

    // Return whether a node is a sentinel node
bool Node::is_sentinel_node(){
    return is_sentinel;
}


int Node::get_value(){
        int a = value;
        return a;
    }
    

