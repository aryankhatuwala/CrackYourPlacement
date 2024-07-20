class Solution {
public:
struct cmp{
   bool operator()(pair<int,int>&a,pair<int,int>&b){
    return a.second<b.second;
   }
};
 int func(int src, vector<vector<pair<int,int>>>&adj,int n, int k)
 {
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>q;
    q.push({src,0});
    vector<int>dist(n,INT_MAX);
    dist[src]=0;

    while(!q.empty())
    {
        auto node=q.top().first, d=q.top().second;
        q.pop();

        for(auto it:adj[node])
        {
            auto adjNode=it.first, adjW=it.second;
            if(dist[node]+adjW < dist[adjNode])
            {
                dist[adjNode]=dist[node]+adjW;
                q.push({adjNode,dist[adjNode]});
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++) if(dist[i]<=k) ans++;
    return ans;
 }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it: edges)
        {
            int from=it[0],to=it[1],w=it[2];
            adj[from].push_back({to,w});
            adj[to].push_back({from,w});
        }
        int ans=INT_MAX,city=-1;
        for(int i=0;i<n;i++)
        {
            int temp=func(i,adj,n,distanceThreshold);
            if(temp<=ans)
            {
                ans=temp;
                city=i;
            }
        }
        return city;
    }
};