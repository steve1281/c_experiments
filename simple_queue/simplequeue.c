#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define QSIZE 100

int *queue;
int top;

void enq(int v)
{
    
    if (top > QSIZE) {
        // OVERFLOW, cannot queue.
        // log an error
        return;
    }
    queue[top] = v;
    top++;
}

int dq()
{
    if (top == -1) {
        // UNDERFLOW,
        // handle error.
        return -1;
    }
    int temp;
    temp = queue[0];
    for (int i=0;i<top;i++) {
        queue[i]=queue[i+1];
    }
    top --;
    return temp;
}

void init()
{
    queue = (int *)malloc(sizeof(int) * QSIZE);
    top = 0;
}

void cleanup()
{
    free (queue);
}

void dump()
{
    char *s = (char *)malloc(sizeof(char) * QSIZE * 4); // "99,"
    s[0]=0;
    char temp[5]; temp[0]=0;
    for (int i=0;i<top;i++) {
        sprintf(temp, "%d,", queue[i]);
        strcat(s,temp);
    }
    s[strlen(s)-1]=0;
    printf("%s\n",s );
    free(s);
}

void banner()
{
    printf("\n+-------------------------------------+\n");
    printf("|                                     |\n");
    printf("| Simple queue                        |\n");
    printf("|                                     |\n");
    printf("+-------------------------------------+\n\n");
}

void footer()
{
    printf("\n");
    getchar();
}
void test1()
{
    enq(1);
    enq(2);
    enq(3);
    dump();
    printf("%d %d %d\n", dq(), dq(), dq());
}

int main() {
// implement a queue
// first in first out

    banner();
    init();
    
    test1();
    footer();
    cleanup();
}
