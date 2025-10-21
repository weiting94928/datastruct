#include <stdio.h>
#define MAXM 9000000

typedef struct{
    int data[MAXM];
    int top;   
} Stack;

void initstack(Stack* s){
    s->top=-1;
}

int isempty(Stack* s){
    return s->top==-1;
}

void push(Stack* s,int x){
    s->data[++(s->top)]=x;
}

int pop(Stack* s){
    return s->data[(s->top)--];
}

int peek(Stack* s){
    return s->data[s->top];
}



int main(){
    Stack l,r;
    initstack(&l);
    initstack(&r);
    char s[260];
    scanf("%s",s);
    for(int i=0;s[i];i++){
        push(&l,s[i]);
    }
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        char opr;
        scanf(" %c",&opr);
        if(opr=='L' && !isempty(&l)){
            push(&r,pop(&l));
        }
        if(opr=='R' && !isempty(&r)){
            push(&l,pop(&r));
        }
        if(opr=='D' && !isempty(&l)){
            pop(&l);
        }
        if(opr=='I'){
            char insert;
            scanf(" %c",&insert);
            push(&l,insert);
        }
    }
    for(int i=0;i<=l.top;i++){
        putchar(l.data[i]);
    }
    for(int i=r.top;i>=0;i--){
        putchar(r.data[i]);
    }
    putchar('\n');

    
    return 0;
}
