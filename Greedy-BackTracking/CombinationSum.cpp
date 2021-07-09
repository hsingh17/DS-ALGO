class Solution {
public:
    vector<vector<int>> combos;
    
    void helper(const vector<int>& nums, vector<int>& combo, const int& target, int k, int sum) {
        if (sum > target) return;
        if (sum == target) {
            combos.push_back(combo);
            return;
        }
        
        for (int i = k; i < nums.size(); i++) {
            combo.push_back(nums[i]);
            helper(nums, combo, target, i, sum+nums[i]);
            combo.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // Method 1: Brute force all combinations and check their sum. Return if the sum of the combination                      is greater than the target. 
        
        vector<int> combo;
        sort(candidates.begin(), candidates.end());
        helper(candidates, combo, target, 0, 0);
        return combos;
    }
};
