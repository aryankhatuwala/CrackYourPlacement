class Solution {
public:
    int func(vector<int>&arr, int k)
    {
        int ans=INT_MIN;
        int sum=0, n=arr.size();
        map<int,int>mp;
        mp[0]=1;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            int need=sum-k;
            auto lb=mp.lower_bound(need);

            if(lb!=mp.end())
            ans=max(ans, sum-lb->first);

            mp[sum]++;
        }
        return ans;
    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        
        int n=matrix.size(), m=matrix[0].size();
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            vector<int>cur(m,0);
            for(int j=i;j<n;j++)
            {
                for(int k=0;k<m;k++)
                {
                   cur[k]+=matrix[j][k];
                }
                ans=max(ans, func(cur,k));
            }
        }
        return ans;
    }
};