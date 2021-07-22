// Problem Link:  https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/


TreeNode* solve(TreeNode* root1,TreeNode* root2,TreeNode* k){
        if(!root1 && !root2)
            return NULL;
        if(root1==k)
            return root2;
        TreeNode *l=solve(root1->left,root2->left,k);
        TreeNode* r=solve(root1->right,root2->right,k);
        if(!l && !r)
            return l;
        if(l)
            return l;
        return r;
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return solve(original,cloned,target);
    }
