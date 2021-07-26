
// Problem Link:  https://leetcode.com/problems/check-completeness-of-a-binary-tree/

bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        bool flag=true;
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr){
                if(curr->left){
                    if(!flag)
                        return false;
                    q.push(curr->left);
                }
                if(curr->right){
                    if(!flag || !curr->left)
                        return false;
                    q.push(curr->right);
                }
                if(!curr->left || !curr->right){
                    flag=false;
                }
            }
            else{
                if(!q.empty()){
                    q.push(NULL);
                }
            }
        }
        return true;
    }
