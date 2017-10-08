#include<stdio.h>
#include<stdlib.h>  // malloc
#include<string.h> // strcat

#define UNDERFLOW -1

// members 
// link, and the data it accesses.
typedef struct link link ;
typedef struct link {
    link * next;   
    int data;
} link;

link *head;
link *tail;

/*
    deq - remove the oldest member of the queue
*/
int deq()
{
    if (head == 0) return UNDERFLOW;   
    int retVal = 0;
    link * temp;
    
    if (head == tail) {
        retVal = head->data;
        free(head); // same memory as tail.
        head = tail =0; // empty
    } else {
        retVal = head->data;
        temp = head;
        head = head->next; // chasing the tail.
        free(temp);
    }
    return retVal;    
    
}
/*
    enq - add another item on the queue.
*/
void enq(int v)
{
    if (tail == 0) {
        tail = (link *)malloc(sizeof(link));
        tail->data = v;
        tail->next = 0;
        head = tail;
    } else {
        tail->next = (link *)malloc(sizeof(link));
        tail = tail->next;
        tail->data = v;
        tail->next = 0;
    }
}

/*
    initialize the queue. 
    (note: in this case, its pretty simple, dont need to do this, but still good form.)
*/
void init(){
    head =0;
    tail =0;
}

/*
    cleanup - deallocate the memory used by the queue.
*/
void cleanup()
{
    if (head == 0) return;
    link *t;
    do {
        t = head;
        head = head->next;
        free(t);
    } while (head !=0);
}

/*
    dunp - print the contents of the queue
*/
void dump()
{
    link *t = head;
    while (t !=0 )
    {
        printf("%d ", t->data);
        t=t->next;
    }
    printf("\n");
}

/*
    test1
*/
void test1(){
    printf(" add 10, 20, 30 in that order. deq in seperate printfs \n");
    enq(10);
    enq(20);
    enq(30);
    dump();
    
    printf("%d ", deq());
    printf("%d ", deq());
    printf("%d\n", deq());
    
}
/*
    test2
    note: this isn't much of a test; see inline comments.
*/
void test2(){
    printf(" add 10, 20, 30 in that order. deq in same printf\n");
    enq(10);
    enq(20);
    enq(30);
    dump();
    // note: checked the spec, the order the deq get executed is unspecified.
    // as a result, this test is not tht useful.
    printf("%d %d %d\n", deq(), deq(), deq());
    
}
/*
    banner 
*/
void banner()
{
    printf("\n"); 
    printf("---------------------------\n");
    printf("\n");
}

/*
    footer
*/
void footer()
{
    printf("\nPress Enter to continue.\n");
    getchar();
}

/*
    main 
*/
int main() {

// use a linked list to create a queue
    banner();
    init();
    test1();
    //test2();
    cleanup();
    footer();

}
