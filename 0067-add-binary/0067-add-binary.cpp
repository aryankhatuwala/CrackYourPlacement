class Solution {
public:
    string addBinary(string a, string b) {
        
        int n=a.size(), m=b.size();

        if(n<m) return addBinary(b,a); 

        int i=n-1, j=m-1;
        string ans="";
        int carry=0;
        while(i>=0 and j>=0)
        {
            int x=a[i]-'0', y=b[j]-'0';
            int sum= x+y+carry;
            int digit= sum%2;
            carry=sum/2;
            ans=to_string(digit)+ans;
            i--; j--;
        }
        while(i>=0)
        {
            int x=a[i]-'0';
            int sum= x+carry;
            int digit= sum%2;
            carry=sum/2;
            ans=to_string(digit)+ans;
            i--; 
        }
        if(carry)
        ans=to_string(carry)+ans;
        return ans;

    }
};