class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int lo = 0, hi = 0;
        for (int w : weights) {
            if (w > lo) lo = w;
            hi += w;
        }

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int reqDays = 1, load = 0;

            for (int w : weights) {
                if (load + w > mid) {
                    reqDays++;
                    load = 0;
                }
                load += w;
            }

            if (reqDays <= days) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        return lo;
    }
};