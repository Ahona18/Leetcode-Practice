/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL ||head->next==NULL)
            return NULL;
        ListNode *slow=head,*fast=head,*tmp=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast)
            {
                while(slow!=tmp)
                {
                    slow=slow->next;
                    tmp=tmp->next;
                }
                return tmp;
            }
            // tmp=tmp->next;
        }
        return NULL;
    }
    
};