#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
          int m = tasks.size();
        unordered_map<char,int> mp;
        for(auto el : tasks){
            mp[el]++;
        } 
        priority_queue<int> h;
        for(auto el:mp){
            h.push(el.second);
       }
       int k=h.top();
       int sum=0;
       for(auto el :mp){
        if(el.second==k) sum+=1;
       }
       return max(m,((k-1)*(n+1)+sum));
    }
};