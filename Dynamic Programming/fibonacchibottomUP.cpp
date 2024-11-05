#include <iostream>
using namespace std;

// Function to calculate Nth Fibonacci number using bottom-up approach
int fibonacci(int N) {
    if (N <= 1) {
        return N;
    }

    // Variables to store previous two Fibonacci numbers
    int prev2 = 0, prev1 = 1, current;

    // Calculate Fibonacci numbers iteratively from 2 to N
    for (int i = 2; i <= N; i++) {
        current = prev1 + prev2;
        prev2 = prev1; // Shift the previous values
        prev1 = current;
    }

    return current;
}

int main() {
    int N;
    cout << "Enter the value of N: ";
    cin >> N;
    
    // Call the Fibonacci function
    int result = fibonacci(N);
    
    cout << "The " << N << "th Fibonacci number is: " << result << endl;
    
    return 0;
}



//Tabulation/Bottom-up

/*

Time Complexity: O(N) because we iterate through numbers from 2 to N.

Space Complexity: O(1) since we only use a constant amount of extra space (just a few variables).

*/