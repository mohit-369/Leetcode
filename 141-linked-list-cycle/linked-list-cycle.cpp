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
    bool hasCycle(ListNode *head) {

        ListNode* slow=head;

        ListNode* fast=head;

        if(head==NULL) return 0;

        while(fast->next)
        {

            fast=fast->next;

            if(fast->next)
            {
                fast=fast->next;
            }

            if(slow==fast) return 1;


            slow=slow->next;

            
        }

        return 0;
        
    }
};