// Problem Link:  https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

//Method 1:

TreeNode* solve(int i,int j,int &ind,vector<int> &inn,vector<int> &post){
        if(i>j)
            return NULL;
        int k=0;
        for(int indd=0;indd<inn.size();indd++){
            if(post[ind]==inn[indd]){
                k=indd;
                break;
            }
        }
        ind--;
        TreeNode* root=new TreeNode(inn[k]);
        root->right=solve(k+1,j,ind,inn,post);
        root->left=solve(i,k-1,ind,inn,post);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int ind=inorder.size()-1;
        return solve(0,inorder.size()-1,ind,inorder,postorder);
    }

//Method 2:

TreeNode* solve(int i,int j,int &ind,vector<int> &inn,vector<int> &post,map<int,int> &m){
        if(i>j)
            return NULL;
        int k;
        k=m[post[ind]];
        ind--;
        TreeNode* root=new TreeNode(inn[k]);
        root->right=solve(k+1,j,ind,inn,post,m);
        root->left=solve(i,k-1,ind,inn,post,m);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int ind=inorder.size()-1;
        map<int,int> m;
        for(int i=0;i<=ind;i++){
            m[inorder[i]]=i;
        }
        return solve(0,inorder.size()-1,ind,inorder,postorder,m);
    }
