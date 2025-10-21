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
            if((i+1)*2>=3100) return;
            if(tree[(i+1)*2]==0){    
                tree[(i+1)*2]=x;
                top=max(top,(i+1)*2+1);
                break;
            }
            else{
                i=(i+1)*2;
            }
        }
        else if(x<tree[i]){
            if((i+1)*2-1>=3100) return;
            if(tree[(i+1)*2-1]==0){    
                tree[(i+1)*2-1]=x;
                top=max(top,(i+1)*2);
                break;
            }
            else{
                i=(i+1)*2-1;
            }        
        }
    }
}

int find(int x){
    if(tree[0]==0){
        return -1;
    }
    int i=0;
    while(1){
        if(i>=3100) return -1;
        if(x==tree[i]){
            return i;
        }
        else if(x>tree[i]){
            if(tree[(i+1)*2]==0){    
                return -1;
            }
            else{
                i=(i+1)*2;
            }
        }
        else if(x<tree[i]){
            if(tree[(i+1)*2-1]==0){    
                return -1;
            }
            else{
                i=(i+1)*2-1;
            }    
        }
    }
}


int findmin(int i){
    while(1){
        if(2*i+1>3000) return i;
        if(tree[i*2+1]==0){
            return i;
            break;
        }
        else{
            i=i*2+1;
        }
    }
}

void delete(int i){
    if(i<0 || i>=3100 || tree[i]==0) return;
    int l=i*2+1,r=i*2+2;

    if(tree[i*2+1]==0 && tree[i*2+2]==0){
        tree[i]=0;
        return;
    }
    else if(tree[i*2+1]!=0 && tree[i*2+2]!=0){
        int sec=findmin(i*2+2);
        tree[i]=tree[sec];
        delete(sec);
        return;
    }
    else{
        if(tree[i*2+1]!=0){
            tree[i]=tree[i*2+1];
            delete(i*2+1);
            return;
        }
        if(tree[i*2+2]!=0){
            tree[i]=tree[i*2+2];
            delete(i*2+2);
            return;
        }
    }
}

signed main(){
    while(1){
        char s[10];
        scanf("%s",s);
        if(strcmp(s,"insert")==0){
            int x;
            scanf("%lld",&x);
            insert(x);
        }
        else if(strcmp(s,"delete")==0){
            int x;
            scanf("%lld",&x);
            int i=find(x);
            if(i<0) continue;
            else delete(i);
        }
        else if(strcmp(s,"exit")==0){
            break;
        }
    }
    for(int i=0;i<3000;i++){
        if(tree[i]!=0)printf("%lld ",tree[i]);
    }
    printf("\n");
    return 0;
}
