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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode*tmp=head;
        int noOfnodes=0;
        while(tmp)
        {
            tmp=tmp->next;
            noOfnodes++;
        }
               ListNode *dummy=new ListNode(0);
       dummy->next=head;
       ListNode *curr=head,*prev=dummy,*nxt=dummy;

        while(noOfnodes>=k)
        {
            curr=prev->next;
            nxt=curr->next;
            for(int i=1;i<k;i++)
            {
                curr->next=nxt->next;
                nxt->next=prev->next;
                prev->next=nxt;
                nxt=curr->next;
            }
            prev=curr;
            noOfnodes-=k;
        }
     return   dummy->next; 
        
    }
};