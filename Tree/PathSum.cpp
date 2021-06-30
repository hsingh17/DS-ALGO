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
    bool dfs(TreeNode* node, int& cur_sum, const int& target_sum) {
        cur_sum += node->val;
        if ((cur_sum == target_sum) && (!(node->left) && !(node->right))) return true;
        
        bool left_sum  = (node->left) ? dfs(node->left, cur_sum, target_sum) : false;
        bool right_sum  = (node->right) ? dfs(node->right, cur_sum, target_sum) : false;
        
        cur_sum -= node->val;
        return left_sum || right_sum;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        // Method 1: DFS Brute Force All Paths
        //          We can find the sum of all paths by doing DFS until we hit a leaf node and at every                         leaf node, check if we reached the targetSum.
        // Runtime: O(N) where N is number of nodes.
        // Space: O(N)
        if (!root) return false;
        int cur_sum = 0;
        return dfs(root, cur_sum, targetSum);
        
    }
};
