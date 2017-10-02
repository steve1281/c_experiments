
#include <stdio.h>
#include <stdlib.h>
#include "sinewave.h"
#include "node.h"
#include "link_lists.h"
#include "test.h"


void banner()
{
    printf(" +-------------------------------+ \n");
    printf(" |                               | \n");
    printf(" |   Simple Doubly Linked List   | \n");
    printf(" |                               | \n");
    printf(" +-------------------------------+ \n");
    printf("\n\n");
    printf("In a doubly linked list you can traverse left or right down the chain.\n");
    printf("This is convienent, but comes at a cost of maintaining the links.\n");
    printf("The left most node is referred to as the head.\n");
    printf("The right most node is the tail.\n");
    printf("\n");
    printf("Each link has a pointer to a node. A node can be anything you want.\n");
    printf("For this example, a node contains two int values, x and y.\n");
    printf("---------------------------------------------------------------\n");
    printf("\n"); 
}

void run_tests()
{
    
    int nc=0;
    link *h;
    
    h = init(&nc);
    test1(h, &nc);
    test2(h, &nc);
    test3(h, &nc);
    test4(h);    

    // free memory
    clear(h); 

}

void footer()
{
    printf("\n");
    printf("---------------------------------------------------------------\n");
}


int main() {
    
    sinewave ( );
    banner();
    run_tests();
    footer();
    getchar();
}