class Solution {
public: 
    int func(vector<int>&arr, int k)
    {
        map<int,int>mp;
        int sum=0, n=arr.size(), maxi=INT_MIN;
        mp[0]=1;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            int need=sum-k;
            auto lb= mp.lower_bound(need);

            if(lb!=mp.end())
             maxi=max(maxi, sum- lb->first);

            mp[sum]++;
        }
        return maxi;
    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int limit) {
        int n=matrix.size(), m=matrix[0].size();
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            vector<int>cur(m,0);
            for(int j=i;j<n;j++)
            {
                for(int k=0;k<m;k++)
                cur[k]+=matrix[j][k];
                ans=max(ans,func(cur,limit));
            }
           
        }
        return ans;
    }
};