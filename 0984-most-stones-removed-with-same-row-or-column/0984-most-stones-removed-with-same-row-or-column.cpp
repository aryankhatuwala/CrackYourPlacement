class Disjoint{
    public:
    vector<int>rank,parent;
    Disjoint(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
        parent[i]=i;
    }
    int findParent(int node)
    {
        if(node==parent[node])
        return node;

        return parent[node]=findParent(parent[node]);
    }
    void unionByRank(int u,int v)
    {
        int ulp_u=findParent(u);
        int ulp_v=findParent(v);

        if(rank[ulp_u]>rank[ulp_v])
        {
            parent[ulp_v]=ulp_u;
        }
        else if(rank[ulp_u]<rank[ulp_v])
        {
            parent[ulp_u]=ulp_v;
        }
        else
        {
            parent[ulp_u]=ulp_v;
            rank[ulp_v]++;
        }
    }
}; 
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        
        int n=stones.size();
        Disjoint d(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++){
                if(i==j)continue;

                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1])
                {
                    if(d.findParent(i)!=d.findParent(j))
                    {
                        d.unionByRank(i,j);
                    }
                }
            }
        }
        int compo=0;
        for(int i=0;i<n;i++)
        {
            if(d.findParent(i)==i) compo++;
        }
        return n-compo;
    }
};