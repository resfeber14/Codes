
// Problem Link:  https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/

// You just have to find shortest path to bottom-right corner from top-left corner.
// Think each cell of a matrix as a node in graph and suppose if at any cell (x,y) character U is given and you go right i.e to cell (x,y+1) 
// then dist[(x,y+1)]=dist[(x,y)]+1 or if you go up to cell (x-1,y) then dist[(x-1,y)=dist[(x,y)]

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
class Solution {
public:
    int dfs(vector<vector<int> > &arr,int n,int m){
    priority_queue <pair<int,pair<int,int> >, vector<pair<int,pair<int,int> > >, greater<pair<int,pair<int,int> >> >pq;
    int dist[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dist[i][j]=INT_MAX;
        }
    }
    pq.push({0,{0,0}});
    dist[0][0]=0;
    while(!pq.empty()){
        int i= pq.top().second.first,j=pq.top().second.second, w=pq.top().first;
        pq.pop();
        int x1,x2;
        if(arr[i][j]==1){
            x1=i,x2=j+1;
        }
        else if(arr[i][j]==2){
            x1=i,x2=j-1;
        }
        else if(arr[i][j]==4){
            x1=i-1,x2=j;
        }
        else{
            x1=i+1,x2=j;
        }
        for(int k=0;k<4;k++){
            int x= i+dx[k],y=j+dy[k];
            if(x>=0 && x<n && y>=0 && y<m){
                if(x==x1 && y==x2 && dist[x][y]>w){
                    dist[x][y]=w;
                    pq.push({dist[x][y],{x,y}});
                }
                else if(dist[x][y]>1+w){
                    dist[x][y]=1+w;
                    pq.push({dist[x][y],{x,y}});
                }
            }
        }
    }
    return dist[n-1][m-1];
}
    int minCost(vector<vector<int>>& arr) {
        int n=arr.size(),m=arr[0].size();
        return dfs(arr,n,m);
    }
};

// Problem Link: https://www.interviewbit.com/problems/min-cost-path/


int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int dfs(vector<string> &arr,int n,int m){
    priority_queue <pair<int,pair<int,int> >, vector<pair<int,pair<int,int> > >, greater<pair<int,pair<int,int> >> >pq;
    int dist[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dist[i][j]=INT_MAX;
        }
    }
    pq.push({0,{0,0}});
    dist[0][0]=0;
    while(!pq.empty()){
        int i= pq.top().second.first,j=pq.top().second.second, w=pq.top().first;
        pq.pop();
        int x1,x2;
        if(arr[i][j]=='R'){
            x1=i,x2=j+1;
        }
        else if(arr[i][j]=='L'){
            x1=i,x2=j-1;
        }
        else if(arr[i][j]=='U'){
            x1=i-1,x2=j;
        }
        else{
            x1=i+1,x2=j;
        }
        for(int k=0;k<4;k++){
            int x= i+dx[k],y=j+dy[k];
            if(x>=0 && x<n && y>=0 && y<m){
                if(x==x1 && y==x2 && dist[x][y]>w){
                    dist[x][y]=w;
                    pq.push({dist[x][y],{x,y}});
                }
                else if(dist[x][y]>1+w){
                    dist[x][y]=1+w;
                    pq.push({dist[x][y],{x,y}});
                }
            }
        }
    }
    return dist[n-1][m-1];
}
int Solution::solve(int n, int m, vector<string> &arr) {
    return dfs(arr,n,m);
}
