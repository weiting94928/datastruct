#include <stdio.h>
#define int long long

int tower[300000];
int top=0;

void swap(int*a,int*b){int t=*a;*a=*b;*b=t;}

void switchup(int id){
    while(id>0){
        int pr=(id-1)/2;
        if(tower[pr]<tower[id]){
            swap(&tower[pr],&tower[id]);
            id=pr;
        }else break;
    }
}

void switchdown(int id){
    while(1){
        int c1=id*2+1;
        if(c1>=top) break;
        int c2=c1+1,chi=c1;
        if(c2<top && tower[c2]>tower[c1]) chi=c2;
        if(tower[chi]>tower[id]){
            swap(&tower[chi],&tower[id]);
            id=chi;
        }else break;
    }
}

void push(int x){
    tower[top]=x;
    switchup(top);
    top++;
}

int popmax(){
    int v=tower[0];
    top--;
    if(top>0){
        tower[0]=tower[top];
        switchdown(0);
    }
    return v;
}

signed main(){
    int n;
    scanf("%lld",&n);
    for(int i=0;i<n;i++){
        int type;
        scanf("%lld",&type);
        if(type==0){
            int x;
            scanf("%lld",&x);
            push(x);
        }
        if(type==1){
            if(top>=2){
                int a=popmax();
                int b=popmax();
                push(a-b);
            }
        }
        if(type==2){
            int id,del;
            scanf("%lld %lld",&id,&del);
            tower[id]+=del;
            if(del>0) switchup(id);
            else if(del<0) switchdown(id);
        }
    }
    for(int i=0;i<top;i++){
        printf("%lld ",tower[i]);
    }
    return 0;
}
