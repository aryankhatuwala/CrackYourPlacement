class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        
        int n=original.size();
        vector<vector<int>>mat(26,vector<int>(26,INT_MAX));

        for(int i=0;i<26;i++) mat[i][i]=0;

        for(int i=0;i<n;i++)
        {
            mat[original[i]-'a'][changed[i]-'a']= 
            min( mat[original[i]-'a'][changed[i]-'a'], cost[i]);
        }

        //floyd warshall
        for(int k=0;k<26;k++)
        {
            for(int i=0;i<26;i++)
            {
                for(int j=0;j<26;j++)
                {
                    if(mat[i][k]!=INT_MAX and mat[k][j]!=INT_MAX)
                    mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
                }
            }
        }

        //main logic
        long long ans=0;
        for(int i=0;i<source.size();i++)
        {
            if(source[i]==target[i]) continue;
            
            int dist=mat[source[i]-'a'][target[i]-'a'];

            if(dist==INT_MAX) return -1;

            ans+= dist;
        }
        return ans;
    }
};