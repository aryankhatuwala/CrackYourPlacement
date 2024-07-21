class Solution {
public:
    int func(int i, int j,vector<vector<int>>& matrix, int n,int m)
    {
        queue<pair<int,int>>q;
        q.push({i,j});
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};

        // vector<vector<int>>vis(n,vector<int>(m,0));
        // vis[i][j]=1;
        int dist=0;
        while(!q.empty())
        {
            int size=q.size();
            while(size--){

            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            for(int k=0;k<4;k++)
            {
                int newR=row+delrow[k], newC=col+delcol[k];
                if(newR>=0 and newR<n and newC>=0 and newC<m 
                and matrix[newR][newC]>matrix[row][col] )
                {
                    // vis[newR][newC]=1;
                    q.push({newR,newC});
                }
            }

            }
            dist++;
        }
        return dist;
    }
    int dfs(int i, int j,vector<vector<int>>& matrix, int n,int m,
    vector<vector<int>>&dp)
    {
        if(dp[i][j]!=-1) return dp[i][j];

        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        
        int ans=0;
        for(int k=0;k<4;k++)
        {
            int newR=i+delrow[k], newC=j+delcol[k];

            if(newR>=0 and newR<n and newC>=0 and newC<m 
                and matrix[newR][newC]>matrix[i][j] )

               ans=max(ans, dfs(newR, newC, matrix,n,m,dp));
        }
        return dp[i][j]=1+ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=INT_MIN;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
            //    int temp=func(i,j,matrix,n,m);
            int temp=dfs(i,j,matrix,n,m,dp);
            ans=max(ans,temp);
            }
        }
        return ans;
    }
};