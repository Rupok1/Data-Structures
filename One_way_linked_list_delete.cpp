//19.02.2020

#include<iostream>
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

void frstdlt(){
    node *ptr;
    ptr=head->link;
    head=ptr;

    traverse();
}

void lstdlt(){
    node *ptr;
    ptr=head;

    while(1){
        if(ptr->link == NULL){
            head=NULL;
            break;
        }
        else{
            temp=ptr->link;
            if(temp->link==NULL){
                ptr->link=NULL;
                break;
            }
            ptr=ptr->link;
        }
    }
    traverse();
}

void gvndlt(int item){
    node *ptr;
    ptr=head;

    while(1){
        if(ptr->info == item){
            if(ptr==head) frstdlt();
            else if(ptr->link == NULL ) lstdlt();
            else{
                temp->link=ptr->link;
                break;
            }
        }
        else{
            temp=ptr;
            ptr=ptr->link;
            if(ptr==NULL) {
                cout<<"No such item"<<endl;
                break;
            }
        }
    }
    traverse();
}

void aftrdlt(int item){
    node *ptr;
    ptr=head;
    temp=ptr->link;

    while(1){
        if(ptr->info==item){
            if(temp==NULL) {
                ptr->link=NULL;
                break;
            }
            else{
                ptr->link=temp->link;
                break;
            }
        }
        else{
            ptr=ptr->link;
            temp=ptr->link;
        }
    }
    traverse();
}

int main(){
    int n,in,var,item;
    cout<<"Please enter the size of List:\n";
    cin>>n;

    for(int i=0;i<n;i++){
        var=rand()%50;
        CreateNode(var);
    }

    while(1){
        cout<<"Please enter:\n1 -  Traverse\n2 - 1st item delete\n3 - Last item delete\n4 - Given item delete\n5 - After given item delete\n0 - exit\n";
        cin>>in;

        if(in==0) break;

        else if(in==1) traverse();
        else if(in==2) frstdlt();
        else if(in==3) lstdlt();
        else if(in==4){
            cout<<"Please enter the item: "<<endl;
            cin>>item;
            gvndlt(item);
        }
        else if(in==5) {
            cout<<"Please enter the after item: "<<endl;
            cin>>item;
            aftrdlt(item);
        }
    }
    return 0;
}
