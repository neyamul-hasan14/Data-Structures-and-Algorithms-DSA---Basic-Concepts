#include <iostream>
using namespace std;

// Function to calculate the Nth Fibonacci number using an optimized bottom-up approach
int fibonacci_optimized(int N) {
    // Base cases
    if (N <= 1) {
        return N;
    }
    
    // Variables to store the previous two Fibonacci numbers
    int prev2 = 0, prev1 = 1, current;
    
    // Iteratively calculate the Fibonacci numbers from 2 to N
    for (int i = 2; i <= N; i++) {
        current = prev1 + prev2;  // Calculate the current Fibonacci number
        prev2 = prev1;            // Update prev2 to the previous value of prev1
        prev1 = current;          // Update prev1 to the current Fibonacci number
    }
    
    // Return the Nth Fibonacci number
    return current;
}

int main() {
    int N;
    cout << "Enter the value of N: ";
    cin >> N;
    
    // Call the optimized Fibonacci function and display the result
    int result = fibonacci_optimized(N);
    cout << "The " << N << "th Fibonacci number is: " << result << endl;
    
    return 0;
}

/*
Time complexity: O(n)
Space complexity: O(1)

*/