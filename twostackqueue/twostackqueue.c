#include<stdio.h>

int stks[2][1000]; 
int tops[2];

int pop(int n)
{
    if (tops[n]==0) return -1;
    
    return stks[n][--tops[n]];
}

void push(int n, int v)
{
    stks[n][tops[n]++] = v;
}

void trans(int n1, int n2)
{
    int t;
    while ((t = pop(n1)) != -1) {
        if (t != -1)
            push(n2, t);
    }
    
}
int deq()
{
    int x= -1;
    trans(0,1);
    x = pop(1);
    trans(1,0);
    return x;
}

int enq(int v)
{
    push(0, v);
}

void init()
{
     
    for (int j=0;j<2;j++) {
        for (int i=0;i<1000;i++) { 
            stks[j][i] = 0;
        }
        tops[j]=0;
    }

}

void test1()
{
    enq(10);
    enq(20);
    enq(30);
    
    printf("%d ", deq());
    printf("%d ", deq());
    printf("%d\n", deq());
   
}
void banner()
{
    printf("\n");
}
void footer()
{
    printf("\nPress Enter to continue.\n");
    getchar();
}

int main() {
    // two stacks ; one queue
    // stack - first in, first out
    // queue - last in, first out
    
    init();
    banner();
    test1();
    footer();

}
