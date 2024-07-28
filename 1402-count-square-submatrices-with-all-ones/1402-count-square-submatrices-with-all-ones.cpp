class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();

        vector<vector<int>>mat=matrix;

        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(mat[i][j]==0) mat[i][j]=0;
                else
                {
                    mat[i][j]=min(mat[i-1][j-1],min(mat[i-1][j],mat[i][j-1]))+1;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<mat[i][j]<<" ";
                ans+=mat[i][j];
            }
            cout<<endl;
        }
        return ans;
    }
};