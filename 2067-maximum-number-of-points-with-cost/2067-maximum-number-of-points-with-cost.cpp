class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int row = points.size();
        if(row == 0) // emtpy array
            return 0;
        

        int m = points[0].size();

        vector<long long> dp(points[0].begin(), points[0].end());
        vector<long long> left(m);
        vector<long long> right(m);

        for(int i=1; i<row; i++) 
        {
            left.front() = dp.front(); //for 0th index
            for(int j=1; j<m; j++) // left[j-1]-1, the minus 1 counts the shift
                left[j] = max(dp[j], left[j-1]-1); 
            

            right.back() = dp.back(); //for (m-1)th index
            for(int j=m-2; j>=0; j--) 
                right[j] =  max(dp[j], right[j+1]-1);
            

            for (int j=0; j<m; j++) //final ans
                dp[j] = points[i][j] + max(left[j], right[j]);

        }
        return *max_element(dp.begin(), dp.end());
    }
};