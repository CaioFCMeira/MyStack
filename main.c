#include <stdio.h>
#include "stack_ctr.h"

node_s *node_one = NULL;
node_s *node_two = NULL;

int main(){

    int ok, full, idx;
    float val;
    float fill_one[5] = {1, 2, -2, 6, 5};
    float fill_two[5] = {-5.1, 1, -1, 0, 12};
    float fill_three[5] = {-.5, -9.3, -1, 1, 5.9};


    printf("\n=====Testing functions with one stack (node_one)=====\n");

    /* --- Stack one test --- */
    printf("Filling stack one:\n");
    for (idx = 0; idx<5; idx++) {
        push(&node_one, fill_one[idx]);
        if(idx == 4)printf("top > %f\n", top(node_one, &ok));
        else printf("      %f\n", top(node_one, &ok));
    }

    printf("\nCheck smallest Value:\n");
    val = mini(&node_one, &ok);
    if(ok) printf("      %f\n", val);
    else printf("      Stack is empty\n");

    printf("\nPop three items:\n");
    for (idx = 0; idx < 3 ; idx++) {
        if(pop(&node_one)) printf("      New Top: %f\n", top(node_one, &ok));
        else printf("      The stack is empty\n");
    }

    printf("\nGet smallest Value: \n");
    val = mini(&node_one, &ok);
    if(ok) printf("      %f\n", val);
    else printf("      Stack is empty\n");

    printf("\nEmpty the stack:\n");
    full = 1;
    while(full) full = pop(&node_one);
    printf("      ... The stack is empty\n");

    printf("\nTry to get top value:\n");
    val = top(node_one, &ok);
    if(ok) printf("      %f\n", val);
    else printf("      No top value, the stack is empty\n");

    printf("\nTry to pop an empty stack:\n");
    if(pop(&node_one)) printf("      New Top: %f\n", top(node_one, &ok));
    else printf("      No node, the stack is empty\n");

    printf("\nTry to check minimum value:\n");
    val = mini(&node_one, &ok);
    if(ok) printf("      %f\n", val);
    else printf("      No minimum value, the stack is empty\n");

    printf("\nRepopulate Stack One:\n");
    for(idx = 0; idx < 5; idx++){
        push(&node_one, fill_two[idx]);
        if(idx == 4)printf("top   %f\n", top(node_one, &ok));
        else printf("      %f\n", top(node_one, &ok));
    }

    printf("\nCheck smallest Value:\n");
    val = mini(&node_one, &ok);
    if(ok) printf("      %f\n", val);
    else printf("      No minimum value, the stack is empty\n");

    printf("\nGet top value:\n");
    val = top(node_one, &ok);
    if(ok) printf("      %f\n", val);
    else printf("      No top value, the stack is empty\n");

    printf("\n=====Testing functions with two stack (node_two)=====\n");
    printf("               No memory conflict\n");

    /* --- Stack two test --- */
    printf("\nFilling stack two:\n");
    for (idx = 0; idx<5; idx++) {
        push(&node_two, fill_two[idx]);
        if(idx == 4)printf("top   %f\n", top(node_two, &ok));
        else printf("      %f\n", top(node_two, &ok));
    }

    printf("\nCheck smallest Value:\n");
    val = mini(&node_two, &ok);
    if(ok) printf("      %f\n", val);
    else printf("      Stack is empty\n");

    printf("\nPop three items:\n");
    for (idx = 0; idx < 3 ; idx++) {
        if(pop(&node_two)) printf("      New Top: %f\n", top(node_two, &ok));
        else printf("      The stack is empty\n");
    }

    printf("\nGet smallest Value: \n");
    val = mini(&node_two, &ok);
    if(ok) printf("      %f\n", val);
    else printf("      Stack is empty\n");

    printf("\nEmpty the stack:\n");
    full = 1;
    while(full) full = pop(&node_two);
    printf("      ... The stack is empty\n");

    printf("\nTry to get top value:\n");
    val = top(node_two, &ok);
    if(ok) printf("      %f\n", val);
    else printf("      No top value, the stack is empty\n");

    printf("\nTry to pop an empty stack:\n");
    if(pop(&node_two)) printf("      New Top: %f\n", top(node_two, &ok));
    else printf("      No node, the stack is empty\n");

    printf("\nTry to check minimum value:\n");
    val = mini(&node_two, &ok);
    if(ok) printf("      %f\n", val);
    else printf("      No minimum value, the stack is empty\n");

    printf("\nRepopulate Stack Two:\n");
    for(idx = 0; idx < 5; idx++){
        push(&node_two, fill_three[idx]);
        if(idx == 4)printf("top   %f\n", top(node_two, &ok));
        else printf("      %f\n", top(node_two, &ok));
    }

    printf("\nCheck smallest Value:\n");
    val = mini(&node_two, &ok);
    if(ok) printf("      %f\n", val);
    else printf("      No minimum value, the stack is empty\n");

    printf("\nGet top value:\n");
    val = top(node_two, &ok);
    if(ok) printf("      %f\n", val);
    else printf("      No top value, the stack is empty\n");

    printf("\nCheck stack one:\n");
    printf("top   %f\n", top(node_one, &ok));
    if(pop(&node_one)) printf("      %f\n", top(node_one, &ok));
    if(pop(&node_one)) printf("      %f\n", top(node_one, &ok));
    if(pop(&node_one)) printf("      %f\n", top(node_one, &ok));
    if(pop(&node_one)) printf("      %f\n", top(node_one, &ok));

    printf("\n=====End routine=====\n");
    printf("Release memories\n");
    full = 1;
    while(full) full = pop(&node_one);
    full = 1;
    while(full) full = pop(&node_two);
    printf("      ... Memories are free\n\n");

     return 0;
}
