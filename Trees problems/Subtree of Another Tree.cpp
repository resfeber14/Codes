// Problem Link:   https://leetcode.com/problems/subtree-of-another-tree/

// Two recursion Method

bool solve(TreeNode* root, TreeNode* subRoot){
        if((!root && subRoot) || (!subRoot && root)){
            return false;
        }
        if(!root && !subRoot)
           return true;
        if(root->val!=subRoot->val)
            return false;
           return solve(root->left,subRoot->left) && solve(root->right,subRoot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root)
            return false;
        if(solve(root,subRoot))
            return true;
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
