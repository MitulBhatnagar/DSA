class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > bloomDay.size()) return -1;

        int lo = 1, hi = 1e9;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int bouquets = 0, adj = 0;

            for (int day : bloomDay) {
                if (day <= mid) {
                    if (++adj == k) {
                        bouquets++;
                        adj = 0;
                    }
                } else {
                    adj = 0;
                }
            }

            if (bouquets >= m) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};