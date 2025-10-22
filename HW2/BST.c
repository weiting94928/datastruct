#include <stdio.h>
#include <string.h>

#define int long long

typedef struct node{
    int v;
    struct leaf* l;
    struct leaf* r;
} node;



int max(int a,int b){
    if(a>=b) return a;
    else return b;
}

node *newnode(int x){
    node *n=(node*)malloc(sizeof(node));
    n->v=x;
    n->l=NULL;
    n->r=NULL;
    return n;
}

node *insert(node *root,int x){
    if(root==NULL){
        return newnode(x);
    }
    else if(x>root->v){
        insert(root->r,x);
    }
    else if(x<root->v){
        insert(root->l,x);      
    }
    return root;
}


void deletenode(node **root,int x){
    if(*root==NULL) return;
    if((*root)->v==x){
        if((*root)->r==NULL && (*root)->l==NULL){
            node* temp=*root;
            *root=NULL;
            free(temp);
        }
        else if((*root)->r!=NULL && (*root)->l!=NULL){
            node **i=&(*root)->r;
            for(;(*i)->l!=NULL;i=&(*i)->l){}
            (*root)->v=(*i)->v;
            deletenode(&(*root)->r,(*i)->v);
        }   
        else{
            node* temp=*root;
            if((*root)->r!=NULL){
                (*root)=(*root)->r;
            }
            if((*root)->l!=NULL){
                (*root)=(*root)->l;
            }
            free(temp);
        }
    }
    else if(x>(*root)->v){
        deletenode(&(*root)->r,x);
    }
    else if(x<(*root)->v){
        deletenode(&(*root)->l,x);      
    }
}

void output(node* root){
    
}


signed main(){
    node* root=NULL;
    while(1){
        char s[10];
        scanf("%s",s);
        if(strcmp(s,"insert")==0){
            int x;
            scanf("%lld",&x);
            insert(root,x);
        }
        else if(strcmp(s,"delete")==0){
            int x;
            scanf("%lld",&x);
            deletenode(&root,x);
        }
        else if(strcmp(s,"exit")==0){
            break;
        }
    }

    return 0;
}
