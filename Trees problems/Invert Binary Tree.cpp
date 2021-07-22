// Problem Link:  https://leetcode.com/problems/invert-binary-tree/

TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return root;
        invertTree(root->right);
        invertTree(root->left);
        TreeNode* temp=root->left;
        root->left=root->right;
        root->right=temp;
        return root;
    }
