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
    void reorderList(ListNode* head) {

        if(head==NULL or head->next==NULL) return ;

        ListNode* slow=head;

        ListNode* fast=head->next;

        while(fast->next)
        {
            slow=slow->next;

            fast=fast->next;

            if(fast->next)
            {
                fast=fast->next;
            }
        }

        // code to reverse second half of linked list

        ListNode* curr=slow->next;

        slow->next=NULL;

        ListNode* prev=NULL;

        while(curr)
        {
            ListNode* temp=curr->next;

            curr->next=prev;

            prev=curr;

            curr=temp;


        }

        // merging of both list 

        ListNode* l1=head;

        ListNode* l2=prev;

        while(l1 && l2)
        {
            ListNode* temp1=l1->next;

            ListNode* temp2=l2->next;

            l1->next=l2;

            l2->next=temp1;

            l1=temp1;

            l2=temp2;


        }

        return ;
        
    }
};