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

    for(int i = 0; i < n; i++) {
        int small = i;
        for(int j = i + 1; j < n; j++) {
            if(num[small] > num[j]) {
                small = j;
            }
        }
        int temp = num[small];
        num[small] = num[i];
        num[i] = temp;
    }

    cout << "Sorted array:" << endl;
    for(int i = 0; i < n; i++) {
        cout << num[i] << " ";
    }
    cout << endl;
    return 0;
}
