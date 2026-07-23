class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int singnumber = 0;

        for(int num : nums){
            singnumber ^= num;

        }

        return singnumber;
    }
};