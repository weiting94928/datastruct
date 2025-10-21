#include <stdio.h>
#include <string.h>

#define int long long
int tree[3100];
int top=0;

int max(int a,int b){
    if(a>=b) return a;
    else return b;
}

void insert(int x){
    if(tree[0]==0){
        tree[0]=x;
        return;
    }
    int i=0;
    while(1){
        if(x==tree[i]) return;
        if(x>=tree[i]){
            int r=(i+1)*2;
            if(r>=3100) return;
            if(tree[r]==0){
                tree[r]=x;
                top=max(top,r+1);
                break;
            }else{
                i=r;
            }
        }else{
            int l=(i+1)*2-1;
            if(l>=3100) return;
            if(tree[l]==0){
                tree[l]=x;
                top=max(top,l+1);
                break;
            }else{
                i=l;
            }
        }
    }
}

int find(int x){
    if(tree[0]==0) return -1;
    int i=0;
    while(1){
        if(i>=3100) return -1;
        if(x==tree[i]) return i;
        else if(x>tree[i]){
            int r=(i+1)*2;
            if(r>=3100 || tree[r]==0) return -1;
            i=r;
        }else{
            int l=(i+1)*2-1;
            if(l>=3100 || tree[l]==0) return -1;
            i=l;
        }
    }
}

int findmin(int i){
    while(1){
        int l=i*2+1;
        if(l>=3100 || tree[l]==0) return i;
        i=l;
    }
}

void delete(int i){
    if(i<0 || i>=3100 || tree[i]==0) return;
    int l=i*2+1, r=i*2+2;

    if((l>=3100||tree[l]==0) && (r>=3100||tree[r]==0)){
        tree[i]=0;
        return;
    }
    else if((l>=3100||tree[l]==0) ^ (r>=3100||tree[r]==0) || (tree[l]==0) ^ (tree[r]==0)){
        int child;
        if(r<3100 && tree[r]!=0 && (l>=3100 || tree[l]==0)) child=r;
        else child=l;
        tree[i]=tree[child];
        delete(child);
    }
    else{
        int sec=findmin(r);
        tree[i]=tree[sec];
        delete(sec);
    }
}

signed main(){
    while(1){
        char s[16];
        if(scanf("%s",s)!=1) break;
        if(strcmp(s,"insert")==0){
            int x; scanf("%lld",&x);
            insert(x);
        }else if(strcmp(s,"delete")==0){
            int x; scanf("%lld",&x);
            int i=find(x);
            if(i>=0) delete(i);
        }else if(strcmp(s,"exit")==0){
            break;
        }
    }
    for(int i=0;i<top;i++){
        if(tree[i]!=0) printf("%lld ",tree[i]);
    }
    printf("\n");
    return 0;
}
