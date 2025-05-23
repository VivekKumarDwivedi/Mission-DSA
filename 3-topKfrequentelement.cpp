#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int el : nums) {
            m[el]++;
        }

        // Move map contents to a vector of pairs
        vector<pair<int, int>> freq(m.begin(), m.end());

        // Sort the vector based on frequency in descending order
        sort(freq.begin(), freq.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.second > b.second;
        });

        // Collect the top K frequent elements
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(freq[i].first);
        }

        return res;
    }
};