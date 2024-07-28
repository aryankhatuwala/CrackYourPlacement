class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        vector<vector<int>>mat(n,vector<int>(m));
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 or j==0) {
                    mat[i][j]=matrix[i][j]-'0';
                    ans=max(ans,mat[i][j]);
                    continue;
                }

                if(matrix[i][j]=='0') mat[i][j]=0;
                else
                {
                    mat[i][j]=min(mat[i-1][j-1],min(mat[i-1][j],mat[i][j-1]))+1;
                }
                ans=max(ans,mat[i][j]);
            }
        }
        
        return ans*ans;
    }
};