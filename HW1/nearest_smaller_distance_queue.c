#include <stdio.h>
#define MAXM 200000

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


int n,A[MAXM],dist[MAXM],ans[MAXM],asize=0;

int main(){
    
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    Stack s;
    initstack(&s);
    for(int i=0;i<n;i++){
        while(!isempty(&s)&&A[peek(&s)]>=A[i]){
            pop(&s);
        }
        if(!isempty(&s)){
            dist[i]=i-peek(&s);
            ans[asize++]=dist[i];
        }else{
            dist[i]=-1;
        }
        push(&s,i);
    }
    for(int i=0;i<n;i++){
        printf("%d ",dist[i]);
    }
    printf("\n");
    if(asize==0){
        printf("EMPTY\n");
    }else{
        for(int i=0;i<asize;i++){
            printf("%d ",ans[i]);
        }
        printf("\n");
    }
    return 0;
}
