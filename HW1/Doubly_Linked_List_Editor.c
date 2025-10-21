#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXM 9000000

typedef struct node{
    int data;
    int id;
    struct node *r;
    struct node *l;
} node;

node* newnode(int x,int i){
    node* n=(node*)malloc(sizeof(node));
    n->data=x;
    n->id=i;
    n->l=NULL;
    n->r=NULL;
    return n;
}

void inserthead(node** head,node** tail,node* n){
    if(*head==NULL){//空的
        *head=*tail=n;
    }
    else{
        n->l=(*head);
        (*head)->r=n;
        *head=n;
    }
}

void inserttail(node** head,node** tail,node* n){
    if(*tail==NULL){//空的
        *head=*tail=n;
    }
    else{
        n->r=(*tail);
        (*tail)->l=n;
        *tail=n;
    }
}

void detach(node** head,node** tail,node* x){
    if(x->r==NULL){
        *head=x->l;
    }
    else{
        x->r->l=x->l;
    }
    if(x->l==NULL){
        *tail=x->r;
    }
    else{
        x->l->r=x->r;
    }
    x->l=NULL;
    x->r=NULL;

}

void deletenode(node** head,node** tail,node* x){
    if(x==NULL) return;
    detach(head,tail,x);

    free(x);

}

void printforward(node *head){
    for(node *cur=head;cur!=NULL;cur=cur->l){
        printf("%d ",cur->data);
    }
    printf("\n");
}
void printbackward(node* tail){
    int cnt=0;
    for(node* cur=tail;cur!=NULL;cur=cur->r){
        printf("%d ",cur->data);
    }
    printf("\n");
}

node* search(node* head,int id){
    for(node *cur=head;cur!=NULL;cur=cur->l){
        if(cur->id==id){
            return cur;
        }
    }
    return NULL;
}

void insertleft(node** head,node** tail,node* n,int id){
    node* target=search(*head,id);
    if(target->l == NULL){
        inserttail(head,tail,n);
        return;
    }
    target->l->r=n;
    n->l=target->l;
    n->r=target;
    target->l=n;
}
void insertright(node** head,node** tail,node* n,int id){
    node* target=search(*head,id);
    if(target->r == NULL){
        inserthead(head,tail,n);
        return;
    }
    target->r->l=n;
    n->r=target->r;
    n->l=target;
    target->r=n;
}

int main(){
    int curid=1;
    node *head=NULL;
    node *tail=NULL;
    int n,q;
    scanf("%d %d",&n,&q);
    for(int i=0;i<n;i++){
        int temp;
        scanf(" %d",&temp);
        node* tempnode=newnode(temp,curid++);
        inserttail(&head,&tail,tempnode);
    }
    for(int i=0;i<q;i++){
        char opr[5];
        scanf("%s",opr);
        if(strcmp(opr,"H")==0){
            int x;
            node* new;
            scanf("%d",&x);
            new=newnode(x,curid++);
            inserthead(&head,&tail,new);
        }
        if(strcmp(opr,"T")==0){
            int x;
            node* new;
            scanf("%d",&x);
            new=newnode(x,curid++);
            inserttail(&head,&tail,new);
        }
        if(strcmp(opr,"A")==0){
            int x,k;
            node* new;
            scanf(" %d %d",&k,&x);
            new=newnode(x,curid++);
            insertleft(&head,&tail,new,k);
        }
        if(strcmp(opr,"B")==0){
            int x,k;
            node* new;
            scanf(" %d %d",&k,&x);
            new=newnode(x,curid++);
            insertright(&head,&tail,new,k);
        }
        if(strcmp(opr,"D")==0){
            int k;
            scanf(" %d",&k);
            deletenode(&head,&tail,search(head,k));
        }
        if(strcmp(opr,"MH")==0){
            int k;
            scanf(" %d",&k);
            node* x=search(head,k);
            detach(&head,&tail,x);
            inserthead(&head,&tail,x);
        }
        if(strcmp(opr,"MT")==0){
            int k;
            scanf(" %d",&k);
            node* x=search(head,k);
            detach(&head,&tail,x);
            inserttail(&head,&tail,x);
        }

    }

    if(head==NULL){
        printf("EMPTY\n");
        printf("EMPTY\n");
    }
    else{
        printforward(head);
        printbackward(tail);
    }



    
    return 0;
}
