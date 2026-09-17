#include <bits/stdc++.h>
using namespace std;

// 1. Brute Force — Extra Array
// Intuition
// Create a temporary array.
// First put all non-zero elements into it.
// Then put all required zeroes at the end.
// Copy the result back to nums.

void moveZeroes(vector<int> &nums)
{
  vector<int> temp;

  for (int x : nums)
  {
    if (x != 0)
      temp.push_back(x);
  }

  while (temp.size() < nums.size())
    temp.push_back(0);

  nums = temp;
}

// Complexity
// Time: O(n)
// Space: O(n)

// Why not optimal?
// The problem specifically asks us to modify the array in-place, so O(n) extra space is avoidable.

// =================================================================================================

// 2. Optimal — Two Pointers
// Intuition

// We don't actually need to shift elements repeatedly.

// i traverses the array.
// j stores the position where the next non-zero element should be placed.
// Whenever nums[i] != 0, swap nums[i] with nums[j].
// Increment j.

// Because we process elements from left to right, the relative order of non-zero elements is maintained.

void moveZeroes(vector<int> &nums)
{
  int j = 0;

  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i] != 0)
    {
      swap(nums[i], nums[j]);
      j++;
    }
  }
}

// Complexity
// Time : O(n)
// Space : O(1)