class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo = 1, hi = 1;
        for (int x : nums) {
            hi = max(hi, x);
        }

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            long long total = 0;
            for (int x : nums) {
                total += (x + mid - 1) / mid;
            }

            if (total <= threshold) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        return lo;
    }
};