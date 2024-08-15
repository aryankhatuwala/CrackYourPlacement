class Solution {
public:
    int countPairs(int mid, vector<int>& nums) {
        int count = 0;
        int start = 0, end=1, n=nums.size();
        while(end<n)
        {
           while(start<end and nums[end]-nums[start]>mid)
           start++;

           count+= end-start;
           end++;
        }
        return count;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0, right = nums[n-1] - nums[0];
         int ans=-1;
        while (left <= right)   //binary search
        {
            int mid = left + (right - left) / 2;
            int count=countPairs(mid, nums);
            if (count < k) 
                left = mid + 1;
            else{
                ans=mid;
                right = mid-1;
            }
            
        }
        return ans;
    }

};