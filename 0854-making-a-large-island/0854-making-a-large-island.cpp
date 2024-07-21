class Disjoint
{
    public:
    vector<int>parent,size;
    Disjoint(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++) parent[i]=i;
    }
    int findParent(int node)
    {
        if(parent[node]==node) return node;
        return parent[node]=findParent(parent[node]);
    }
    void unionBySize(int u, int v)
    {
        int ulp_u=findParent(u), ulp_v=findParent(v);

        if(ulp_u==ulp_v) return;

        if(size[ulp_u]>size[ulp_v])
        {
            size[ulp_u]+=size[ulp_v];
            parent[ulp_v]=ulp_u;
        }
        else
        {
            size[ulp_v]+=size[ulp_u];
            parent[ulp_u]=ulp_v;
        }
    }
};
class Solution {
public:
    void func(int i, int j, vector<vector<int>>& grid,int n,
    vector<vector<int>>& vis,Disjoint &d)
    {
        queue<pair<int,int>>q;
        q.push({i,j});
        vis[i][j]=1;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        
        while(!q.empty())
        {
            auto row=q.front().first, col=q.front().second;
            q.pop();
            
            for(int k=0;k<4;k++)
            {
                int newR=delrow[k]+row;
                int newC=delcol[k]+col;

                if(newR>=0 and newR<n and newC>=0 and newC<n 
                and grid[newR][newC]==1 and vis[newR][newC]==0)
                {
                    vis[newR][newC]=1;
                    q.push({newR,newC});
                    int x=row*n+col, y=newR*n+newC;
                    d.unionBySize(x,y);
                }      
            }
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        
        int n=grid.size();
        Disjoint d(n*n);
        vector<vector<int>>vis(n,vector<int>(n,0));
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1 and vis[i][j]==0)
                {
                    func(i,j,grid,n,vis, d);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1) continue;
                set<int>st;

                for(int k=0;k<4;k++)
                {
                  int newR=delrow[k]+i;
                  int newC=delcol[k]+j;

                  if(newR>=0 and newR<n and newC>=0 and newC<n 
                  and grid[newR][newC]==1)
                  st.insert(d.findParent(newR*n+newC));    
                }
                int count=0;
                for(auto it:st)
                count+=d.size[it];
                ans=max(ans,count+1);
            }
        }
        for(int i=0;i<=n*n;i++)
         if(d.parent[i]==i)
         ans=max(ans,d.size[i]);

        return ans;
    }
};