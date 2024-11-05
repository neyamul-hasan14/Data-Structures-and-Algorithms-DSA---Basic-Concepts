#include <iostream>
using namespace std;

// Function to calculate Nth Fibonacci number using naive recursion
int fibonacci(int N) {
    // Base cases
    if (N <= 1) {
        return N;
    }
    
    // Recursive calls for Fibonacci(N-1) and Fibonacci(N-2)
    return fibonacci(N - 1) + fibonacci(N - 2);
}

int main() {
    int N;
    cout << "Enter the value of N: ";
    cin >> N;
    
    // Call the Fibonacci function using naive recursion
    int result = fibonacci(N);
    
    cout << "The " << N << "th Fibonacci number is: " << result << endl;
    
    return 0;
}

/*
Naive Recursion
Time Complexity: O(2^N) due to the exponential growth in the number of recursive calls. Each call generates two more recursive calls, leading to significant overlap of the same subproblems being solved multiple times.
Space Complexity: O(N) due to the recursive call stack, where the depth of recursion is proportional to N.

*/