class Solution {
public:
    int dp[1002][1002][4];
    int func(int cur, int prev, int count, vector<int>&rating,int n)
    {
        if(count==3) return 1;
        if(cur==n) return 0;
        if(dp[cur][prev+1][count]!=-1) return dp[cur][prev+1][count];
        
        int inc, notinc;
        inc=0;
        notinc=func(cur+1,prev, count, rating,n);
        if(prev==-1 || rating[cur]>rating[prev])
        {
            inc=func(cur+1,cur,count+1,rating,n);
        }
        return dp[cur][prev+1][count]=inc+notinc;
    }
    int numTeams(vector<int>& rating) {
        memset(dp,-1,sizeof(dp));
        int n=rating.size();

        int ans1=func(0,-1,0,rating,n);
        reverse(rating.begin(),rating.end());
        memset(dp,-1,sizeof(dp));
        int ans2=func(0,-1,0,rating,n);
        return ans1+ans2;
    }
};