class Solution {
public:
    void findLps(string str, vector<int>&lps)
    {
        int i=0,j=1;
        lps[0]=0;
        while(i<str.size() and j<str.size())
        {
            if(str[i]==str[j])
            {
                lps[j]=i+1;
                i++;j++;
            }
            else
            {
                if(i==0)
                {
                    lps[j]=0; j++; 
                }
                else 
                i=lps[i-1];
            }

        }
    }
    int strStr(string haystack, string needle) {
        
        int n=haystack.size(), m=needle.size();
        int i=0,j=0;
        vector<int>lps(m);
        findLps(needle,lps);
        while(i<n)
        {
            if(haystack[i]==needle[j])
            {
                i++; j++;
            }
            if(j==m)
            return i-m;

            else if(haystack[i]!=needle[j] and i<n)
            {
                if(j==0) i++;
                else
                 j=lps[j-1];
            }
        }
        return -1;

    }
};