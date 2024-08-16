class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();
        
        int mini = arrays[0][0];            // Initialize to the first element of the first array
        int maxi = arrays[0].back();        // Initialize to the last element of the first array
        int max_diff = 0;
        
        for (int i = 1; i < n; i++) {
            // Calculate the potential max distance using current array's first and last element
            max_diff = max(max_diff, abs(arrays[i].back() - mini));
            max_diff = max(max_diff, abs(maxi - arrays[i][0]));
            
            // Update global minimum and maximum considering the current array
            mini = min(mini, arrays[i][0]);
            maxi = max(maxi, arrays[i].back());
        }
        
        return max_diff;
    }
};
