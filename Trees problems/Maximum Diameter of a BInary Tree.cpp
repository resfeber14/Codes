// Problem Link:   https://leetcode.com/problems/diameter-of-binary-tree/


// Approach 1: Time Complexity: O(N*N) Space Complexity: O(N)

// Brute Force
int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return 1+max(height(root->left),height(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        int h1=height(root->left);
        int h2=height(root->right);
        int op1=h1+h2;
        int op2=diameterOfBinaryTree(root->left);
        int op3=diameterOfBinaryTree(root->right);
        return max(op1,max(op2,op3));
    }

// Approach 2: Here in the pair we are storing the height of the node and the maximum diameter upto now

pair<int,int> diameter(TreeNode* root){
        pair<int,int> p;
        if(!root){
            p.first=0;
            p.second=0;
            return p;
        }
        pair<int,int> l=diameter(root->left);
        pair<int,int> r=diameter(root->right);
        p.first=max(l.first,r.first)+1;
        int op1=l.first+r.first;
        int op2=l.second;
        int op3=r.second;
        p.second=max({op1,op2,op3});
        return p;
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
       return diameter(root).second; 
    }

// Approach 3:

// Here we are using the Maximum Depth of a Binary tree code.And just updating the diamter

int solve(TreeNode* root,int &dia){
        if(!root)
            return 0;
        int lh=solve(root->left,dia);
        int rh=solve(root->right,dia);
        dia=max(dia,lh+rh);
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dia=0;
        solve(root,dia);
        return dia;
    }
