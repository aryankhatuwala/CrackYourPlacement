class Solution {
public:
    string convertToTitle(int columnNumber) {
        int n=columnNumber;
        string ans="";
        while(n>0)
        {
            n--;
            int d=n%26;
            ans+= (d+65);
            n/=26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};