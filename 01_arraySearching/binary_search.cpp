#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int> &arr, int target) {
  int left = 0;
  int right = static_cast<int>(arr.size()) - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (arr[mid] == target) {
      return mid;
    }
    if (arr[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return -1;
}

int main() {
  cout << "Enter number of elements: ";
  int n;
  cin >> n;

  cout << "Enter " << n << " elements: ";
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cout << "Enter element to search: ";
  int target;
  cin >> target;
  cout << '\n';

  int index = binarySearch(arr, target);
  if (index != -1) {
    cout << "Element found at index " << index << endl;
  } else {
    cout << "Element not found" << endl;
  }

  return 0;
}
