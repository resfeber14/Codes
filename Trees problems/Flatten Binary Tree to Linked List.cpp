// Problem Link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

// Approach: Time Complexity: O(N)  Space Complexity: O(N)

// Here we are doing reverse Post order
// We first go to the right,assign its right to prev pointer,which will be pointing to the node to which its right should be attached and mark the prev pointer to this node
// Then we go to the node's left,and do the same

class Solution {
    TreeNode* prev=NULL;
public:
    
    void flatten(TreeNode* root) {
         if(!root)
            return;
        
        flatten(root->right);
        flatten(root->left);
        root->right=prev;
        root->left=NULL;
        prev=root;
    }
};
