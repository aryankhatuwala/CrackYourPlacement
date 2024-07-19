class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=1,ans=0;
        sort(nums.begin(),nums.end());
        set<pair<int,int>>st;
        while(j<n)
        {
            int diff=nums[j]-nums[i];
            if(i==j){
                j++; 
                continue;
            }
            if(diff==k and 
            st.find({min(nums[i],nums[j]),max(nums[i],nums[j])})==st.end()) 
            {
                cout<<nums[i]<<" "<<nums[j]<<endl;
                st.insert({min(nums[i],nums[j]),max(nums[i],nums[j])});
                ans++; i++;j++;
            }
            else if(diff<k)
            j++;
            else 
            i++;
        }
        return ans;
    }
};