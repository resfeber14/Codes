// Problem Link:   https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

// Method 1:

TreeNode* solve(int i,int j,int &ind,vector<int> &pre,vector<int> &inn){
        if(i<0 || j>=pre.size() || i>j || ind>=pre.size()){
            return NULL;
        }
        TreeNode* root=new TreeNode(pre[ind]);
        int k=-1;
        for(int indd=0;indd<pre.size();indd++){
            if(inn[indd]==pre[ind]){
                k=indd;
                break;
            }
        }
        ind++;
        root->left=solve(i,k-1,ind,pre,inn);
        root->right=solve(k+1,j,ind,pre,inn);
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& inn) {
        int n=pre.size();
        int ind=0;
        return solve(0,n-1,ind,pre,inn);
    }


// Method 2:

TreeNode* solve(int i,int j,int &ind,vector<int> &pre,vector<int> &inn,map<int,int> &m){
        if(i>j){
            return NULL;
        }
        TreeNode* root=new TreeNode(pre[ind]);
        int k=-1;
        k=m[pre[ind]];
        ind++;
        root->left=solve(i,k-1,ind,pre,inn,m);
        root->right=solve(k+1,j,ind,pre,inn,m);
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& inn) {
        int n=pre.size();
        int ind=0;
        map<int,int> m;
        for(int i=0;i<n;i++){
            m[inn[i]]=i;
        }
        return solve(0,n-1,ind,pre,inn,m);
    }
