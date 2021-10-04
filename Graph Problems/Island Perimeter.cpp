/* Problem Link: https://leetcode.com/problems/island-perimeter/
Here we will have one side only we jump into a cell which has arr[i][j]==0 or we jump to any invalid cell

*/

int dfs(int i,int j,int n,int m,vector<vector<bool> > &visited,vector<vector<int> > &arr){
        if(i>=n || i<0 || j>=m || j<0 )
            return 1;
        if(arr[i][j]==0)
            return 1;
        visited[i][j]=1;
        int cnt=0;
        for(int k=0;k<4;k++){
            int x=i+dx[k],y=j+dy[k];
            if(x>=0 && y>=0 && x<n && y<m && visited[x][y])  // Here we are saving ourselves from falling into the infinite loop
                continue;
            cnt+= dfs(x,y,n,m,visited,arr);
        }
        return cnt;
    }
    int islandPerimeter(vector<vector<int>>& arr) {
        int n=arr.size(),m=arr[0].size();
        int ans=0;
        vector<vector<bool> > visited(n,vector<bool> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j] && !visited[i][j])
                    ans+=dfs(i,j,n,m,visited,arr);
            }
        }
        return ans;
    }
