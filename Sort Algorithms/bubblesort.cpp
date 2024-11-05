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

    for(int i = 0; i < n-1; i++) {
        int flag = 0;
        for(int j = 0; j < n-1-i; j++) {
            if(num[j] > num[j+1]) {
                int temp = num[j];
                num[j] = num[j+1];
                num[j+1] = temp;
                flag++;
            }
        }
        if(flag == 0) {
            break;
        }
    }

    cout << "Sorted array:" << endl;
    for(int i = 0; i < n; i++) {
        cout << num[i] << " ";
    }
    cout << endl;
    return 0;
}
