class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Method 1: Use HashMap to store each number in nums and its index i.
        //           Then after we can check if target-nums[i] exists in the HashMap
        // Runtime: O(N) where N is the length of nums
        // Space: O(N) need HashMap
        
        int N = nums.size();
        unordered_map<int, int> m;
        
        for (int i = 0; i < N; i++) {
            if (m.find(target-nums[i]) != m.end()) return {i, m[target-nums[i]]};
            m[nums[i]] = i;
        }
        
        return {};
    }
};
