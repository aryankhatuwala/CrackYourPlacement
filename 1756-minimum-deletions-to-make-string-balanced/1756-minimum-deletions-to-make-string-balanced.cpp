class Solution {
public:
    int func(int ind, string temp, string s, int n, map<pair<int,string>,int>&dp)
    {
        if(ind>=n) return 0;
        if(dp.find({ind,temp})!=dp.end()) return dp[{ind,temp}];

        int notinc,inc;
        inc=INT_MIN;
        notinc=func(ind+1,temp,s,n,dp);

        if(temp.empty() or temp.back()=='a' or (temp.back()=='b' and s[ind]=='b'))
        inc=1+func(ind+1,temp+s[ind],s,n,dp);
        
        return dp[{ind,temp}]=max(notinc,inc);
    }
    int minimumDeletions(string s) {
        int n=s.size();
        // map<pair<int,string>,int>dp;
        // int ans=func(0,"",s,n,dp);
        // return n-ans;
        
       int a_count=0,b_count=0;
       for(int i=0;i<n;i++)
       {
        if(s[i]=='a') a_count++;
        else b_count++;
       }
       int i=0,j=n-1;
       int ans=0;
       cout<<a_count<<" "<<b_count;
       while(i<=j)
       {
          if(a_count>b_count)
          {
            if(s[i]=='a') 
            a_count--;
            else {
            b_count--;
            ans++;
            }
            i++;
          }
          else
          {
            if(s[j]=='a'){
             a_count--;
             ans++;
            }
            else 
            b_count--;
            j--;
          }
       }
       return ans;

    }
};