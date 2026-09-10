class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        const int* arr =piles.data();
        int size = piles.size();
        int high = piles[0];
        for(int i = 1; i < size; ++i) {
            if (arr[i] > high) {
                high = arr[i];

            }
        }
        while (low < high) {
            int mid = low + (high - low) / 2;
            long long hours = 0;
            for (int i = 0; i < size; ++i) {
                hours += (arr[i] + mid - 1) / mid;
            }
            if (hours <= h) {
                high = mid;
            }else {
                low = mid + 1;
            }
        }

        return low;
    }
};