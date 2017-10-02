#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "link_lists.h"


// dump the node data
void nodedump(node *n)
{
    printf("(%d,%d)",n->x,n->y);
}

// build a node
node *buildnode(int x, int y) 
{
    node *n = (node *)malloc(sizeof(node));
    n->x = x;
    n->y = y;
    return n;
}
