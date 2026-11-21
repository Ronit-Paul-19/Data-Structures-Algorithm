#include <iostream>
#include <vector>
using namespace std;

void mergeRanges(vector<int> &arr, int left, int mid, int right,
                 vector<int> &temp) {
  int i = left;
  int j = mid + 1;
  int k = left;

  while (i <= mid && j <= right) {
    if (arr[i] <= arr[j]) {
      temp[k++] = arr[i++];
    } else {
      temp[k++] = arr[j++];
    }
  }

  while (i <= mid) {
    temp[k++] = arr[i++];
  }
  while (j <= right) {
    temp[k++] = arr[j++];
  }

  for (int p = left; p <= right; p++) {
    arr[p] = temp[p];
  }
}

void mergeSort(vector<int> &arr, int left, int right, vector<int> &temp) {
  if (left >= right) {
    return;
  }

  int mid = left + (right - left) / 2;
  mergeSort(arr, left, mid, temp);
  mergeSort(arr, mid + 1, right, temp);
  mergeRanges(arr, left, mid, right, temp);
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

  vector<int> temp(n);
  mergeSort(arr, 0, n - 1, temp);

  for (int i = 0; i < n; i++) {
    cout << arr[i] << (i + 1 == n ? '\n' : ' ');
  }

  return 0;
}
