class Solution {
public:
    vector<vector<int>> permutations;
    
    void helper(vector<int>& nums, vector<int> perm, vector<bool>& taken) {
        if (perm.size() == nums.size()) {
            permutations.push_back(perm);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (taken[i]) continue;
            perm.push_back(nums[i]);
            taken[i] = true;
            helper(nums, perm, taken);
            perm.pop_back();
            taken[i] = false;
        }
    } 
    
    vector<vector<int>> permute(vector<int>& nums) {
        // Method 1: Each number in nums is either currently in the permutation or not in the permutation
        //           Iterate through nums and check if it is taken or not, then mark as taken and push into                        the permutation. Repeat till permutation is size N
        // Runtime: O(N!)
        // Space: O(N)
        vector<bool> taken(nums.size(), false);
        helper(nums, {}, taken);
        return permutations;
    }
};
