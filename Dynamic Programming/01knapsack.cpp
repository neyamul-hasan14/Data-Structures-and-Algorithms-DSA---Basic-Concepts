#include <iostream>
#include <vector>

using namespace std;

// Function to solve the knapsack problem
void knapsack(int n, vector<int> weights, vector<int> values, int W) {
    // Create a DP table
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Populate the DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Find the maximum profit
    int profit = dp[n][W];
    cout << "Profit: " << profit << " taka" << endl;

    // Find which items were included in the optimal solution
    cout << "Items included:\n";
    int w = W;
    for (int i = n; i > 0 && profit > 0; i--) {
        if (profit != dp[i - 1][w]) {
            cout << "item " << i << ": " << weights[i - 1] << " kg " << values[i - 1] << " taka\n";
            profit -= values[i - 1];
            w -= weights[i - 1];
        }
    }
}

int main() {
    int n, W;

    // Input number of items
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> weights(n), values(n);

    // Input weights and values
    cout << "Enter weights and values (weight value):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> weights[i] >> values[i];
    }

    // Input capacity of the knapsack
    cout << "Enter capacity of the knapsack: ";
    cin >> W;

    // Call knapsack function
    knapsack(n, weights, values, W);

    return 0;
}
/*

Time complexity: O(nW)
Space complexity: O(nW)

*/




/*
formating 


Enter number of items: 4
Enter weights and values (weight value):
4 20
3 9
2 12
1 7
Enter capacity of the knapsack: 5
Profit: 27 taka
Items included:
item 4: 1 kg 7 taka
item 1: 4 kg 20 taka

*/