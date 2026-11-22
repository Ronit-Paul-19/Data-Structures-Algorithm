#include <bits/stdc++.h>
#include <climits>
using namespace std;

// BRUTE FORCE
int secondLargestElement_BRUTE(vector<int> &nums) { // O(n + n log (n))
  int n = nums.size();

  // we can only find the second largest if there are more than 2 elements in
  // the array
  if (n < 2) {
    return -1;
  }

  vector<int> sortedNums = nums;
  // sort the array
  sort(sortedNums.begin(), sortedNums.end()); // O(n log (n))

  // clearly largest element will be the last i.e. the (n-1)th element
  int largest = sortedNums[n - 1];

  // return the element greater than largest
  for (int index = n - 2; index >= 0; index--) { // O(n)
    if (sortedNums[index] < largest) {
      return sortedNums[index];
    }
  }

  return -1; // second largest does not exists
}

// BETTER
int secondLargestElement_BETTER(vector<int> &nums) { // O(2n) = O(n)
  int largest = INT_MIN;
  int sLargest = INT_MIN;

  // first pass :- find out the largest element
  for (int i = 0; i < nums.size(); i++) { // O(n)
    if (nums[i] > largest) {
      largest = nums[i];
    }
  }

  // second pass :- find our the second largest element
  for (int i = 0; i < nums.size(); i++) { // O(n)
    if (nums[i] != largest && nums[i] > sLargest) {
      sLargest = nums[i];
    }
  }

  return sLargest;
}

// OPTIMAL
int secondLargestElement_OPTIMAL(vector<int> &nums) {
  int largest = INT_MIN;
  int sLargest = INT_MIN;

  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] > largest) {
      sLargest = largest;
      largest = nums[i];
    } else if (nums[i] < largest && nums[i] > sLargest) {
      sLargest = nums[i];
    }
  }

  return sLargest;
}

int main() {
  vector<int> nums = {8, 7, 5, 3, 6};

  cout << secondLargestElement_BRUTE(nums) << endl;
  cout << secondLargestElement_BETTER(nums) << endl;
  cout << secondLargestElement_OPTIMAL(nums) << endl;

  return 0;
}
