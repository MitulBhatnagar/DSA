class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longestLength = 0;
        unordered_map<int, bool> exploredMap;
        
        for (int num : nums) {
            exploredMap[num] = false;
        }
        
        for (int num : nums) {
            if (exploredMap[num]) continue; 
            
            exploredMap[num] = true;
            int currentLength = 1;
            
            int nextNum = num + 1;
            while (exploredMap.count(nextNum) && !exploredMap[nextNum]) {
                currentLength++;
                exploredMap[nextNum] = true;
                nextNum++;
            }
            
            int prevNum = num - 1;
            while (exploredMap.count(prevNum) && !exploredMap[prevNum]) {
                currentLength++;
                exploredMap[prevNum] = true;
                prevNum--;
            }
            
            longestLength = max(longestLength, currentLength);
        }
        
        return longestLength;
    }
};