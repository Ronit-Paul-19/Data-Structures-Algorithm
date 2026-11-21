#include <iostream>
#include <vector>
using namespace std;

int partitionRange(vector<int> &arr, int low, int high) {
  int mid = low + (high - low) / 2;
  swap(arr[mid], arr[high]);

  int pivot = arr[high];
  int i = low;

  for (int j = low; j < high; j++) {
    if (arr[j] < pivot) {
      swap(arr[i], arr[j]);
      i++;
    }
  }

  swap(arr[i], arr[high]);
  return i;
}

void quickSort(vector<int> &arr, int low, int high) {
  if (low >= high) {
    return;
  }

  int pivotIndex = partitionRange(arr, low, high);
  quickSort(arr, low, pivotIndex - 1);
  quickSort(arr, pivotIndex + 1, high);
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
  cout << '\n';

  quickSort(arr, 0, n - 1);

  for (int i = 0; i < n; i++) {
    cout << arr[i] << (i + 1 == n ? '\n' : ' ');
  }

  return 0;
}
