class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        if (n < 3) return 0;

        vector<int> increasing(n, 0), decreasing(n, 0);

        // Fill increasing array
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (rating[j] < rating[i]) {
                    increasing[i]++;
                }
            }
        }

        // Fill decreasing array
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (rating[j] > rating[i]) {
                    decreasing[i]++;
                }
            }
        }

        int teams = 0;

        // Count valid teams
        for (int i = 0; i < n - 1; ++i) {
            int inc = 0, dec = 0;
            for (int j = i + 1; j < n; ++j) {
                if (rating[i] < rating[j]) {
                    inc++;
                }
                if (rating[i] > rating[j]) {
                    dec++;
                }
            }
            teams += increasing[i] * inc + decreasing[i] * dec;
        }

        return teams;
    }
};
