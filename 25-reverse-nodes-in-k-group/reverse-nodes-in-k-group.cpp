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
        
        if (!head) return head;

        // Step 1: Check if at least k nodes remain
        ListNode* check = head;
        for (int i = 0; i < k; i++) {
            if (!check) return head;   // < k nodes left, return as is
            check = check->next;
        }

        // Step 2: Reverse exactly k nodes
        ListNode *prev = NULL, *curr = head, *next = NULL;
        int count = 0;
        while (count < k && curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // Step 3: Recursively process remaining list
        head->next = reverseKGroup(curr, k);

        // 'prev' is new head of this block
        return prev;
        
    }
};