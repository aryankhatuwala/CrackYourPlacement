class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n=bills.size();
        // sort(bills.begin(),bills.end());
        map<int,int>mp;

        for(int i=0;i<n;i++)
        {
            int amt=bills[i], copy=amt, flag=false;
            if(amt==10)
            {
                if(mp[5]>=1) 
                mp[5]--;
                else return false;
            }
            else if(amt==20)
            {
                if(mp[10]>=1){
                    mp[10]--; amt-=10;
                }
                else if(mp[5]>=3){
                 mp[5]-=3;
                 amt=5;
                }
                else 
                return false;

                if(amt==10 and mp[5]>=1){
                    mp[5]--; amt-=5;
                }
                else if(amt!=5)
                return false;
            }
            mp[copy]++;
        }
        return true;
    }
};