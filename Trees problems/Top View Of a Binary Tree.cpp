// Problem Link:   https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1#

// Problem Link:   https://www.hackerrank.com/challenges/tree-top-view/problem


vector<int> topView(Node *root)
    {
        //Your code here
        vector<int> v;
        map<int,int> m;
        queue<pair<Node*,int> > q;
        q.push({root,0});
        while(!q.empty()){
            pair<Node*,int> curr=q.front();
            Node* curr1=curr.first;
            int curr2=curr.second;
            q.pop();
            if(m.find(curr2)==m.end()){
                m[curr2]=curr1->data;
            }
            if(curr1->left)
                q.push({curr1->left,curr2-1});
            if(curr1->right)
                q.push({curr1->right,curr2+1});
        }
        for(auto it:m){
            v.push_back(it.second);
        }
        return v;
    }
