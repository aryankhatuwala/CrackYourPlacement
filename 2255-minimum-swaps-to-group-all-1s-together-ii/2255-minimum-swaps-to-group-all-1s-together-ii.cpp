class Solution {
public:
    int minSwaps(vector<int>& nums) {
        
        int n=nums.size();

        int ones=0;
        for(int i=0;i<n;i++) if(nums[i]==1) ones++;
        
        int bad=0;
        for(int i=0;i<ones;i++) if(nums[i]==0) bad++;

        int ans=bad;
        for(int i=ones;i<n+ones;i++)
        {
           if(nums[(i-ones)%n]==0) bad--;
           if(nums[i%n]==0) bad++;
           ans=min(ans, bad);
        }
        return ans;

    }
};