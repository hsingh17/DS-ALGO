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
    int good_nodes = 0;
    
    void dfs(TreeNode* node, int max) {
        if (!node) return;
        
        // Node X is a good node
        if (node->val >= max) {
            good_nodes++;
            max = node->val;
        }
        
        dfs(node->left, max);
        dfs(node->right, max);
    }
    
    int goodNodes(TreeNode* root) {
        if (!root) return 0;
        // A node X is good iff it is the LARGEST node from the root to node X, since if there was a node              with a value larger than X, then X would not be a good node.
        // We can do DFS on the binary tree, and determine the maximum along the current path.
        // At every step, we determine if the node X has a value >= than the maximum to determine if it is            a good node.
        dfs(root, -1e9);
        return good_nodes;
    }
};
