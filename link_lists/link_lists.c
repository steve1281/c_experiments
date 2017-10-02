#include<stdio.h>
#include<stdlib.h>


#include "node.h"
#include "link_lists.h"
#include "defines.h"

// build a link
link *buildlink(node *n)
{
    link *bl;
    bl = (link *)malloc(sizeof(link));
    bl->data = n;
    bl->right = 0;
    bl->left =0;
    
    return bl;
}


// clear all links and their nodes on a chain (free the malloc'd memory)
void clear(link *n)
{
    
    link *top = findhead(n);
    link *m;

    while (top->right != 0){
        m = top;
        top = top->right;
        free(m->data); // free the node
        free(m); // free myself
    }

}

// insert a link to the left of link a
void insertleft(link *a, link *n)
{
    if (a->left == 0) 
    {
        a->left = n;
        n->right= a;
    } else {
        link *b = a->left;
        n->right = a;   
        n->left = b;    
        a->left = n;
        b->right =n;    
    }
}

// insert a link to the right of link a
void insertright(link *a, link *n)
{
    
    if (a->right == 0) 
    {
        a->right = n;
        n->left = a;
        
    } else {
        link *b = a->right;
        n->right = b;   
        n->left = a;    
        a->right = n;
        b->left =n;    
    }

}

// add a link to the end of the chain.
link *addright(link *h, link *n)
{
    /* 
    travel to the far right of the list and append a link 
    */
    if (h ==0) return 0;
    
    link *src = findtail(h);

    src->right = n; 
    n->left = src;
    
    return src->right; // return the new link (technically, the tail*)
}

// add a link to the front of the chain.
link *addleft(link *h, link *n)
{
    /* 
    travel to the far left of the list and insert a link 
    */
    if (h ==0) return 0;
    
    link *src = findhead(h);
    link *temp;
    
    src->left = n;
    temp=src;
    src =n;
    src->right = temp; 
    
    return src->left; // return the new link (technically, the new head)
}


// find the head (left) of the chain.
link *findhead(link *src)
{
    link *t = src;
    while (t->left != 0) t=t->left;
    return t;
    
}

// find the tail (right) of the chain.
link *findtail(link *src)
{
    link *t = src;
    while (t->right != 0) t=t->right;
    return t;
    
}

link *left(link *h)
{
    if (h==0) return 0;

    return h->left;
}

link *right(link *h)
{
    if (h==0) return 0;
    return h->right;
}



