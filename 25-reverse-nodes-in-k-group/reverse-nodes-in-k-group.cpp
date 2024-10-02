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
int calLen(ListNode* head)
{
    int len = 0;

    while(head)
    {
        head = head -> next;

        len++;
    }

    return len;


}
ListNode* solve(ListNode* head,int k, int len)
{
    if(len < k) return head;

    ListNode* pre = NULL;

    ListNode* curr = head;

    ListNode* next = curr -> next;

    int count = k;

    while(count--)
    {
        curr -> next = pre;

        pre = curr;

        curr = next;

        if(next)
        {
            next = curr -> next;
        }
    }

    head -> next = solve(curr,k,len - k);

    return pre;

}
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        int len = calLen(head);

        if(len < k) return head;

        return solve(head,k,len);




        
        
    }
};