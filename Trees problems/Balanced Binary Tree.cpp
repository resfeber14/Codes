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

// Approach 2:  Here we will only add 2 lines from the maximum depth of a binary tree


int solve(TreeNode* root){
        if(!root)
            return 0;
        int lh=solve(root->left);
        int rh=solve(root->right);
        if(lh==-1 || rh==-1)
            return -1;
        if(abs(rh-lh)>1)
            return -1;
        return max(lh,rh)+1;
    }
    
    bool isBalanced(TreeNode* root) {
        if(solve(root)==-1)
            return false;
        return true;
    }
