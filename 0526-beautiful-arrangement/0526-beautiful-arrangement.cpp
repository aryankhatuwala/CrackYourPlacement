class Solution {
public:
    int func(int place, int n, int mask)
    {
        if(place==n+1) return 1;
        // if(mask==(1<<(n+1)-1)) return 1;

        int inc=0;
        for(int k=1;k<=n;k++)
        {
            if((k%place==0 or place%k==0) and (mask&(1<<k))==0)
            {
             int new_mask=(1<<k)|mask;
             inc+=func(place+1,n,new_mask);
            }
        }
        return inc;
    }
    int countArrangement(int n) {
        // vector<int>used(n+1,0);
        return func(1,n,0);
    }
};