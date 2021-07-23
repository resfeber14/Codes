// Probelm Link:   https://leetcode.com/problems/binary-tree-pruning/

bool solve(TreeNode* root){
        if(!root)
            return true;
        bool l=solve(root->left);
        bool r=solve(root->right);
        if(l && r){
            root->left=root->right=NULL;
            if(root->val==0)
                return true;
        }
        else{
            if(l)
                root->left=NULL;
            if(r)
                root->right=NULL;
        }
        return false;
        
    }
    TreeNode* pruneTree(TreeNode* root) {
        bool x= solve(root);
        if(x)
            return NULL;
        return root;
    }
