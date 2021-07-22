// Problem Link:  https://leetcode.com/problems/symmetric-tree/

bool solve(TreeNode* root1,TreeNode* root2){
        if(!root1 && !root2)
            return true;
        if(!root1 && root2 || root1 && !root2)
            return false;
        if(root1->val==root2->val){
            return solve(root1->left,root2->right) && solve(root2->left,root1->right);
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return solve(root->left,root->right);
    }
