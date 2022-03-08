//02.03.2020

#include<iostream>
#include<cstdio>
#include<stdlib.h>
using namespace std;

class node{
public:
    int info;
    node *link;
};

node *head=NULL, *temp=NULL;

void CreateNode(int item){
    node *ptr;
    ptr = new node();
    ptr->info=item;
    ptr->link=NULL;

    if(head==NULL){
        head=ptr;
        temp=ptr;
    }
    else{
        temp->link=ptr;
        temp=ptr;
    }
}

void traverse(){
    node *ptr;
    ptr=head;

    while(ptr != NULL){
        cout<<ptr->info<<" ";
        ptr=ptr->link;
    }
    cout<<endl;
}

void FirstInsert(int t){
    node *ptr;
    ptr= new node();
    ptr->info=t;
    ptr->link=head;
    head=ptr;

    cout<<"List after first insert:";
    traverse();
}

void LastInsert(int t){
    node *ptr,*tm=head;
    ptr=new node();
    ptr->info=t;
    ptr->link=NULL;

    while(1){
        if(tm->link==NULL){
            tm->link=ptr;
            break;
        }
        else tm=tm->link;
    }
    cout<<"List after last insert:";
    traverse();
}

void BeforeInsert(int t,int num){
    node *ptr,*p1=head;
    node *p2=NULL;
    ptr=new node();
    ptr->info=num;
    ptr->link=NULL;

    while(1){
        if(p1==NULL){
            cout<<"Item not found!"<<endl;
            break;
        }
        else if(p1==head) FirstInsert(num);
        else if(p1->info==t){
            ptr->link=p2->link;
            p2->link=ptr;
            break;
        }
        else{
            p2=p1;
            p1=p1->link;
        }
    }
    cout<<"List after before insert:\n";
    traverse();
}

void AfterInsert(int t,int num){
    node *ptr,*tm;
    ptr=new node();
    ptr->info=num;
    ptr->link=NULL;
    tm=head;

    while(1){
        if(tm==NULL) {
            cout<<"Item not found!"<<endl;
            break;
        }
        else if(tm->info==t){
            ptr->link=tm->link;
            tm->link=ptr;
            break;
        }
        else tm=tm->link;
    }
    traverse();
}

int main(){
    int n,t,num;
    cout<<"Please enter the size of array: ";
    cin>>n;

    for(int i=0;i<n;i++){
        t=rand()%50;
        CreateNode(t);
    }

    while(1){

        cout<<"Please enter:\n1 - Fisrt insert\n2 - Last insert\n3 - Before insert\n4 - After insert\n5 - Traverse\n0 - exit"<<endl;
        cin>>n;

        if(n==0) break;
        else if(n==1) {
            cout<<"Please enter the element to be first inserted: ";
            cin>>t;
            FirstInsert(t);
        }
        else if(n==2) {
            cout<<"Please enter the element to be last inserted: ";
            cin>>t;
            LastInsert(t);
        }
        else if(n==3){
            cout<<"Please enter the element of before inset: ";
            cin>>t;
            cout<<"Plese enter the number: ";
            cin>>num;
            BeforeInsert(t,num);
        }
        else if(n==4){
            cout<<"Please enter the element of after insert: ";
            cin>>t;
            cout<<"Plese enter the number: ";
            cin>>num;
            AfterInsert(t,num);
        }
        else if(n==5) traverse();
    }
    return 0;
}
