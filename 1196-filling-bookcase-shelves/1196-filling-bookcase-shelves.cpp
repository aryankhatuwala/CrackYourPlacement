class Solution {
public:
   int func(int ind,vector<vector<int>>& books, int n, int shelfWidth,
   vector<int>&dp )
   {
       if(ind==n) return 0;
       if(dp[ind]!=-1) return dp[ind];

       int width=0, max_height=INT_MIN, ans=INT_MAX;
       for(int k=ind;k<n;k++)
       {
         width+=books[k][0];

         if(width>shelfWidth) break;

         max_height=max(max_height, books[k][1]);
         int next=max_height+ func(k+1,books,n,shelfWidth,dp);
         ans=min(ans, next);
       }
       return dp[ind]=ans;
   }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n=books.size();
         vector<int>dp(n,-1);
        return func(0, books,n,shelfWidth,dp);
    }
};