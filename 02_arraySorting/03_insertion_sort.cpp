#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr) {
    int n = static_cast<int>(arr.size());
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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

    insertionSort(arr);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << (i + 1 == n ? '\n' : ' ');
    }

    return 0;
}
