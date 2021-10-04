/*

Problem Statement

Let there be N workers and N jobs. Any worker can be assigned to perform any job, incurring some cost that may vary depending on the work-job assignment. It is required to perform all jobs by assigning exactly one worker to each job and exactly one job to each agent in such a way that the total cost of the assignment is minimized.

Input Format
Number of workers and job: N
Cost matrix C with dimension N*N where C(i,j) is the cost incurred on assigning ith Person to jth Job.

Sample Input
4

[
9 2 7 8
6 4 3 7
5 8 1 8
7 6 9 4
]

Sample Output
13

Constraints
N <= 20

*/

int dp[21][1<<21];

int solve(int i,int mask,int n,vector<vector<int> > &arr){
	if(i==n) // all jobs have been assigned
		return 0;
	if(dp[i][mask]!=-1)  
		return dp[i][mask];
	int ans=INT_MAX;
	for(int j=0;j<n;j++){  // traversing over the labourers
		if((1<<j) & mask){
			ans=min(ans,arr[j][i]+solve(i+1,mask^(1<<j),n,arr)); // turning off the jth bit
		}
	}
	return dp[i][mask]= ans;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  	memset(dp,-1,sizeof(dp));
  	int n;
  	cin>>n;
  	vector<vector<int> > arr(n,vector<int> (n,-1));
  	for(int i=0;i<n;i++){
  		for(int j=0;j<n;j++){
  			int x;
  			cin>>x;
  			arr[i][j]=x;
  		}
  	}
  	cout<<solve(0,(1<<n)-1,n,arr); // We are representing the availability men as mask
  	// if the jth bit of mask is ON ,it means ith man has not been assigned any job
    return 0;
}
