#include <iostream>
#include <vector>
#include <limits>
using namespace std;

long long calculateProduct(const vector<int>& array, int start, int end)
{
    long long product = 1;
    for (int i = start; i <= end; i++) 
    {

        product *= array[i];
    }

    return product;

}

long long findMaxCrossingProduct(const vector<int>& array, int low, int mid, int high, int& start, int& end) 
{
    long long leftProduct = 1, rightProduct = 1;
    long long maxLeftProduct = numeric_limits<long long>::min();
    long long maxRightProduct = numeric_limits<long long>::min();
    int maxLeftIndex = mid, maxRightIndex = mid + 1;

    for (int i = mid; i >= low; i--) 
    {
        leftProduct *= array[i];

        if (leftProduct > maxLeftProduct) 
        {
            maxLeftProduct = leftProduct;
            maxLeftIndex = i;
        }
    }

    for (int i = mid + 1; i <= high; i++)
     {
        rightProduct *= array[i];

        if (rightProduct > maxRightProduct)
         {
            maxRightProduct = rightProduct;
            maxRightIndex = i;
        }
    }

    start = maxLeftIndex;
    end = maxRightIndex;
    return maxLeftProduct * maxRightProduct;
}

   long long findMaxProduct(const vector<int>& array, int low, int high, int& start, int& end) 
   {
    if (low == high) {
        start = low;
        end = high;
        return array[low];
    }

    int mid = (low + high) / 2;

    int leftStart, leftEnd;
    long long leftMax = findMaxProduct(array, low, mid, leftStart, leftEnd);

    int rightStart, rightEnd;
    long long rightMax = findMaxProduct(array, mid + 1, high, rightStart, rightEnd);
    

    int crossStart, crossEnd;

    long long crossMax = findMaxCrossingProduct(array, low, mid, high, crossStart, crossEnd);

    if (leftMax >= rightMax && leftMax >= crossMax) 
    {
        start = leftStart;
        end = leftEnd;
        return leftMax;
    } 
    else if (rightMax >= leftMax && rightMax >= crossMax) {
        start = rightStart;
        end = rightEnd;
        return rightMax;
    } 
    else {
        start = crossStart;
        end = crossEnd;
        return crossMax;
    }
}

int main() {

    int n;
    cin >> n;

    if (n <= 0) 
    {
        cout << "Array must have at least one element." << endl;
        return 1; 
    }

    vector<int> array(n);
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    int start = 0, end = 0;

    long long maxProduct = findMaxProduct(array, 0, n - 1, start, end);

    cout << maxProduct << endl;
    cout << "Start index: " << start << endl;
    cout << "End index: " << end << endl;

    return 0;
}
