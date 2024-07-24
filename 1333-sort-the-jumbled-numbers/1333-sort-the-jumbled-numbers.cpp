class Solution {
public:
    struct State{
        int ind, number, newNum;
    };
    bool static cmp(State &a, State &b)
    {
        return a.newNum==b.newNum? a.ind<b.ind : a.newNum<b.newNum;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n=nums.size();
        vector<State>vec;
        for(int i=0;i<n;i++)
        {
            string str=to_string(nums[i]);
            string temp="";
            for(int i=0;i<str.size();i++) temp+=to_string(mapping[str[i]-'0']);
            int sum=stoi(temp);
            cout<<sum<<" ";
            vec.push_back({i,nums[i],sum});
        }
        sort(vec.begin(),vec.end(),cmp);
        vector<int>ans;
        for(auto it: vec)
        {
            ans.push_back(it.number);
        }
        return ans;
    }
};