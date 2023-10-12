#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node*next;

    Node(int data){
     this->data=data;
     this->next=NULL;
    }
};

void insertAttale(Node*&head,Node*&tail,int d){
    if(tail==NULL){
        Node* newnode=new Node(d);
        tail=newnode;
        head=newnode;
    }
    else{
        Node* newnode=new Node(d);
        tail->next=newnode;
        tail=tail->next;
    }
}

bool floyedCycleDetect(Node* head){
    //if there linked list is empty then it will return false
    if(head==NULL)
    return false;
   
    //fast pointer :it will increment by 2
    Node* fast=head;
    //slow pointer: it will increment by 1
    Node* slow=head;

    while(fast!=NULL&&slow!=NULL){
        fast=fast->next;
         if(fast->next!=NULL){
            fast=fast->next;
         }
        slow=slow->next;

        if(slow==fast){
            //when slow is equal to fast then it means thera is a cycle in linked list
            return true;
        }

    }
 //else it will return false
  return false;

}

void print(Node* &head){
  Node*temp=head;

  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
  }
}

int main(){
   Node*head=NULL;
   Node*tail=NULL;

   insertAttale(head,tail,3);
   insertAttale(head,tail,6);
   insertAttale(head,tail,4);
   insertAttale(head,tail,2);
   insertAttale(head,tail,8);
   insertAttale(head,tail,9);

   print(head);
   
   //making cycle in singly linear LL
   tail->next=head->next;

   if(floyedCycleDetect(head)){
    cout<<"yes"<<endl;
   }
   else
   cout<<"no"<<endl;
   
   
}