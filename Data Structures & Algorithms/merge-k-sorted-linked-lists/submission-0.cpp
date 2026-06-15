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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* nHead = new ListNode();

        for(int i=0;i<lists.size();i++)
        {
            ListNode* head2 = lists[i];
            ListNode* head1 = nHead->next;
            ListNode* itr = nHead;
            
            while(head1 && head2)
            {
                if(head1->val<head2->val)
                {
                    itr->next = head1;
                    itr=itr->next;
                    head1=head1->next;
                }
                else
                {
                    itr->next = head2;
                    itr=itr->next;
                    head2=head2->next;
                }
            }
            if(head1)
            {
                itr->next = head1;
            }
            if(head2)
            {
                itr->next = head2;
            }
        }
        return nHead->next;
    }
};
