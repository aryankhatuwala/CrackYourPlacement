class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> pq;
        int ans = INT_MIN;
        for(auto point:points)
        {
            while(pq.size() && point[0]-pq.top().second>k)
                pq.pop();

            if(!pq.empty())
                ans = max(ans, point[0] + point[1] + pq.top().first);
                
            pq.push(make_pair(point[1]-point[0], point[0]));
        }
        return ans;
    }
};