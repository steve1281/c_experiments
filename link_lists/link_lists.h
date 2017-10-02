

// protoypes (aka forward declarations)

typedef struct link link;

// generic doubly linked stuct
typedef struct link {
    link *right;
    link *left;
    node *data;
    
} link;

void rdumplist(link *n);
void dumplist(link *n);
link *findtail(link *src);
link *findhead(link *src);
link *addleft(link *h, link *n);
link *addright(link *h, link *n);
void insertleft(link *a, link *n);
void insertright(link *a, link *n);
void clear(link *n);
link *right(link *h);
link *left(link *h);


