// Problem Link: https://leetcode.com/problems/asteroid-collision/

// Here we are checking popping only if the s.top()>0 && arr[i]<0

vector<int> asteroidCollision(vector<int>& arr) {
        stack<int> s;
        for(int i=0;i<arr.size();i++){
            if(s.empty())
                s.push(arr[i]);
            else if(s.top()>0 && arr[i]<0){
                bool flag=false;
                while(!s.empty()){
                    if(s.top()>0 && arr[i]<0){ // If the two are approaching each other,then only any collision will occur. Then only any operation will be performed
                        if(s.top()>abs(arr[i])){  // It means the arr[i] asteroid will collapse,since it is smaller
                            flag=false;
                            break;
                        }
                        else if(s.top()<abs(arr[i])){ // It means the size of current asteroid is more .So the s.top() asteroid will collapse
                            flag=true;
                            s.pop();
                        }
                        else{  // It means they are of same size
                            flag=false;
                            s.pop();
                            break;
                        }
                    }
                    else
                        break;
                }
                if(flag)
                    s.push(arr[i]);
            }
            else{
                s.push(arr[i]);
            }
        }
        vector<int> v;
        while(!s.empty()){
            v.push_back(s.top());
            s.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
