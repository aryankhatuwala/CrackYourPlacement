class Solution {
public:
    struct State{
        int row,col,dist;
    };
    int func(vector<vector<int>>& grid, int n, int m)
    {
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<State>q;
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
         if(grid[i][j]==1){
          q.push({i,j,0});

        vis[i][j]=1;
        }
        if(q.empty() || q.size()==n*m) return -1;

        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        int ans=INT_MIN;
        while(!q.empty())
        {
            State cur=q.front();
            q.pop();
            int r=cur.row,c=cur.col,d=cur.dist;
            
            ans=max(ans,d);

            for(int k=0;k<4;k++)
            {
                int newR=delrow[k]+r;
                int newC=delcol[k]+c;

                if(newR>=0 and newR<n and newC>=0 and newC<m and
                 grid[newR][newC]==0 and vis[newR][newC]!=1)
                {
                   q.push({newR,newC,d+1}); 
                   vis[newR][newC]=1;
                }
                
            }
        }
        return ans==INT_MAX?-1:ans;
    }
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
       
        return func(grid,n,m);

    }
};