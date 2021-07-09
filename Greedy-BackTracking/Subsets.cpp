class Solution {
public:
    vector<vector<int>> power_set;
    void helper(vector<int>& nums, vector<int>& subset, int k) {
        if (k == nums.size()) {
            power_set.push_back(subset);
            return;
        }
        
        subset.push_back(nums[k]);
        helper(nums, subset, k+1);
        subset.pop_back();
        helper(nums, subset, k+1);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        // Method 1: Because there are 2^N subsets for an array of N elements, we can use the bits of each                        of those 2^N integers to tell us what numbers are in the subset.
        // vector<vector<int>> subsets;
        // for (int i = 0; i < (1 << nums.size()); i++) {
        //     vector<int> subset;
        //     for (int j = 0; j < nums.size(); j++) 
        //         if ((i >> j) & 1) subset.push_back(nums[j]);
        //     subsets.push_back(subset);
        // }
        // return subsets;
        
        // Method 2: Recursive
        vector<int> subset;
        helper(nums, subset, 0);
        return power_set;
    }
};
