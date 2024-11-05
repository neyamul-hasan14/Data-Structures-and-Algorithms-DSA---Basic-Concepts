#include <iostream>  
#include <vector>    

using namespace std;

int mergeAndCountInversions(vector<int>& numbers, vector<int>& tempArray, int start, int middle, int end) {
    
    int i = start;

    int j = middle + 1;
    int k = start;
    int inversionCount = 0;


    while (i <= middle && j <= end) {
        if (numbers[i] <= numbers[j]) {
            tempArray[k++] = numbers[i++];
        } else {
            tempArray[k++] = numbers[j++];
            inversionCount += (middle - i + 1);
        }
    }

    while (i <= middle) tempArray[k++] = numbers[i++];
    while (j <= end) tempArray[k++] = numbers[j++];

    for (i = start; i <= end; i++) 

    {

    numbers[i] = tempArray[i];
    
    }
    return inversionCount;
}

int mergeSortAndCountInversions(vector<int>& numbers, vector<int>& tempArray, int start, int end) {

    if (start >= end) return 0;

    int middle = start + (end - start) / 2;
    int inversionCount = 0;

    inversionCount += mergeSortAndCountInversions(numbers, tempArray, start, middle);
    inversionCount += mergeSortAndCountInversions(numbers, tempArray, middle + 1, end);
    inversionCount += mergeAndCountInversions(numbers, tempArray, start, middle, end);

    return inversionCount;
}

int countTotalInversions(vector<int>& numbers) {

    vector<int> tempArray(numbers.size());

    return mergeSortAndCountInversions(numbers, tempArray, 0, numbers.size() - 1);

}

  int main() {

    int size;
    cin >> size;

    vector<int> numbers(size);

    for (int& element : numbers) cin >> element;

    cout << "Result: " << countTotalInversions(numbers) << endl;

    return 0;
}
