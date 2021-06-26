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
    int maxDepth(TreeNode* root) {
        // Method 1: Recursive DFS
        //           Keep recursing on left and/or right nodes until we get to a leaf node (nodes with                          neither a left or right child). Then, each leaf returns 1 and at each parent node                          return the max of its children+1 to its parent.
        // Runtime: O(N) where N is nodes in the tree
        // Space: O(N) due to call stack
        if (!root) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left, right) + 1;
    }
};
