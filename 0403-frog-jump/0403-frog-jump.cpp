class Solution {
public:
    bool func(int pos,int k, vector<int>& stones, int n,set<int>&st,
     map<pair<int,int>,bool>&mp )
    {
        if(pos==stones[n-1]) return true;
        if(pos>stones[n-1] || k<=0 || pos<0) return false;

        if(mp.find({pos,k})!=mp.end())return mp[{pos,k}];

        if(st.find(pos)==st.end()) return false;

        bool one,two,three;
        one=two=three=false;
        one=func(pos+ k,k,stones,n,st,mp);
        two=func(pos+ k-1,k-1,stones,n,st,mp);
        three=func(pos+ k+1,k+1,stones,n,st,mp);
        
        return  mp[{pos,k}]= one||two||three;
    }
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        set<int>st(stones.begin(),stones.end());
        map<pair<int,int>,bool>mp;
        if(stones[1]!=1) return 0;
        return func(1,1,stones,n,st,mp);
    }
};