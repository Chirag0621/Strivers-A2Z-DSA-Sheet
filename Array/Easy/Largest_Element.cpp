#include <bits/stdc++.h>
using namespace std;
int largest(vector<int> &arr)
{
  int largest = arr[0];
  for (int i = 1; i < arr.size(); i++)
  {
    largest = max(largest, arr[i]);
  }
  return largest;
}
int main()
{
  vector<int> arr = {1, 2, 3, 4, 5};
  cout << largest(arr) << endl;
  return 0;
}
// Time Complexity: O(n)
// Space Complexity: O(1)
//NOTE: O(n) is the best time complexity for this problem as we have to traverse the entire array to find the largest element, because the vector is unsorted.