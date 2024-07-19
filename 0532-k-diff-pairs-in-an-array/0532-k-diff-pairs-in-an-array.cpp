class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=1,ans=0;
        sort(nums.begin(),nums.end());
        // set<pair<int,int>>st;
        while(j<n)
        {
            int diff=nums[j]-nums[i];
            if(i==j){
                j++; 
                continue;
            }
            if(diff==k) 
            {

                ans++; 
                i++;j++;
                while(i<n and nums[i]==nums[i-1])i++;
                while(j<n and nums[j]==nums[j-1])j++;
            }
            else if(diff<k)
            j++;
            else 
            i++;
        }
        return ans;
    }
};