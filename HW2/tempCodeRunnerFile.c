#include <stdio.h>

#define int long long
#define d lld
int tower[300000];
int top=0;


void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
void switchup(int id){
    while(id>0){
        int pr=(id-1)/2;
        if(tower[pr]<tower[id]){
            swap(&tower[pr],&tower[id]);
        }
        else break;
        id=pr;
    }
}
void push(int x){
    tower[top]=x;
    switchup(top);
    top++;
}
void switchdown(int id){
    while(id<top){
        int c1=(id)*2+1;
        int c2=(id)*2+2;
        int chi;
        if(tower[c1]>=tower[c2]){
            chi=c1;
        }
        else{
            chi=c2;
        }
        if(chi>=top) break;
        if(tower[chi]>tower[id]){
            swap(&tower[chi],&tower[id]);
        }
        else break;
        id=chi;
    }
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
            int x;
            x=tower[0];
            top--;
            tower[0]=tower[top];
            switchdown(0);
            x-=tower[0];
            top--;
            tower[0]=tower[top];
            switchdown(0);
            push(x);
        }
        if(type==2){
            int id,del;
            scanf("%lld %lld",&id,&del);
            tower[id]+=del;
            if(del>0) switchup(id);
            else switchdown(id);
        }
            
    }
    for(int i=0;i<top;i++){
        printf("%lld ",tower[i]);
    }
    return 0;
}
