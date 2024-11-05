#include <iostream>
#include <vector>
#include <algorithm> // For INT_MAX
#include <limits>    // For numeric limits

using namespace std;

// Function to find the minimum number of coins required to make change for amount N
int minCoins(int N, const vector<int>& coins, vector<int>& selectedCoins) {
    vector<int> dp(N + 1, numeric_limits<int>::max()); // Create a DP array initialized to a large value
    vector<int> coinUsed(N + 1, -1); // Array to track which coin was used
    dp[0] = 0; // Base case: No coins are needed to make 0

    // Iterate over each coin
    for (int coin : coins) {
        // Update the DP array for each amount from coin to N
        for (int amount = coin; amount <= N; amount++) {
            if (dp[amount - coin] != numeric_limits<int>::max() && dp[amount] > dp[amount - coin] + 1) {
                dp[amount] = dp[amount - coin] + 1; // Update minimum coins
                coinUsed[amount] = coin; // Track the coin used
            }
        }
    }

    if (dp[N] == numeric_limits<int>::max()) {
        return -1; // Return -1 if change cannot be made
    } else {
        // Backtrack to find the coins used
        int amount = N;
        while (amount > 0) {
            selectedCoins.push_back(coinUsed[amount]);
            amount -= coinUsed[amount];
        }
        return dp[N]; // Return the minimum number of coins
    }
}

int main() {
    int N; // Amount to make change for
    int m; // Number of coin denominations
    cout << "Enter the amount: ";
    cin >> N; // Read N
    cout << "Enter the number of denominations: ";
    cin >> m; // Read m

    vector<int> coins(m); // Vector to hold the coin denominations
    cout << "Enter the denominations: ";
    for (int i = 0; i < m; i++) {
        cin >> coins[i]; // Read each coin denomination
    }

    vector<int> selectedCoins; // To store the coins used
    int result = minCoins(N, coins, selectedCoins); // Call the function to find minimum coins
    if (result != -1) {
        cout << "The minimum number of coins required to make change for " << N << " is: " << result << endl;
        cout << "The selected coins are: ";
        for (int coin : selectedCoins) {
            cout << coin << " ";
        }
        cout << endl;
    } else {
        cout << "It's not possible to make change for " << N << " with the given denominations." << endl;
    }

    return 0;
}

//Tabulation method