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
        
        ListNode* h=head, *h2=head;
         
        for(int i=0;i<n;i++)
        {
            h=h->next;
        }
        if(!h) return head->next;
        
        while(h->next){
        h2=h2->next;
        h=h->next;
        }
        
        cout<<h2->val;
        if(h2->next){
            ListNode* temp=h2->next;
            h2->next=h2->next->next;
            delete temp;
            }

        return head;

    }
};