/* Problem Link:  https://www.lintcode.com/problem/787/

Here we will traverse till we have found a boundary or a wall

*/

/*
There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

Given the ball's start position, the destination and the maze, determine whether the ball could stop at the destination.

The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space. You may assume that the borders of the maze are all walls. The start and destination coordinates are represented by row and column indexes.
Example
Example 1:

Input:
map = 
[
 [0,0,1,0,0],
 [0,0,0,0,0],
 [0,0,0,1,0],
 [1,1,0,1,1],
 [0,0,0,0,0]
]
start = [0,4]
end = [3,2]
Output:
false
Example 2:

Input:
map = 
[[0,0,1,0,0],
 [0,0,0,0,0],
 [0,0,0,1,0],
 [1,1,0,1,1],
 [0,0,0,0,0]
]
start = [0,4]
end = [4,4]
Output:
true

*/

int dx[]={0,1,-1,0};
int dy[]={1,0,0,-1};
class Solution {
public:
    
    bool hasPath(vector<vector<int>> &arr, vector<int> &start, vector<int> &destination) {
        int n=arr.size(),m=arr[0].size();
        vector<vector<bool> > visited(n,vector<bool> (m,0));
        queue<pair<int,int> > q;
        q.push({start[0],start[1]});
        visited[start[0]][start[1]]=1;
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            if(curr.first==destination[0] && curr.second==destination[1]){
                return true;
            }
            for(int k=0;k<4;k++){
                int x=curr.first+dx[k];
                int y=curr.second+dy[k];
                while(x>=0 && y>=0 && x<n && y<m && arr[x][y]==0){
                    x=x+dx[k];
                    y=y+dy[k];
                }
                x-=dx[k]; // backtracking as we have either reached the wall or a boundary
                y-=dy[k];
                if(!visited[x][y]){
                    visited[x][y]=1;
                    q.push({x,y});
                }
            }
        }
        return false;
    }
};


