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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        
        // Method 1: Just BFS
        queue<TreeNode*> q;
        vector<vector<int>> lvl_order;
        q.push(root);
        
        while (!q.empty()) {
            vector<int> lvl;
            int q_size = q.size();
            
            // There are q_size number of TreeNodes for this lvl
            for (int i = 0; i < q_size; i++) {
                auto& node = q.front();
                lvl.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                q.pop();
            }
            
            lvl_order.push_back(lvl);
        }
        
        return lvl_order;
    }
};
