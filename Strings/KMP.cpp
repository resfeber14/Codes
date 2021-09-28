// Naive Approach
// Time Complexity:O(N*M) Space Complexity: O(1)
void naive(){
  	string txt,pat;
  	cin>>txt>>pat;
  	int n=txt.length(), m=pat.length();
  	// Naive Approach
  	for(int i=0;i<=n-m;i++){
  		int k=i,j=0;
  		for(j=0;j<m;j++){
  			if(txt[k]!=pat[j]){
  				break;
  			}
  			else{
  				k++;
  			}
  		}
  		if(j==m){
  			cout<<"Naive Approach: Pattern found at "<<k-m<<"\n";
  		}
  	}
}
  	
/*
    KMP: Knuth-Morris-Pratt Algorithm
  	LPS -> Longest Prefix Suffix  
  	It is the longest prefix (0....i) of the array which is also a suffix(...j)
  	
  	Proper prefix: Prefix of a string which starts from the 0th index but is not equal to the string
  	Suffix:  Any substring which is in the end of the string
  	LPS value can atmost increase to 1 if we move by 1
	Time Complexity:O(N+M) Space Complexity:O(M)
	  LPS ARRAY formation:
*/

	int lps[m]={};
	int j=0;
	for(int i=1;i<m;i++){
		while(j && pat[i]!=pat[j]){
			j=lps[j-1];
		}
		if(pat[i]==pat[j]){
			j++;
			lps[i]=j;
		}
		
	}
  	for(int i=0;i<m;i++){
  		cout<<lps[i]<<" ";
  	}
  	cout<<"\n";
  	int i=0;
  	j=0;
  	// KMP
  	while(i<n){
  		if(txt[i]==pat[j]){
  			j++;
  			i++;
  		}
  		if(j==m){
  			cout<<"Pattern found at "<<i-j<<"\n";
  			j=lps[j-1];
  		}
  		else if(i<n && pat[j]!=txt[i]){
  			if(j!=0){
  				j=lps[j-1];
  			}
  			else
  				i++;
  		}
  	}
    return 0;
}
