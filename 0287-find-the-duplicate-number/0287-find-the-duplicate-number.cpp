class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int slow=nums[0], fast=nums[0];
         
        //he initial values of slow and fast are the same, so the loop condition should ensure they move at least once before comparing.
         do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        int temp=nums[0];
        while(temp!=slow)
        {
            slow=nums[slow];
            temp=nums[temp];
        }
        return slow;
    }
};