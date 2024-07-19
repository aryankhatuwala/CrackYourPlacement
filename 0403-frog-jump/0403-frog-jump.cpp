class Solution {
public:
    bool func(int pos, int k, vector<int>& stones, int n, set<int>& st, map<pair<int, int>, bool>& memo) {
        if (pos == stones[n - 1]) return true;
        if (pos > stones[n - 1] || k <= 0) return false;

        if (st.find(pos) == st.end()) return false;

        auto key = make_pair(pos, k);
        if (memo.find(key) != memo.end()) return memo[key];

        bool one = func(pos + k, k, stones, n, st, memo);
        bool two = func(pos + k - 1, k - 1, stones, n, st, memo);
        bool three = func(pos + k + 1, k + 1, stones, n, st, memo);

        memo[key] = one || two || three;
        return memo[key];
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if(stones[1]!=1) return false;
        set<int> st(stones.begin(), stones.end());
        map<pair<int, int>, bool> memo;
        return func(1, 1, stones, n, st, memo); // Start with k=1 instead of k=0
    }
};
