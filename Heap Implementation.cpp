

#include <bits/stdc++.h> 
#include<map>
using namespace std;
#define ll long long int
#define pb push_back
#define mod 1000000007
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ppi pair<int,int>
#define ppl pair<long long int,long long int>
#define f first
#define s second

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

class Heap{
	vector<int> v;
	bool isMinHeap;
	bool compare(int val1,int val2){
		if(isMinHeap){
			return val1<val2;
		}
		else{
			return val1>val2;
		}
		
	}
  
  // Heapify: Bringing back to the original form
	void heapify(int i){
		int left=2*i;
		int right=2*i+1;
		// Assume current is min
		int minIndex=i;
		if(left<v.size() && compare(v[left],v[i])){
			minIndex=left;
		}
		if(right<v.size() && compare(v[right],v[minIndex])){
			minIndex=right;
		}
		// If we need to swap,then swap first ,then call the recursive function
		if(minIndex!=i){
			swap(v[i],v[minIndex]);
			heapify(minIndex);
		}
	}
	public:
		Heap(bool type=true){
			isMinHeap=type;
			v.push_back(-1);
		}
  
  //Push Operation
		void push(int val){
			v.push_back(val); // Insert at the last
			// Take the element to the correct position restore the heap property
			int index=v.size()-1;
			int parent=index/2;
			
			while(index>1 && compare(v[index],v[parent])){
				swap(v[index],v[parent]);
				index=parent;
				parent=parent/2;
			}
		}
  
  // Pop Operation:
		void pop(){
			// Remove the topmost element
			if(v.size()==1){
				return;
			}
			int ind=v.size()-1;
			swap(v[ind],v[1]); // swap the first with the last index,as we want to delete the element with index 1
			v.pop_back();
			heapify(1);
		}
		
  // checks if the heap is empty
		bool empty(){
			return v.size()==1;
		}
		int top(){
			return v[1];
		}
};

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Heap h(true);
    h.push(5);
    h.push(15);
    h.push(2);
    h.push(20);
    h.push(3);
   // cout<<h.top();
   while(!h.empty()){
   		cout<<h.top()<<" ";
   		h.pop();
   }
    return 0;
}
