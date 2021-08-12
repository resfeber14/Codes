// Problem Link:   https://practice.geeksforgeeks.org/problems/coin-change2448/1#   
// Here Order doesn't matter

// Recurrence: solve(n,i)   =   solve(n-arr[i],i)+solve(n,i-1)           if(arr[i]<=n) 
//             solve(n,i)   =    solve(n,i-1)                            if(arr[i]>n) 


// Top Down:
// Kind of inclusion Exclusion
long long int solve(int n,int i,int arr[],vector<vector<long long int> > &dp){
        if(n==0){
            return dp[n][i]=1;
        }
        
        if(i<0){
            return 0;
        }
        if(dp[n][i]!=-1){
            return dp[n][i];
        }
        
        
        if(arr[i]<=n){
            dp[n][i]=solve(n-arr[i],i,arr,dp)+solve(n,i-1,arr,dp);
        }
        else{
            dp[n][i]=solve(n,i-1,arr,dp);
        }
        return dp[n][i];
    }
    long long int count( int arr[], int m, int n ){
        vector<vector<long long int> > dp(n+1,vector<long long int> (m,-1));
        return solve(n,m-1,arr,dp);
    }


// Bottom Up:

long long int count( int arr[], int m, int n ){
       long long int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=0;i<m;i++){
            for(int j=1;j<=n;j++){
                if(j>=arr[i]){
                    dp[j]=(dp[j]+dp[j-arr[i]]);
                }
            }
        }
        return dp[n];
    }



// Problem Link:   https://leetcode.com/problems/coin-change/

// minCoins(coins[0..m-1], V) = min {1 + minCoins(V-coins[i])} where i varies from 0 to m-1 and coin[i] <= V

int solve(int k,int n,vector<int> &dp,vector<int> &arr){
        if(k==0)
            return 0;
        if(dp[k]!=-1)
            return dp[k];
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            if(arr[i]<=k){
                int x=solve(k-arr[i],n,dp,arr);
                if(x!=INT_MAX && x+1<ans){
                    ans=x+1;
                }
            }
        }
        return dp[k]=ans;
    }
    int coinChange(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(k+1,-1);
        int p= solve(k,n,dp,arr);
        if(p==INT_MAX)
            return -1;
        return p;
    }

// Problem Link:  https://cses.fi/problemset/task/1635/
//Order matters
// Recurrence: sigma(solve(k-arr[i]))   0<i<n && arr[i]<=k

ll solve(ll k,ll arr[],ll dp[],ll n){
	if(k==0){
		return 1;
	}
	if(dp[k]!=-1){
		return dp[k];
	}
	ll ans=0;
	for(int i=0;i<n;i++){
		if(k>=arr[i]){
			ll x=solve(k-arr[i],arr,dp,n);
			if(x!=-1){
				ans= ((ans)%mod + x%mod)%mod;
			}
		}
	}
	if(ans!=0)
		dp[k]=(ans)%mod;
	return dp[k];
}


int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k;
    cin>>n>>k;
    ll arr[n];
    forn(i,n){
    	cin>>arr[i];
    }
    ll dp[k+1];
    memset(dp,-1,sizeof(dp));
    
    ll p=solve(k,arr,dp,n);
    if(p==-1)
    	cout<<"0\n";
    else
    cout<<p<<"\n";
    return 0;
}









