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
        int cnt=0;
        while(curr)
        {
            cnt++;
            curr = curr->next;
        }

        if(cnt==n)
            return head->next;

        curr=head;
        int it = 1;
        while(curr && (it<(cnt-n)))
        {
            curr=curr->next;
            it++;
        }

        curr->next = curr->next->next;

        return head;
    }
};
