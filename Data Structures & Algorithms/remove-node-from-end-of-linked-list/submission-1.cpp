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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        while(n--)
        {
            curr=curr->next;
        }

        if(curr==nullptr)
            return head->next;

        ListNode* node = new ListNode();
        node->next = head;

        while(node && curr)
        {
            node = node->next;
            curr = curr->next;
        }

        node->next = node->next->next;
        return head;
    }
};
