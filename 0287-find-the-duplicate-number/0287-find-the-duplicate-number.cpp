class Solution {
public:
    int findSmaller(int x, vector<int>& nums){
        int count=0;
        for(auto it:nums)
        if(it<x)
        count++;

        return count;
    }
    int findDuplicate(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        int n=nums.size();
        int low=1, high=n-1;

        while(low<=high)
        {
            int mid=(low+high)/2;

            int count=findSmaller(mid,nums);
            if(count<mid)
            {
                low=mid+1;
            }
            else if(count>=mid)
             high=mid-1;
        }
        return high;
    }
};