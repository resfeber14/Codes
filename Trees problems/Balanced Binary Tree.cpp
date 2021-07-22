// Problem Link: https://leetcode.com/problems/balanced-binary-tree/

 pair<int,bool> solve(TreeNode* root){
        pair<int,bool> p;
        if(!root){
            p.first=0;
            p.second=true;
            return p;
        }
        pair<int,bool> l=solve(root->left);
        pair<int,bool> r=solve(root->right);
        p.first=max(l.first,r.first)+1;
        if(abs(l.first-r.first)<=1 && l.second && r.second){
            p.second=true;
        }
        else{
            p.second=false;
        }
        return p;
    }
    bool isBalanced(TreeNode* root) {
        return solve(root).second;
    }
