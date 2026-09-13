#include <bits/stdc++.h>
using namespace std;

// 1. Brute Force
// "I'll start with the brute-force approach. I can rotate the array one position to the right, k times."
// For one rotation:
// [1,2,3,4,5]
//           ↓
// [5,1,2,3,4]
// So I repeat this k times.

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n;

    while (k--) {
        int last = nums[n - 1];

        for (int i = n - 1; i > 0; i--) {
            nums[i] = nums[i - 1];
        }

        nums[0] = last;
    }
}
// Trade-off
// "The problem is that for every rotation I'm shifting almost the entire array, so this becomes expensive when k is large."
// Time: O(n × k)
// Space: O(1)
// "We can improve the time by avoiding these repeated shifts."

// 2. Better Approach
// "Instead of rotating one position at a time, I can directly construct the rotated array. After rotating right by k, an element at index i moves to (i + k) % n."
// So I can use an extra array:

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n;

    vector<int> temp(n);

    for (int i = 0; i < n; i++) {
        temp[(i + k) % n] = nums[i];
    }

    nums = temp;
}
// Trade-off
// "This reduces the time to linear, but I'm using an extra array of size n, so the space complexity becomes O(n)."
// Time: O(n)
// Space: O(n)
// "We can achieve the same O(n) time while removing the extra space."

// 3. Optimal Approach — Reversal Algorithm
// "The optimal approach is to use the reversal technique. The idea is to reverse specific portions of the array instead of moving elements individually."

// For:

// [1,2,3,4,5,6,7]
// k = 3
// Step 1: Reverse the entire array
// [7,6,5,4,3,2,1]
// Step 2: Reverse the first k elements
// [5,6,7,4,3,2,1]
// Step 3: Reverse the remaining elements
// [5,6,7,1,2,3,4]

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n;

    reverse(nums.begin(), nums.end());

    reverse(nums.begin(), nums.begin() + k);

    reverse(nums.begin() + k, nums.end());
}
// Trade-off

// "This gives us linear time like the better approach, but unlike the better approach, we don't need an extra array. We modify the input array in-place."

// Time: O(n)
// Space: O(1)

// "This is optimal because we need at least O(n) time to process the array, and we're achieving that with constant extra space."