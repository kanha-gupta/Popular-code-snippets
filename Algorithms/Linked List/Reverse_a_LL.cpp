#include<stack>
class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
     stack<int> s;
     Node *temp=head;
     while(temp!=NULL){
         s.push(temp->data);
         temp=temp->next;
     }
     temp=head;
     while(temp!=NULL){
         temp->data=s.top();
         temp=temp->next;
         s.pop();
     }
     
     return head;
    }
