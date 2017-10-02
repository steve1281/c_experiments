typedef struct node node;
typedef struct link link;

// node that link points to; could contain anything.
typedef struct node {
    int x;    
    int y;
} node;

node *buildnode(int x,int y) ;
link *buildlink(node *n);
void nodedump(node *n);