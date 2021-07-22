// Problem Link: https://leetcode.com/problems/same-tree/

bool solve(TreeNode* p,TreeNode* q){
        if(!p && !q)
            return true;
        if(!p && q || p && !q)
            return false;
        if(p->val==q->val && solve(p->left,q->left) && solve(p->right,q->right)){
            return true;
        }
        return false;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return solve(p,q);
    }
