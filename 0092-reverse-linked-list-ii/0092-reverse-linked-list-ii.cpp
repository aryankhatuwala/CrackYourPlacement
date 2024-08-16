class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int> ans;
        ListNode* h = head;
        int count = 1;
        
        // Collect values from the sublist defined by 'left' to 'right'
        while (head && count <= right) {
            if (count >= left) {
                ans.push_back(head->val);
            }
            head = head->next;
            count++;
        }

        // Reverse the sublist values in the original list
        head = h;
        count = 1;
        int k = ans.size() - 1;
        while (head && count <= right) {
            if (count >= left) {
                head->val = ans[k--];
            }
            head = head->next;
            count++;
        }

        return h;
    }
};
