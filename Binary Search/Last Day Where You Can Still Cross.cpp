// Problem Link: https://leetcode.com/problems/last-day-where-you-can-still-cross/
// Time complexity: row*col* O(row*col)

//Here binary search will be applied coz there will be a day k 1.....row*col after which we can't traverse from top to bottom 
// So we will 1.....row*col take mid check if that day we can go from top to bottom or not.If yes then l=mid+1 else r=mid-1

#define ppi pair<int,int>
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
class Solution {
public:
    bool check(int n,int m,int mid,vector<vector<int> > &v){
        int arr[n][m];
        memset(arr,0,sizeof(arr));
        vector<vector<bool> > visited(n,vector<bool> (m,0));
        for(int i=0;i<mid;i++){
            int x=v[i][0],y=v[i][1];
            x--,y--;
            arr[x][y]=-1;
        }
        queue<ppi> q;
        for(int i=0;i<m;i++){
            if(arr[0][i]==0){
                if(q.empty())
                    visited[0][i]=1;
                q.push({0,i});
            }
        }
        
        while(!q.empty()){
            ppi curr=q.front();
            int x=curr.first,y=curr.second;
            if(x==n-1){
                return true;
            }
            q.pop();
            for(int i=0;i<4;i++){
                int xx=x+dx[i],yy=y+dy[i];
                if(xx>=0 && yy>=0 && xx<n && yy<m && !visited[xx][yy] && arr[xx][yy]!=-1){
                    q.push({xx,yy});
                    visited[xx][yy]=1;
                }
            }
        }
        return false;
    }
    int bin_search(int row,int col,int n,vector<vector<int> > &v){
        int ans=0;
        int l=1,r=n;
        while(l<=r){
            int mid=(l+r)>>1;
            if(check(row,col,mid,v)){
                ans=mid;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        return ans;
        
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& v) {
        int x=bin_search(row,col,row*col,v);
        return x;
    }
};

