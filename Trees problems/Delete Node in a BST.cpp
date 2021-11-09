/*
Problem Link:  https://leetcode.com/problems/delete-node-in-a-bst/
*/

TreeNode* findMin(TreeNode* root){
        if(!root)
            return NULL;
        if(!root->left){
            return root;
        }
        return findMin(root->left);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return NULL;
        else if(root->val>key){
            root->left=deleteNode(root->left,key);
        }
        else if(root->val< key){
            root->right=deleteNode(root->right,key);
        }
        else{ // we have got the node
            // Case 1: the jkey is the root node
            if(!root->left && !root->right){
                delete root;
                root=NULL;
                return root;
            }
            // Case 2: They key's node has only one child
            else if(!root->left && root->right){
                TreeNode* temp=root;
                root=root->right;
                delete temp;
                return root;
            }
            else if(!root->right && root->left){
                TreeNode* temp=root;
                root=root->left;
                delete temp;
                return root;
            }
            // Case 3: They key's node has two children
            else{
                TreeNode* temp= findMin(root->right);
                root->val=temp->val;
                root->right=deleteNode(root->right,temp->val); // boils down to deleting
                // the node having the minimum value
                return root;
            }
        }
        return root;
    }
