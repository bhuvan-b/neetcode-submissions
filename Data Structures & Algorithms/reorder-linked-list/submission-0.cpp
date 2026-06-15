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
        ListNode *itr=head, *itr2=head;
        ListNode *curr=head, *curr2=head;
        while(curr->next && curr2->next && curr2->next->next)
        {
            curr=curr->next;
            curr2=curr2->next->next;
        }

        itr2=curr->next;
        curr->next=nullptr;

        ListNode *prev=nullptr, *next;
        curr=itr2;

        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        itr2 = prev;

        curr = head;
        ListNode* ptr = itr2;

        while(curr && ptr)
        {
            ListNode* nxt = curr->next;
            curr->next = ptr;
            ptr = ptr->next;
            curr->next->next = nxt;
            curr = curr->next->next;
        }

        while(head!=nullptr)
        {
            cout << head->val << " ";
            head = head->next;
        }

        // while(itr!=nullptr)
        // {
        //     cout << itr->val << " ";
        //     itr = itr->next;
        // }
        // cout << endl;

        // while(itr2!=nullptr)
        // {
        //     cout << itr2->val << " ";
        //     itr2 = itr2->next;
        // }
        // cout << endl;

    }
};
