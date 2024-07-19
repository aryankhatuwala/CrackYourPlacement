class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp;
        int start=0,k=0;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]]==1){
            swap(nums[i],nums[start++]);
            k++;
            }
        }
        return k;
    }
};