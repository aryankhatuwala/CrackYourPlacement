class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxi=0, mini=INT_MAX;
        for(int i=0;i<n;i++)
        {
           if(mini!=INT_MAX)
           maxi=max(maxi,prices[i]-mini);
           mini=min(mini,prices[i]);
        }
        return maxi;
    }
};