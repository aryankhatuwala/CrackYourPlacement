class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int zero_idx=-1;
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                q.push(i);
            }
            else if(!q.empty())
            {
                int idx=q.front(); q.pop();
                nums[idx]=nums[i];
                nums[i]=0;
                i--;
            }
        }
    }
};