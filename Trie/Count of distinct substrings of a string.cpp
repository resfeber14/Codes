

/*
 Problem Link: https://practice.geeksforgeeks.org/problems/count-of-distinct-substrings/1#

Given a string of length n of lowercase alphabet characters, we need to count total number of distinct substrings of this string.
Examples:

Input  : str = “ababa”
Output : 10
Total number of distinct substring are 10, which are,
"", "a", "b", "ab", "ba", "aba", "bab", "abab", "baba"
and "ababa"


*/

struct Node{
	Node* arr[26];
	bool flag=false;
	
	
};

int countDistinctSubstring(string s)
{
    //Your code here
    int n=s.size();
    int cnt=0;
    Node* root=new Node();
    for(int i=0;i<n;i++){
        Node* temp=root;
        for(int j=i;j<n;j++){
            if(temp->arr[s[j]-'a']==NULL){
                Node* newNode=new Node();
                temp->arr[s[j]-'a']=newNode;
                temp->flag=true;
                cnt++;
            }
            temp=temp->arr[s[j]-'a'];
        }
    }
    return cnt+1;
    
}
