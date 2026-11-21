// Given an array of integers nums, return the value of the largest element in the array
#include <iostream>
#include <vector>

using namespace std;

int largestElement(vector<int>& nums) {
  int largest = INT_MIN;

  for (auto element : nums) {
    if (element > largest) {
      largest = element;
    }
  }

  return largest;
}

int main() {
  vector<int> nums = {1, 5, 2, 7, 4, 3};

  cout << largestElement(nums);
  
  return 0;
}
