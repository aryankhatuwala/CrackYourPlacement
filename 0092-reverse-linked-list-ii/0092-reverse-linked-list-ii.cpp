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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        vector<int>ans;
        ListNode* h=head;
        int flag=0, count=1;
        while(head and count !=right+1)
        {
            if(count==left)
            flag=1;

            if(flag==1)
            ans.push_back(head->val);

            head=head->next;
            count++;
        }

        for(auto it:ans)cout<<it<<" ";

        int k=ans.size()-1;
        // cout<<k;
        head=h;
        flag=0;
        count=1;
        while(head and count !=right+1)
        {
            cout<<"*";
            if(count ==left)
            flag=1;

            if(flag==1)
            head->val=ans[k--];

            head=head->next;
            count++;
        }

        return h;
    }
};