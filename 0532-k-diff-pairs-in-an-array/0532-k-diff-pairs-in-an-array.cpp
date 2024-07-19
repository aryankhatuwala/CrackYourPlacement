class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0; // Since k must be non-negative

        map<int, int> mp;
        set<pair<int, int>> st;
        
        for (int num : nums) {
            mp[num]++;
        }
        
        int ans = 0;
        for (const auto& p : mp) {
            int x = p.first;
            int temp = x - k;
            
            if (k == 0) {
                if (mp[x] > 1) {
                    ans++;
                }
            } else {
                if (mp.find(temp) != mp.end()) {
                    st.insert({min(x, temp), max(x, temp)});
                }
            }
        }
        
        return k == 0 ? ans : st.size();
    }
};
