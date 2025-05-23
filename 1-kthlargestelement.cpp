#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto el : nums){
            pq.push(el);
        }
        int t=k-1;
        while(t){
            pq.pop();
            t--;
        }
       return pq.top();
    }
};