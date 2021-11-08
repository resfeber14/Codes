/*
Problem Link:  https://leetcode.com/problems/repeated-dna-sequences/
Slide over every window of 10 and store that frequency of every such substring in a map

Time Complexity: O(N) Space Complexity: O(N)
*/

vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> m;
        vector<string> v;
        int n=s.length();
        if(n<=10)
            return v;
        string curr="";
        for(int i=0;i<10;i++){
            curr+=s[i];
        }
        m[curr]++;
        for(int i=10;i<n;i++){
            curr.erase(curr.begin());
            curr+=s[i];
            m[curr]++;
        }
        for(auto it:m){
            if(it.second>1){
                v.push_back(it.first);
            }
        }
        return v;
    }
