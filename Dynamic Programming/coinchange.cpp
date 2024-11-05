#include <iostream>
#include <vector>

using namespace std;

// Function to count the number of ways to make change for amount N
int countWaysToMakeChange(int N, const vector<int>& coins) {
    vector<int> dp(N + 1, 0); // Create a DP array to store the ways to make change
    dp[0] = 1; // Base case: One way to make 0 amount

    // Iterate over each coin
    for (int coin : coins) {
        // Update the DP array for each amount from coin to N
        for (int amount = coin; amount <= N; amount++) {
            dp[amount] += dp[amount - coin];
        }
    }

    return dp[N]; // Return the number of ways to make change for N
}

int main() {
    int N; // Amount to make change for
    int m; // Number of coin denominations
    cin >> N >> m; // Read N and m

    vector<int> coins(m); // Vector to hold the coin denominations
    for (int i = 0; i < m; i++) {
        cin >> coins[i]; // Read each coin denomination
    }

    int result = countWaysToMakeChange(N, coins);
    cout << result << endl; // Output the result

    return 0;
}
