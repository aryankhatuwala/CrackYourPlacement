class Solution {
public:
    int func(int i, int j,int count, vector<int>& boxes,
    vector<vector<vector<int>>>&dp)
    {
        if(i>j) return 0;
        
        if(dp[i][j][count]!=-1) return dp[i][j][count];

        int ans=(count+1)*(count+1) + func(i+1,j,0,boxes,dp); //taken as single element
        for(int k=i+1;k<=j;k++)
        {
            if(boxes[i]==boxes[k])
            {
                ans=max(ans, func(i+1,k-1,0,boxes,dp)+ func(k,j,count+1,boxes,dp));
                //1st func to remove the elements in between and 
                //2nd func to make a streak with the kth element
            }
        }
        return dp[i][j][count]=ans;
    }
    int removeBoxes(vector<int>& boxes) {
        int n=boxes.size();
        vector<vector<vector<int>>>dp (n+1,vector<vector<int>>(n+1,vector<int>(n+1,-1)));
        return func(0,n-1,0,boxes,dp);
    }
};