class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int n=haystack.size(), m=needle.size();
        int h_hash,n_hash; 
        h_hash=n_hash=0;
        int mod=11;
        int d=10;
        for(int i=0;i<m;i++)
        {
            h_hash=(h_hash*d+haystack[i]-'a'+1)%mod;
            n_hash=(n_hash*d+needle[i]-'a'+1)%mod;
        }
        cout<<n_hash<<" ";
        int q=1;
        for(int i=0;i<m-1;i++) q=(q*d)%mod;

        for(int i=0;i<= n-m;i++)
        {
           if(h_hash==n_hash)
           {
              int flag=true; 
              for(int j=0;j<m;j++)
              {
                if(haystack[i+j]!=needle[j]) flag=false;
              }
              if(flag) return i;
           }
           else if(i<n-m)
           {
             h_hash=((h_hash-(haystack[i]-'a'+1)*q)*d + haystack[i+m]-'a'+1)%mod;
             if(h_hash<0)
             h_hash+=mod;
            cout<<h_hash<<" ";
           }
        }
        return -1;
    }
};