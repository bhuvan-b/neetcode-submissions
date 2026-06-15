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
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return head;
        
        stack<ListNode*> st;
        ListNode* it = head;

        while(it!=nullptr)
        {
            st.push(it);
            it=it->next;
        }

        ListNode* newHead = st.top();
        st.pop();
        ListNode* it2 = newHead;

        while(!st.empty())
        {
            it2->next = st.top();
            st.pop();
            it2=it2->next;
        }

        it2->next = nullptr;

        return newHead;
    }
};
