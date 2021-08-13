// Convert to Kadane

int maxSubstring(string s)
	{
	    // Your code goes here
	    int n=s.length();
	    int curr=0,ans=INT_MIN;
	    for(int i=0;i<n;i++){
	        int temp=0;
	        if(s[i]=='1'){
	            temp= -1;
	        }
	        else{
	            temp=1;
	        }
	        if(temp+curr>temp){
	            curr=temp+curr;
	        }
	        else{
	            curr=temp;
	        }
	        ans=max(ans,curr);
	    }
	    return ans;
	}
