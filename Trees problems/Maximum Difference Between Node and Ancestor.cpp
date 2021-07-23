// Problem Link:  https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/


int ans=0;
    pair<int,int> solve(TreeNode* root){
        pair<int,int> p;
        if(!root){
            p.first=INT_MAX;
            p.second=INT_MIN;
            return p;
        }
        pair<int,int> l=solve(root->left);
        pair<int,int> r=solve(root->right);
        p.first=min(l.first,r.first);
        p.second=max(l.second,r.second);
       // cout<<l.first<<" "<<l.second<<" "<<r.first<<" "<<r.second<<'\n';
        if(p.first==INT_MAX){
            p.first=root->val;
        }
        else{
            ans=max(ans,abs(root->val-p.first));
            p.first=min(p.first,root->val);
        }
        if(p.second==INT_MIN){
            p.second=root->val;
        }
        else{
            ans=max(ans,abs(root->val-p.second));
            p.second=max(p.second,root->val);
        }
        
        return p;
        
    }
    int maxAncestorDiff(TreeNode* root) {
        solve(root);
        return ans;
    }
