class Solution {
public:
   bool static cmp(int &a, int &b){
   return a>b;
   }
    int minimumPushes(string word) {
        
        int n=word.size();
        vector<int>count(26,0);
        int arr[10]={0};

        for(int i=0;i<n;i++) count[word[i]-'a']++;

        sort(count.begin(),count.end(),cmp);
        int k=2, ans=0;
        for(int i=0;i<count.size();i++)
        {
            if(count[i]==0) continue;

            arr[k]++;
            ans+=arr[k]*count[i];
            k=(k+1);
            if(k==10)k=2;
        }
        return ans;
    }
};