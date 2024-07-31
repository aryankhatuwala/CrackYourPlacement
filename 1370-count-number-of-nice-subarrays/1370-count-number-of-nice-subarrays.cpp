class Solution {
public:
   int func(vector<int>& nums, int k)
   {
        int n=nums.size();
        int start=0,end=0, ans=0, odd=0;
        while(end<n)
        {
            if(nums[end]%2==1) odd++;

            while(start<=end and odd>k)
            {
                if(nums[start]%2==1) odd--;
                start++;
            }
            ans+=(end-start+1);
            end++;
        }
        return ans;
   }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return func(nums,k)-func(nums,k-1);
        
    }
};