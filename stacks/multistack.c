#include<stdio.h>
#include<stdlib.h>


#define OVERFLOW -1
#define UNDERFLOW -1


int STACKSIZE;
int STACKS;
int HEAPSIZE;
int *stack;
int *bottom;
int *top;
    
/*
    init - allocate space, set initial values, for stacks.
*/
void init(int stacks, int stacksize)
{
    
    int STACKSIZE = stacksize;
    int STACKS= stacks;
    int HEAPSIZE = (STACKSIZE*STACKS);

    // allocate
    stack = (int *)malloc(sizeof(int) * HEAPSIZE);
    bottom = (int *)malloc(sizeof(int) * STACKS);  
    top = (int *)malloc(sizeof(int) * STACKS);   
    
    // initiate
    for (int i=0;i<HEAPSIZE;i++) stack[i]=0;
    for (int i=0;i<STACKS;i++) bottom[i] = (STACKSIZE/STACKS)*i;
    for (int i=0;i<STACKS;i++) top[i] = bottom[i];
}

/*
   cleanup - free the allocated space.
   (should be the last thing you call)
*/   
void cleanup()
{
    free(stack);
    free(bottom);
    free(top);
}

/*
    pop - remove an item from stack n.
*/    
int pop(int n) 
{
    if (bottom[n] == top[n]) {
        // EMPTY
        return UNDERFLOW;
    }
    top[n]--;
    return stack[top[n] +1];
}

/*
    push - add a value to stack n.
*/    
int push(int n, int v)
{
    if (n==STACKS && top[n]==(HEAPSIZE-1)) {
        // OVERFLOW
        return OVERFLOW;
    }    
    if (top[n]+1 == bottom[n+1]) {
        // OVERFLOW
        return OVERFLOW;
    }
    top[n] ++;
    stack[top[n]] = v;
}

/*
   test 1
*/
void test1() 
{
    push(0,5);
    push(1,6);
    push(2,7);

    push(0,8);
    push(1,9);
    push(2,10);

    printf("%d %d %d\n", pop(0), pop(1), pop(2));
    printf("%d %d %d\n", pop(0), pop(1), pop(2));
    printf("%d %d %d\n", pop(0), pop(1), pop(2));
}


/*
    main
*/    
int main() 
{
    // implememnt a 3 stacks in a single array
    // a stack is First In, First Out (FIFO)
    // methods are push, pop, init
    // errors are 
    //    OVERFLOW - stack is full
    //    EMPTY - stack can't pop

    init(3, 100);
    test1();  
    cleanup();
}
