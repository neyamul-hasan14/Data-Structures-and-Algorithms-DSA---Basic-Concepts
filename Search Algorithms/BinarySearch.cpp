#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " sorted elements of the array:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int key;
    cout << "Enter the key to search for: ";
    cin >> key;

    int l = 0;
    int r = n - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == key) {
            cout << "Element found at index: " << mid << endl;
            return 0;
        } else if (arr[mid] > key) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << "Element not found in the array." << endl;
    return 0;
}
