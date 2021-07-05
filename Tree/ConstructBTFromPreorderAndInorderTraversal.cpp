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
    int pre_idx = 0;
    
    TreeNode* helper(vector<int>& pre, vector<int>& in, int in_lo, int in_hi) {
        // Base cases
        if (in_lo > in_hi) return nullptr;
        
        // Find where in the inorder array the root of this subtree is.
        int root_idx;
        for (int i = in_lo; i < in_hi; i++) {
            if (pre[pre_idx] == in[i]) {
                root_idx = i;
                break;
            }
        }
        
        // Create the node for parent of this subtree and move the preorder idx forward since this node has            been processed.
        TreeNode* parent = new TreeNode(pre[pre_idx]);
        pre_idx++;
        
        // Set parent's left and right subtrees.
        parent->left = helper(pre, in, in_lo, root_idx-1);
        parent->right = helper(pre, in, root_idx+1, in_hi);

        return parent;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Method 1: 
        //          Preorder (NLR) array will tell us the root of the subtree that is currently being                             processed.
        //          Inorder (LNR) array will tell us the left and right subtrees for that root.
        return helper(preorder, inorder, 0, inorder.size()-1);
    }
};
