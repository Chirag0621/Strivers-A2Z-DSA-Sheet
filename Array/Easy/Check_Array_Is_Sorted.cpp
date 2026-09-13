#include <bits/stdc++.h>
using namespace std;
// Brute Force Approach: Sort the array and check if it is sorted or not.
//  bool isSorted(vector<int>& arr) {
//      for (int i = 1; i < arr.size(); i++) {
//          if (arr[i] < arr[i - 1]) {
//              return false;
//          }
//      }

//     return true;
// }

// bool check(vector<int>& nums) {
//     int n = nums.size();

//     for (int k = 0; k < n; k++) {

//         vector<int> rotated;

//         for (int i = 0; i < n; i++) {
//             rotated.push_back(nums[(k + i) % n]);
//         }

//         if (isSorted(rotated)) {
//             return true;
//         }
//     }

//     return false;
// }

// Time Complexity: O(n^2)
// Space Complexity: O(n)

// Better
// The brute-force approach is doing unnecessary work because I'm actually creating every rotation. Instead, I can try to identify a property that every sorted-and-rotated array has.




// Optimal Approach: Traverse the array and count the number of times the current element is greater than the next element. If this count is more than 1, then the array is not sorted and rotated. Otherwise, it is sorted and rotated.
bool check(vector<int> &nums)
{
  int cnt = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i] > nums[(i + 1) % nums.size()])
      cnt++;
  }
  return cnt <= 1;
}

// Time Complexity: O(n)
// Space Complexity: O(1)