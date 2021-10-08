/*
Problem Link:  https://leetcode.com/problems/number-of-visible-people-in-a-queue/

*/

vector<int> canSeePersonsCount(vector<int>& arr) {
        stack<int> s;
         vector<int> v;
        for(int i=arr.size()-1;i>=0;i--){
            if(s.empty()){
                v.push_back(0);
            }
            else{
                if(arr[s.top()]<arr[i]){
                    int cnt=0;
                    while(!s.empty() && arr[s.top()]<arr[i]){
                        s.pop();
                        cnt++;
                    }
                    if(s.size())
                        v.push_back(1+cnt);
                    else
                        v.push_back(cnt);
                }
                else{
                    if(arr[s.top()]>=arr[i]){
                        v.push_back(1);
                    }
                }
            }
            s.push(i);
        }
        reverse(v.begin(),v.end());
        return v;
    }
