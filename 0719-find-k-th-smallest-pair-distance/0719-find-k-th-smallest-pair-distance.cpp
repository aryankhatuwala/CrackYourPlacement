class Solution {
public:
    int countPairs(int mid, vector<int>& nums) {
        int count = 0;
        int start = 0;
        for (int end = 0; end < nums.size(); ++end) {
            while (start < nums.size() && nums[start] - nums[end] <= mid) {
                ++start;
            }
            count += start-end-1;
        }
        return count;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0, right = nums[n-1] - nums[0];

        while (left < right)   //binary search
        {
            int mid = left + (right - left) / 2;
            if (countPairs(mid, nums) < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return left;
    }

};