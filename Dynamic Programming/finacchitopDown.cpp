#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the Nth Fibonacci number using memoization
int fibonacci(int N, vector<int> &memo) {
    // Base cases
    if (N <= 1) {
        return N;
    }

    // If the value is already computed, return it
    if (memo[N] != -1) {
        return memo[N];
    }

    // Compute and store the result in memo array
    memo[N] = fibonacci(N - 1, memo) + fibonacci(N - 2, memo);
    
    return memo[N];
}

int main() {
    int N;
    cout << "Enter the value of N: ";
    cin >> N;
    
    // Create a memo array and initialize it to -1
    vector<int> memo(N + 1, -1);
    
    // Call the fibonacci function with memoization
    int result = fibonacci(N, memo);
    
    cout << "The " << N << "th Fibonacci number is: " << result << endl;
    
    return 0;
}
//Memoization/Top-down

/*
Time Complexity: O(N), as each Fibonacci number is calculated only once and then stored in the memo array.
Space Complexity: O(N) due to the recursion stack and the memoization array.
 */