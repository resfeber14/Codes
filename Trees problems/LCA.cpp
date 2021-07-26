
// Method 1: Brute Force 
// Store path in which n1 and n2 appears in two vectors.And find which is the first node to be different.Return previous node.

// Time complexity: O(N) Space Complexity: O(N)

bool solve(Node* root,vector<Node*> &v,int n){
        if(!root)
            return false;
        v.push_back(root);
        if(root->data==n)
            return true;
        if(root->left && solve(root->left,v,n) || root->right && solve(root->right,v,n)){
            return true;
        }
        v.pop_back();
        return false;
    }
    Node* lca(Node* root ,int n1 ,int n2 )
    {
        vector<Node*> v1;
        vector<Node*> v2;
        bool x=solve(root,v1,n1);
        bool y=solve(root,v2,n2);
        if(!x || !y)
            return NULL;
            int i;
        for(i=0;i<v1.size() && i<v2.size();i++){
            if(v1[i]!=v2[i]){
                break;
            }
        }
        return v1[i-1];
    }



// Method 2: Single Traversal
//// Time complexity: O(N) Space Complexity: O(1)

TreeNode* lca(TreeNode* root,TreeNode* p, TreeNode* q){
        if(!root)
            return NULL;
        if(root==p || root==q)
            return root;
        TreeNode* x=lca(root->left,p,q);
        TreeNode* y=lca(root->right,p,q);
        // If the LCA is the current root and p is in left and q is in right OR p is in right and q is in left
        if(x && y)
            return root;
        // Both are in left subtree
        if(x)
            return x;
        // Both are in right subtree
        return y;
    }
