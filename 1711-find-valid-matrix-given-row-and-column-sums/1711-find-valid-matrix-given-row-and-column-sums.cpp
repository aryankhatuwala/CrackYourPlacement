class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n=rowSum.size();
        int m=colSum.size();
        vector<vector<int>>mat(n,vector<int>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(rowSum[i]<colSum[j])
                    mat[i][j]=rowSum[i];
                else 
                mat[i][j]=colSum[j];

                rowSum[i]-=mat[i][j];
                colSum[j]-=mat[i][j];
            }
        }
        return mat;
    }
};