class Solution {
public:
    int find_max(vector<int>& arr, int k) {
        int n = arr.size();
        int maxi = INT_MIN;
        int curr_sum = 0;
        map<int, int> mp;
        mp[0] = 0;  // Insert 0 with a value of 0 to handle cases where the subarray itself is exactly k

        for (int i = 0; i < n; i++) {
            curr_sum += arr[i];
            int need = curr_sum - k;
            auto lb = mp.lower_bound(need);

            if (lb != mp.end()) {
                maxi = max(maxi, curr_sum - lb->first);
            }

            // We use the cumulative sum directly as the key to ensure correctness
            // If the same prefix sum occurs, we store the smallest index for consistency
            mp[curr_sum] = i;
        }
        
        return maxi;
    }

    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxi = INT_MIN;

        for (int start_row = 0; start_row < n; start_row++) {
            vector<int> col_array(m, 0);
            for (int end_row = start_row; end_row < n; end_row++) {
                for (int col = 0; col < m; col++) {
                    col_array[col] += matrix[end_row][col];
                }
                int curr_max = find_max(col_array, k);
                maxi = max(maxi, curr_max);
            }
        }

        return maxi;
    }
};

