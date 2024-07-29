class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n=rating.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int leftSmaller=0, rightGreater=0;
            int leftGreater=0, rightSmaller=0;
            for(int j=0;j<n;j++)
            {
                if(j<i and rating[j]<rating[i]) leftSmaller++;
                if(j>i and rating[j]>rating[i]) rightGreater++;
                if(j<i and rating[j]>rating[i]) leftGreater++;
                if(j>i and rating[j]<rating[i]) rightSmaller++;
            }
            ans+=leftSmaller*rightGreater;
            ans+=leftGreater*rightSmaller;
        }
        return ans;
    }
};