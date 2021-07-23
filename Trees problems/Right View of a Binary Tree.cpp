// Problem Link:  https://leetcode.com/problems/binary-tree-right-side-view/

//Method 1:  BFS

void solve(TreeNode* root,vector<int> &v){
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(q.size()>1){
            TreeNode* curr=q.front();
            q.pop();
            if(!q.front()){
                v.push_back(curr->val);
            }
            if(curr){
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            else{
                q.push(NULL);
            }
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        if(!root)
            return v;
        solve(root,v);
        return v;
    }

// Method 2: DFS
void solve(TreeNode* root,int d,vector<int> &v){
        if(!root)
            return;
        if(v.size()<d){
            v.push_back(root->val);
        }
        solve(root->right,d+1,v);
        solve(root->left,d+1,v);
   
}
    vector<int> rightSideView(TreeNode *root)
    {
       // Your code here
        vector<int> v;
        solve(root,1,v);
        return v;
    }
