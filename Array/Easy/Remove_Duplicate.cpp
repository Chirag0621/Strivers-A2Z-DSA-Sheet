#include <bits/stdc++.h>
using namespace std;

// 1. Brute Force
// "Since the array is sorted, I can use an extra data structure like a set to store only unique elements."

int removeDuplicates(vector<int> &nums)
{
  set<int> st;

  for (int x : nums)
  {
    st.insert(x);
  }

  int i = 0;
  for (int x : st)
  {
    nums[i++] = x;
  }

  return i;
}

// Trade - off : Very simple, but set
//   requires extra
// space and each insertion takes O(log n).

// Time : O(n log n)
// Space : O(n)

//"But because the array is already sorted, we don't actually need a set."

// 2. Better Approach

// We can use an unordered_set.

int removeDuplicates(vector<int> &nums)
{
  unordered_set<int> st;

  for (int x : nums)
  {
    st.insert(x);
  }

  int i = 0;

  for (int x : st)
  {
    nums[i++] = x;
  }

  return i;
}

// Trade - off : Average insertion is O(1), so we improve the time, but we still use O(n)
// extra space.Also, because unordered_set doesn't preserve order, this is not appropriate if we need to maintain sorted order.

// Average Time : O(n)
//  Space : O(n)

//"Since the input is sorted, we can do even better by taking advantage of that property."

// 3. Optimal — Two Pointers
// "Because duplicates are adjacent in a sorted array, I can maintain one pointer i at the position of the last unique element. Then I use another pointer j to scan the array."

// Whenever :nums[j] != nums[i]
//  we have found a new unique element,
// so :i++;
//  nums[i] = nums[j];
//  Code
int removeDuplicates(vector<int> &nums)
{
  int i = 0;

  for (int j = 1; j < nums.size(); j++)
  {
    if (nums[j] != nums[i])
    {
      i++;
      nums[i] = nums[j];
    }
  }

  return i + 1;
}

int main()
{
  vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5};
  int newLength = removeDuplicates(nums);
  cout << "New length: " << newLength << endl;
  cout << "Array after removing duplicates: ";
  for (int i = 0; i < newLength; i++)
  {
    cout << nums[i] << " ";
  }
  cout << endl;
  return 0;
}

// Complexity
//  Time: O(n)
//  Space: O(1)

// "This is optimal because I only traverse the array once and modify it in-place without using any extra data structure."