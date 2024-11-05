#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int num[n];
    cout << "Enter " << n << " elements of the array:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }

    for(int i = 1; i < n; i++) {
        int key = num[i];
        int r = i - 1;
        while(key < num[r] && r >= 0) {
            swap(num[r], num[r+1]);
            r--;
        }
    }

    cout << "Sorted array:" << endl;
    for(int i = 0; i < n; i++) {
        cout << num[i] << " ";
    }
    cout << endl;
    return 0;
}
