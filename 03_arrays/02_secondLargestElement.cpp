#include <bits/stdc++.h>
using namespace std;

int secondLargestElement_BRUTE(vector<int> &nums) {
  int n = nums.size();

  if (n < 2) {
    return -1;
  }

  vector<int> sortedNums = nums;
  sort(sortedNums.begin(), sortedNums.end());

  int largest = sortedNums[n - 1];

  for (int index = n - 2; index >= 0; index--) {
    if (sortedNums[index] < largest) {
      return sortedNums[index];
    }
  }

  return -1;
}

int main() {
  vector<int> nums = {8, 7, 5, 3, 6};

  cout << secondLargestElement_BRUTE(nums) << endl;

  return 0;
}
