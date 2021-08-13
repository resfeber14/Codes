// Problem Link:  https://practice.geeksforgeeks.org/problems/maximum-difference-of-zeros-and-ones-in-binary-string4111/1

// Modification of Kadane
// Convert all 0s to 1 and all 1s to -1.Then find maximum subarray sum


int maxSubstring(string s)
	{
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
