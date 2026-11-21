#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &arr) {
  int n = static_cast<int>(arr.size());
  for (int i = 0; i < n - 1; i++) {
    bool swapped = false;
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
        swapped = true;
      }
    }
    if (!swapped) {
      break;
    }
  }
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

  bubbleSort(arr);

  for (int i = 0; i < n; i++) {
    cout << arr[i] << (i + 1 == n ? '\n' : ' ');
  }

  return 0;
}
