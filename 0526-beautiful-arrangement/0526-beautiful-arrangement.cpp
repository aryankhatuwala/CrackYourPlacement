class Solution {
public:
    int func(int place, int n, int mask,map<pair<int,int>,int>&mp)
    {
        if(place==n+1) return 1;
        if(mp.find({place,mask})!=mp.end()) return mp[{place,mask}];

        int inc=0;
        for(int k=n;k>=1;k--)
        {
            if((k%place==0 or place%k==0) and (mask&(1<<k))==0)
            {
             int new_mask=(1<<k)|mask;
             inc+=func(place+1,n,new_mask,mp);
            }
        }
        return mp[{place,mask}]=inc;
    }
    int countArrangement(int n) {
        // vector<int>used(n+1,0);
        // vector<vector<int>>dp(n+1,-1);
        map<pair<int,int>,int>mp;
        return func(1,n,0,mp);
    }
};