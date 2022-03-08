#include<iostream>
#include<cstdlib>
using namespace std;

class node{
public:
    int info;

    node *prev,*next;
};

node *head=NULL, *tail=NULL;

void CreateNode(int item){
    node *ptr;
    ptr=new node();
    ptr->info=item;
    ptr->prev=NULL;
    ptr->next=NULL;

    if(head==NULL){
        head=ptr;
        tail=ptr;
    }
    else{
        tail->next=ptr;
        ptr->prev=tail;
        tail=ptr;
    }
}

void ForwardTraverse(){
    node *i=head;

    while(1){
        if(i==NULL) break;
        cout<<i->info<<" ";
        i=i->next;
    }
    cout<<endl;
}

void BackwardTraverse(){
    node *i=tail;

    while(1){
        if(i==NULL) break;
        cout<<i->info<<" ";
        i=i->prev;
    }
    cout<<endl;
}

void FirstDelete(){
    head=head->next;
    head->prev=NULL;
}

void LastDelete(){
    tail=tail->prev;
    tail->next=NULL;
}

void GivenDelete(int item){
    node *ptr=head;
    while(1){
        if(ptr->info==item){
            if(ptr==head) {
                FirstDelete();
                break;
            }
            else if(ptr==tail) {
                LastDelete();
                break;
            }
            else{
                ptr->prev->next=ptr->next;
                ptr->next->prev=ptr->prev;
                break;
            }
        }
        else if(ptr->next==NULL) {
            cout<<"Item Not Found!"<<endl;
            break;
        }
        else ptr=ptr->next;
    }
}

void AfterDelete(int item){
    node *ptr=head;

    while(1){
        if(ptr->info==item){
            if(ptr->next==tail){
                LastDelete();
                break;
            }
            else if(ptr==tail) break;
            else if(ptr->next!=NULL){
                ptr->next=ptr->next->next;
                ptr->next->prev=ptr;
                break;
            }
        }
        else if(ptr->next==NULL){
            cout<<"Item not found"<<endl;
            break;
        }
        else ptr=ptr->next;
    }
}

void BeforeDelete(int item){
    node *ptr=head;

    while(1){
        if(ptr->info==item){
            if(ptr==head) break;
            else if(ptr->prev==head){
                FirstDelete();
                break;
            }
            else{
                ptr->prev=ptr->prev->prev;
                ptr->prev->next=ptr;
                break;
            }
        }
        else if(ptr==tail){
            cout<<"Item not found!"<<endl;
            break;
        }
        else ptr=ptr->next;
    }
}

int main(){
    int n,num,temp;
    cout<<"Please enter the size of list: ";
    cin>>n;

    for(int i=0;i<n;i++){
        temp=rand()%50;
        CreateNode(temp);
    }

    while(1){
        cout<<"1 - Forward Traverse\n2 - Backward Traverse\n3 - First Delete\n4 - Last delete\n5 - Given item delete\n6 - Before delete\n7 - After delete\n0 - exit"<<endl;
        cin>>n;

        if(n==0) break;
        else if(n==1) ForwardTraverse();
        else if(n==2) BackwardTraverse();
        else if(n==3) FirstDelete();
        else if(n==4) LastDelete();
        else if(n==5){
            cout<<"Please enter the number: ";
            cin>>num;
            GivenDelete(num);
        }
        else if(n==6){
            cout<<"Please enter the Before item: ";
            cin>>num;
            BeforeDelete(num);
        }
        else if(n==7){
            cout<<"Please enter the After item: ";
            cin>>num;
            AfterDelete(num);
        }
    }

    return 0;
}
