#include<stdio.h>
#include<stdlib.h>

#define DEBUG (1==0)

typedef struct node node;
typedef struct node {
    node *nodes[100];
    int nodecnt;
    int id;
} node;

int idctr;
node *root;
int visited[1000];
int visitcnt;

node * makenode()
{
    node *n = (node *)malloc(sizeof(node));
    n->id = idctr++;
    n->nodecnt=0;
    return n;
}

void addnode(node *n, node *v)
{
    n->nodes[n->nodecnt++] = v;
}

int does_path(node *n1, node *n2)
{
    // path from n1 to n2
    if (n1==0) return 0;
    if (n2==0) return 0;
    if (n1 == n2) return 1; // found it.
    
    for (int i=0;i<visitcnt;i++) { // avoid cycles
        if (visited[i] == n2->id) {
            return 0;
        }
    }
    visited[visitcnt++] = n2->id;
    
    int flag =0; // check leaf nodes.
    for (int i=0;i<n2->nodecnt;i++) {
        flag = flag || does_path(n1, n2->nodes[i]);
        if (flag==1) return 1;
    }
    return flag;
        
}

void dump(node *n, int depth)
{
    
    // check if null leaf.
    if (n == 0) return ;
    
    // check if we have visited before. 
    for (int i=0;i<visitcnt;i++) {
        if (visited[i] == n->id) {
            printf("\n");
            for (int j=0;j<depth;j++) printf("\t");
            printf("(%d)",n->id);
            return;
        }
    }
    visited[visitcnt++] = n->id;
    
    // tab in based on depth from root.
    printf("\n");
    for (int i=0;i<depth;i++) printf("\t");
    
    // display leaf info (id will do for now)
    printf("[%d]", n->id, depth);
    
    // for each leaf, dump it recursively.
    for (int i=0;i<n->nodecnt;i++) {
        dump(n->nodes[i], depth+1);
    }
 
}

void init_visited()
{
    for (int i=0;i<1000;i++) visited[i] = 0;
    visitcnt = 0;    
}
void init()
{
    root =0;
    idctr =10;  // any positive value greater than 0 is fine.
    init_visited();
}

void purge(node *n, int depth)
{
    // check if null leaf.
    if (n == 0) return ;
    
    // check if we have visited before. 
    for (int i=0;i<visitcnt;i++) {
        if (visited[i] == n->id) {
            return;
        }
    }
    visited[visitcnt++] = n->id;

    // for each leaf, dump it recursively.
    for (int i=0;i<n->nodecnt;i++) {
        if (n->nodes[i] != 0 ) {    // check if we deleted it befrore
            purge(n->nodes[i], depth+1);
        }
    } 
    
    free(n);
    n=0;
}

void cleanup()
{
    // visit each leaf, and eliminate it
    init_visited();
    purge(root, 0);
    
    if (DEBUG) {
        // ---- Check if all nodes got deleted.
        printf("\n\nCheck if ids of all added nodes in the deletion list:\n\t");
        for (int i=0;i<visitcnt;i++) {
            printf("%d ", visited[i]);
        }
        printf("\n");
    }
    
    
}
void test1()
{
    printf("\n\ntest 1-------------------------------\n\n");
    
    root = makenode();
    node *leaf1 = makenode();
    node *leaf2 = makenode();
    node *leaf3 = makenode();
    addnode(root, leaf1 );
    addnode(root, leaf2 );
    addnode(root, leaf3 );
    
    node *leaf4 = makenode();
    addnode(leaf2, leaf4);
    addnode(leaf4, root);   // create a cyclic path.
    
    node *leaf5 = makenode();
    
    addnode(leaf1, leaf5);
    addnode(leaf2, leaf5);
    addnode(leaf3, leaf5);
    addnode(leaf4, leaf5);
    
    dump(root, 0);
    
}

void evaluate_path(node *n1, node *n2)
{
    init_visited();
    
    int path1 = does_path(n1, n2);
    int path2 = does_path(n2, n1);

    if (path1 ==1 && path2==1) {
        printf("A circuit exists between: %d and %d\n", n2->id, n1->id);
    } else {
        printf("No circuit exists between: %d and %d\n", n2->id, n1->id);
    }
}

void test2()
{
    printf("\n\ntest 2-------------------------------\n\n");
    
    
    root = makenode();
    node *leaf1 = makenode();
    node *leaf2 = makenode();
    node *leaf3 = makenode();
    addnode(root, leaf1 );
    addnode(root, leaf2 );
    addnode(root, leaf3 );
    
    node *leaf4 = makenode();
    addnode(leaf2, leaf4);
    addnode(leaf4, root);   // create a cyclic path.
    
    node *leaf5 = makenode();
    
    addnode(leaf1, leaf5);
    addnode(leaf2, leaf5);
    addnode(leaf3, leaf5);
    addnode(leaf4, leaf5);
    

    evaluate_path(root, leaf4);
    evaluate_path(root, leaf5);
    evaluate_path(root, leaf2);
    
    init_visited();
    dump(leaf2, 0); // you can start on any node with a path to root.
    
}
void header()
{
    printf("");
}
void footer()
{
    printf("\nPress Enter to continue.");
    getchar();
}

int main() {
    // route between nodes (on a directed graph)
    // need a simple data structure for this
    // and a way tp track visits
    
    header();
    
    if (DEBUG) {
        init();
        test1(); // check if the datastructure is ok
        cleanup();
    }
    
    init();
    test2(); // look for some cycles in the graph
    cleanup();

    footer();
}
