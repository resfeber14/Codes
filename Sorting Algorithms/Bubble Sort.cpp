#include <bits/stdc++.h> 
#include<map>
using namespace std;

void bubble_sort(int n,vector<int> &v){
	// if list is already sorted then there would not be any swaps.So,for that use flag
    // if list is already sorted,Time complexity: O(k*(n-1))  Best case
    // Average: O(N*N)
    // Worst: O(N*N)
    // Inplace,Stable
	for(int i=1;i<n-1;i++){
		bool flag=false;
		for(int j=0;j<n-i;j++){
			if(v[j]>v[j+1]){
				flag=true;
				swap(v[j+1],v[j]);
			}
		}
		if(!flag){
			break;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
    	cin>>v[i];
    }
    bubble_sort(n,v);
    for(int i=0;i<n;i++){
    	cout<<v[i]<<" ";
    }
    return 0;
}
