// Problem Link: https://leetcode.com/problems/delete-leaves-with-a-given-value/

// We are here doing Postorder traversal and finding if the node is a leaf node and its value is equal target,return NULL
// Time Complexity: O(N)
// Space Complexity: O(1)

TreeNode* solve(TreeNode* root,int k){
        if(!root)
            return NULL;
        root->left=solve(root->left,k);
        root->right=solve(root->right,k);
        if(root && !root->left && !root->right){
            if(root->val==k){
                TreeNode* curr=root;
                return NULL;
            }
        }
        return root;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int k) {
        return solve(root,k);
    }
