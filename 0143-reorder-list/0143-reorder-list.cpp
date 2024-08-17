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
        ListNode* dum=new ListNode(0);
        dum->next=head;
        ListNode* slow=dum, *fast=dum;

        while(fast and fast->next)  //find middle
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        //reverse second half;
        ListNode* prev=nullptr, *cur=slow->next;
        slow->next=nullptr;
        while(cur)
        {
            ListNode* next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }

        //merge the two halves
        ListNode* first=dum->next, *second=prev;
        if(first)
        cout<<first->val;
        if(second) cout<<second->val;
        while(first and second)
        {
            ListNode* sec_next=second->next;
            ListNode* first_next=first->next;
            second->next=first->next;
            first->next=second;
            first=first_next;
            second=sec_next;
        }

    }
};