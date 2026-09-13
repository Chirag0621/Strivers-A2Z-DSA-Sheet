#include <bits/stdc++.h>
using namespace std;
int getSecondLargest(vector<int> &arr)
{
  // Brute Force Approach: Sort the array and return the second last element.
  //--- code ---
  // sort(arr.begin(), arr.end());
  // return arr[arr.size() - 2];
  // Time Complexity: O(nlogn)
  // Space Complexity: O(1)

  // Optimal Approach: Traverse the array and keep track of the largest and second largest elements.
  // For every element x:
  // If x > largest:
  // The current largest becomes the second largest.
  // x becomes the new largest.
  // Otherwise, if x is smaller than largest but greater than secondLargest:
  // Update secondLargest.
  
  int largest = arr[0];
  int secondLargest = -1;
  for (int i = 1; i < arr.size(); i++)
  {
    if (arr[i] > largest)
    {
      secondLargest = largest;
      largest = arr[i];
    }
    else if (arr[i] < largest && arr[i] > secondLargest)
    {
      secondLargest = arr[i];
    }
  }
  return secondLargest;
}
int main()
{
  vector<int> arr = {1, 2, 3, 4, 5};
  cout << getSecondLargest(arr) << endl;
  return 0;
}

// Time Complexity: O(n)
//Space Complexity: O(1)
