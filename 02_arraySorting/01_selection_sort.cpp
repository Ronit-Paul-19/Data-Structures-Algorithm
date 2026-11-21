#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr) {
    int n = static_cast<int>(arr.size());
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
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

    selectionSort(arr);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << (i + 1 == n ? '\n' : ' ');
    }

    return 0;
}
