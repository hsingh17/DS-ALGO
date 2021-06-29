/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:    
    TreeNode* helper(vector<int>& nums, int left, int right) {
        // Base case (Step 4)
        if (left == right) return new TreeNode(nums[left]);
        if (left > right) return nullptr;
        
        // Step 2
        int mid = ceil((left+right) / 2);
        TreeNode* parent = new TreeNode(nums[mid]);
        
        // Step 3 & 5
        parent->left = helper(nums, left, mid-1);
        parent->right = helper(nums, mid+1, right);
        
        return parent;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // Method 1: Divide & Conquer Method
        //          To create a height-balanced BST, we can take the middle element (since the array is                         sorted) and recurse on the left and right until the base case where there is only one                       element in the array.
        //          Step 1: Have left & right pointers
        //          Step 2: Find the middle element
        //          Step 3: Recurse until base case (left >= right)
        //          Step 4: Return the node with the value.
        //          Step 5: At the parent node, set the left and right children returned by subproblem.
        // This creates a height-balanced BST because at each subproblem, we guarantee the left and right              children both have a depth that doesn't differ by more than one by selecting the middle element            in the subproblem to be the parent.
        // Runtime: O(N) where N is length of nums
        // Space: O(N)
        return helper(nums, 0, nums.size()-1);
    }
};
