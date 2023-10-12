/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode* reverseList(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* next=NULL;
        while(curr)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        head=reverseList(head);
        int carry=0;
        ListNode* temp=head;
        while(temp)
        {
            int x=(temp->val*2)+carry;
            temp->val=x%10;
            carry=x/10;
            temp=temp->next;
        }
        head=reverseList(head);
        if(carry>0)
        {
            ListNode* dummy=new ListNode(carry);
            dummy->next=head;
            head=dummy;
        }
        return head;
    }
};

