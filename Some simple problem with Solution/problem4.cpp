#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int countRotations(const vector<int>& nums) {

    int left = 0;

    int right = nums.size() - 1;

    if (nums[left] <= nums[right]) 
    
    {
        return 0;
    }

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (mid < right && nums[mid] > nums[mid + 1])
        {
         return mid + 1;
        }
        if (mid > left && nums[mid] < nums[mid - 1])
        
        {

         return mid;
        }


        if (nums[mid] >= nums[left]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return 0; 
}

int main() {

    vector<int> array;
    string inputLine;
    
    getline(cin, inputLine);

    stringstream ss(inputLine);

    int value;
    while (ss >> value) 
    {

        array.push_back(value);
    }

    if (array.empty()) {
        cout << "Array is empty!" << endl;
        return 0;
    }

    int rotations = countRotations(array);
    
    cout << "Result: rotated " << rotations << " times" << endl;

    return 0;
}
