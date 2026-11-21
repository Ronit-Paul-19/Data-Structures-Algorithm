#include <iostream>
#include <vector>
using namespace std;

int linearSearch(const vector<int> &arr, int target) {
  for (int i = 0; i < static_cast<int>(arr.size()); i++) {
    if (arr[i] == target) {
      return i;
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

  int index = linearSearch(arr, target);
  if (index != -1) {
    cout << "Element found at index " << index << endl;
  } else {
    cout << "Element not found" << endl;
  }

  return 0;
}
