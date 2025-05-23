#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        // Step 1: Create the prefix sum array
        vector<long long> prefix(n + 1, 0); // Long long to handle large sums
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        // Step 2: Use a deque to find the shortest subarray
        deque<int> deq;
        int result = INT_MAX;

        for (int j = 0; j <= n; ++j) {
            // Step 3: Find subarray with sum >= k
            while (!deq.empty() && prefix[j] - prefix[deq.front()] >= k) {
                result = min(result, j - deq.front());
                deq.pop_front(); // Remove the front as it's used for a valid
                                 // subarray
            }

            // Step 4: Maintain deque in increasing order of prefix sum
            while (!deq.empty() && prefix[j] <= prefix[deq.back()]) {
                deq.pop_back();
            }

            // Step 5: Add the current index to the deque
            deq.push_back(j);
        }

        // Step 6: Return result, or -1 if no subarray found
        return result == INT_MAX ? -1 : result;
    }
};