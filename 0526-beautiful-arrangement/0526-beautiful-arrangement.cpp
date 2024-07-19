class Solution {
public:
    int func(int place, int n,vector<int>used)
    {
        if(place==n+1) return 1;

        // if(num==n+1) return 0;

        int inc=0,notinc=0;
        for(int k=1;k<=n;k++)
        {
            if((k%place==0 or place%k==0) and used[k]!=1)
            {
            used[k]=1;
            inc+=func(place+1,n,used);
            used[k]=0;
            }
        }
        return inc+notinc;
    }
    int countArrangement(int n) {
        vector<int>used(n+1,0);
        return func(1,n,used);
    }
};