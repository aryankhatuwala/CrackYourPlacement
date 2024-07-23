class Solution {
public:
    bool static cmp(pair<int,int>&a, pair<int,int>&b)
    {
        return (a.second==b.second)? a.first>b.first: 
        a.second<b.second;
    }
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int>mp;
        for(auto it: nums) mp[it]++;

        vector<pair<int,int>>arr;
        for(auto it:mp)
        arr.push_back({it.first, it.second});

        sort(arr.begin(),arr.end(),cmp);

        vector<int>ans;
        for(auto it:arr)
        {
            for(int i=0;i<it.second;i++)
            ans.push_back(it.first);
        }
        return ans;
    }
};