#include <bits/stdc++.h>
using namespace std;


// Brute Force Approach
// In this approach, we will use a set to store the unique elements from both arrays. We will iterate through both arrays and insert each element into the set. Since sets automatically handle duplicates, we will end up with a collection of unique elements. Finally, we will convert the set back into a vector and return it as the result.

//==================================================================================================
// Set is a data structure that stores unique elements in sorted order. When we insert elements into a set, it automatically handles duplicates and maintains the order of the elements.

// The time taken by set to perform insertion, deletion, and search operations is O(log n), where n is the number of elements in the set. This is because sets are typically implemented as balanced binary search trees, which allow for efficient operations. Therefore, when we insert elements into a set, it takes logarithmic time to find the appropriate position for each element and maintain the sorted order. As a result, the overall time complexity of this approach is O((n + m) log (n + m)), where n and m are the sizes of the two input arrays.

// ===================================================================================================

vector<int> findUnion(vector<int> &a, vector<int> &b)
{
  // code here
  set<int> st;
  for (auto it : a)
  {
    st.insert(it);
  }
  for (auto it : b)
  {
    st.insert(it);
  }
  vector<int> ans;
  for (auto it : st)
  {
    ans.push_back(it);
  }

  return ans;
}

// T.C: O((N + M) log(N + M))
// S.C: O(N + M)

//====================================================================================================

// 2. Optimal Approach
vector<int> findUnion(vector<int>& a,  vector<int>& b) {
    vector<int> res; 
    int n = a.size();
    int m = b.size();
  
    
    int i = 0, j = 0;    
    while(i < n && j < m) {
      
       
        if(i > 0 && a[i - 1] == a[i]) {
            i++;
            continue;
        }
      
      	if(j > 0 && b[j - 1] == b[j]) {
          	j++;
          	continue;
        }
      	
      	
        if(a[i] < b[j]) {
          	res.push_back(a[i]);
            i++;
        }
        else if(a[i] > b[j]) {
          	res.push_back(b[j]);
            j++;
        }
      
        
        else {
            res.push_back(a[i]);
            i++;
            j++;
        }
    }
  	
  	
  	while (i < n) {
      	
      	
      	if(i > 0 && a[i - 1] == a[i]) {
            i++;
            continue;
        }
      	res.push_back(a[i]);
      	i++;
    }
  
  	
  	while (j < m) {
      
      	
      	if(j > 0 && b[j - 1] == b[j]) {
            j++;
            continue;
        }
      	res.push_back(b[j]);
      	j++;
    }
    return res; 
}



