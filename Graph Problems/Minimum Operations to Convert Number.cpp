/*
Problem Link: https://leetcode.com/problems/minimum-operations-to-convert-number/

*/

class Solution {
public:
    int minimumOperations(vector<int>& arr, int start, int goal) {
        int n=arr.size();
        queue<int> q;
        q.push(start);
        vector<int> visited(1003,0);
        int s=start;
        int ans=0;
        while(!q.empty()){
            int len=q.size();
            for(int i=0;i<len;i++){
                int topp=q.front();
                q.pop();
                if(topp==goal)
                    return ans;
                if(topp<0 || topp>1000 || visited[topp])
                    continue;
                visited[topp]=1;
                for(int j=0;j<arr.size();j++){
                    int op1=((arr[j])^(topp));
                    int op2=arr[j]+topp;
                    int op3=topp-arr[j];
                    q.push(op1);
                    q.push(op2);
                    q.push(op3);
                }
                
            }
                ans++;
        }
        return -1;
    }
};
