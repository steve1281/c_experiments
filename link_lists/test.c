#include <stdio.h>

#include "node.h"
#include "link_lists.h"
#include "test.h"
#include "defines.h"


// dump the contents of the chain left to right
void dumplist(link *n)
{
    link *top = findhead(n);
    
    while (top != 0){
        nodedump(top->data);
        top = top->right;    
    }
    printf("\n");
    
}

// reverse dump the contgents of the chain, right to left
void rdumplist(link *n)
{
    link *top = findtail(n);
    
    while (top != 0){
        nodedump(top->data);
        top = top->left;
    }
    printf("\n");
    
}



link *init(int *nc)
{
    link *h=0;
    
    
    h =  buildlink(buildnode((*nc)++,15));
    
    addright(h,BL((*nc)++,25));
    addright(h,BL((*nc)++,35));
    addright(h,BL((*nc)++,45));
    addright(h,BL((*nc)++,55));
    addright(h,BL((*nc)++,65));  

    printf("initial list:\n");
    dumplist(h);

    return h;
}
void test1(link *h, int *nc)
{
    printf("\n");
    printf("insertright 99 at tail:\n");
    insertright(findtail(h),BL((*nc)++,99));
    dumplist(h);

}

void test2(link *h, int *nc)
{
    printf("\n");
    printf("insertleft 98 at head:\n");
    insertleft(findhead(h),BL((*nc)++,98));
    dumplist(h);
}

void test3(link *h, int *nc)
{
    printf("\n");
    printf("insertleft 97 at head+2:\n");
    insertleft(right(right(findhead(h))), BL((*nc)++,97));
    dumplist(h);

}
void test4(link *h)
{
    printf("\n");
    printf("display backwards to check left links\n");
    rdumplist(h);  
}

