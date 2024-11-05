#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Recursive function to find the minimum number of coins
int minCoinsRecursive(int amount, const vector<int>& coins, vector<int>& coinUsed, vector<int>& selectedCoins) {
    // Base case: if amount is 0, no coins are needed
    if (amount == 0) {
        return 0;
    }

    // If the amount is negative, return a large value indicating no solution
    if (amount < 0) {
        return numeric_limits<int>::max();
    }

    int minCount = numeric_limits<int>::max(); // Initialize minCount

    // Iterate over each coin
    for (int coin : coins) {
        int count = minCoinsRecursive(amount - coin, coins, coinUsed, selectedCoins); // Recursive call

        // Check if a valid combination was found
        if (count != numeric_limits<int>::max()) {
            count++; // Include the current coin

            // Update minCount and track the coin used
            if (count < minCount) {
                minCount = count;
                coinUsed[amount] = coin; // Track the coin used for this amount
            }
        }
    }

    return minCount; // Return the minimum number of coins
}

// Function to backtrack and find the coins used
void findCoins(int amount, const vector<int>& coinUsed, vector<int>& selectedCoins) {
    while (amount > 0 && coinUsed[amount] != -1) {
        selectedCoins.push_back(coinUsed[amount]);
        amount -= coinUsed[amount];
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

    vector<int> coinUsed(N + 1, -1); // To track which coin was used
    vector<int> selectedCoins; // To store the coins used

    int result = minCoinsRecursive(N, coins, coinUsed, selectedCoins); // Call the recursive function

    if (result != numeric_limits<int>::max()) {
        cout << "The minimum number of coins required to make change for " << N << " is: " << result << endl;
        findCoins(N, coinUsed, selectedCoins); // Find which coins were used
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
//Time Complexity: O(2^N)
//Space Complexity: O(N)












/*

*******
Enter the number of coin denominations: 3
Enter the coin denominations (space-separated): 1 2 5
Enter the target amount: 5

The output will display the total number of ways to make the target amount using the given coins:

Total ways to make 5 using coins: 4
******

#include <iostream>
#include <vector>

using namespace std;

int coinChange(const vector<int>& coins, int amount) {
    // Base cases
    if (amount == 0) {
        return 1; // One way to make zero amount
    }
    if (amount < 0) {
        return 0; // No way to make a negative amount
    }

    // Initialize the total ways
    int totalWays = 0;

    // Recur for each coin
    for (int coin : coins) {
        totalWays += coinChange(coins, amount - coin);
    }

    return totalWays;
}

int main() {
    int n; // Number of coin denominations
    cout << "Enter the number of coin denominations: ";
    cin >> n; // Read the number of coins

    vector<int> coins(n); // Vector to store coin denominations
    cout << "Enter the coin denominations (space-separated): ";
    for (int i = 0; i < n; ++i) {
        cin >> coins[i]; // Read each coin denomination
    }

    int amount; // Target amount
    cout << "Enter the target amount: ";
    cin >> amount; // Read the target amount

    // Output the total ways to make the amount
    cout << "Total ways to make " << amount << " using coins: " << coinChange(coins, amount) << endl;

    return 0;
}
*/