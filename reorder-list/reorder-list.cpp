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
    ListNode* reverse(ListNode* head)
    {
         if(head == NULL || head->next==NULL){
            return head;
        }
        ListNode *curr=head,*prev=NULL,*nxtptr=head;
        while(curr)
        {
            nxtptr=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxtptr;
        }
       
      return prev;  
    }
    ListNode* midelement(ListNode* head)
    {
        ListNode* slow=head,*fast=head;
       
        while(slow && fast && fast->next && fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;
        return mid; 
    }
    void mergeList(ListNode* p, ListNode* q){
        ListNode* tmp;
        while(q){
            tmp = p->next;  // store address of next
            p->next = q;    // link to 2nd list
            q = q->next;    // increase 2nd list pointer
            p = p->next;    
            p->next = tmp;  // link to 1st list
            p = p->next;    // increase 1st list pointer
        }
    }
    void reorderList(ListNode* head) {
        if(!head)
            return;
        ListNode* p=head;
         ListNode *q=midelement(head);
        q=reverse(q);
        mergeList(p,q);
        
    }
};