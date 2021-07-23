pair<int,bool> solve(TreeNode* root,TreeNode* par){
        pair<int,bool> p;
        if(!root){
            p.first=par->val;
            p.second=true;
            return p;
        }
        if(!root->left && !root->right){
            p.first=root->val;
            p.second=true;
            return p;
        }
        pair<int,bool> l=solve(root->left,root);
        pair<int,bool> r=solve(root->right,root);
        if(l.second && r.second && (l.first==r.first) && (l.first==root->val)){
            p.first=root->val;
            p.second=true;
            return p;
        }
        p.first=root->val;
        p.second=false;
        return p;
        
    }
    bool isUnivalTree(TreeNode* root) {
        if(!root)
            return true;
        return solve(root,root).second;
    }
