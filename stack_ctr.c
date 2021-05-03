#include <stdio.h>
#include <stdlib.h>
#include "stack_ctr.h"

/* Local Variables */
int first_node_flag = 0;

/* Local Functions */
void stores_smallest_value(node_s **top, node_s **next);
int node_is_empty(node_s *node);


int node_is_empty(node_s *node){
    if(node != NULL) return 0;
    return 1;
}

int push(node_s **node, float value){
    node_s *new_node = (node_s*)malloc(sizeof(node_s));
    node_s *old_node= *node;
    int ret = 0;
    if(new_node){                   // If memory allocated
        new_node->data = value;     // Store requested item in new node
        new_node->next = old_node;  // Stores address from previous node
        *node = new_node;           // Update stack top
        if(node_is_empty(old_node))first_node_flag = 1; // If first node, set flag
        else first_node_flag = 0;
        stores_smallest_value(&new_node, &old_node); // Store smallest value so far
        ret = 1;
    }
    return ret;
 }

 int pop(node_s **node){
    int ret=1;
    node_s *top_node = *node;
    if(!node_is_empty(top_node)) {  // Update stack top
        *node = top_node->next;     // Remove from stack
        free(top_node);             // Frees up memory
    }
    if(node_is_empty(*node)) ret = 0;
    return ret;
}

void stores_smallest_value(node_s **top, node_s **next){
    node_s *top_node = *top;
    node_s *next_node = *next;

    if (first_node_flag == 1) { // If first node
        top_node->smallest_value = &top_node->data; // Stores first data
    } else {                                        // Else, compare values
        if (top_node->data < *next_node->smallest_value) {
            top_node->smallest_value = &top_node->data;
        } else {
            top_node->smallest_value = next_node->smallest_value;
        }
    }
}

float top(node_s *node, int *has_top){
    node_s *top_node = node;
    if(!node_is_empty(node)) {      // If node is not empty
            *has_top = 1;           // It has a top value
            return top_node->data;  // Return node value
    }
    *has_top = 0;
}

float mini(node_s **node, int *has_min){
     *has_min = 0;
     node_s *top_node = *node;
    if (!node_is_empty(top_node)) {         // If node is not empty
        *has_min = 1;                       // It has a minimum value
        return *top_node->smallest_value;   // Return smallest value
    }
 }
