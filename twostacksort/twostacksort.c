#include<stdio.h>

int stks[2][1000]; 
int tops[2];

int pop(int n)
{
    if (tops[n]==0) {
        return -1;
    }
    return stks[n][--tops[n]];
}

void push(int n, int v)
{
    stks[n][tops[n]++] = v;
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

void dump(int n)
{
    for (int i=0;i<tops[n];i++) {
        printf("%d ",stks[n][i]);
    }
    printf("\n");
}
void stacksort(int debug)
{
    int t;
    int c;
    while ( tops[0] != 0) {
        t = pop(0);
        while ((c = pop(1) ) != -1) {
            if (c < t) { // found it.
                push(1, c);
                push(1, t);
                t = -1; // mark as used.
                break;
            } else {
                push(0, c);
            }
        }
        if (t != -1) {
            push(1,t);
        }
        if (debug ==1) dump(1);
    }

}
void test1()
{
    push(0, 10);
    push(0, 30);
    push(0, 50);
    push(0, 20);
    push(0, 40);
    push(0, 60);
    
    dump(0);
    stacksort(1==1);
    dump(1);

}
void header()
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
    // stack 1 is sorted
    // stack 0 is not
    
    init();
    header();
    test1();
    footer();
    

}
