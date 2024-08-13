class Solution {
public:
    bool func(int ind,vector<int>& nums, int n,vector<int>&dp )
    {
        if(ind==n-1) return true;
        if(ind>=n) return false;
        if(dp[ind]!=-1) return dp[ind];

        bool ans=false;
        for(int k=1;k<=nums[ind];k++)
        {
            if(ind+k>=n) break;

            ans|= func(ind+k,nums,n,dp);
        }
        return dp[ind]=ans;
    }
    bool canJump(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>dp(n,-1);
        return func(0,nums,n,dp);

        // vector<bool>dp2(n+1,false);
        // dp2[n-1]=true;
        // for(int i=n-2;i>=0;i--)
        // {
        //     bool ans=false;
        //     for(int k=1;k<=nums[i];k++)
        //     {
        //         if(i+k<n)
        //         ans|=dp2[i+k];

        //         if(i+k>=n) break;
        //     }
        //     dp2[i]=ans;
        // }
        // return dp2[0];
    }
};