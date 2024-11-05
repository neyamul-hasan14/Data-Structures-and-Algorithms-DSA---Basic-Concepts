#include <iostream>
#include <vector>
#include <string>
#include <set> // Include set for storing unique LCS
using namespace std;

// Function to find the length of LCS of two strings
int lcs(string X, string Y, vector<vector<int>>& dp) {
    int m = X.length();
    int n = Y.length();

    // Fill the dp array according to LCS rules
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1; // If characters match
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // If characters do not match
            }
        }
    }

    return dp[m][n];
}

// Function to print all unique LCS
void printLCS(string X, string Y, vector<vector<int>>& dp, int i, int j, string lcs_str, set<string>& lcs_set) {
    // Base case: if we reach the end of either string
    if (i == 0 || j == 0) {
        if (!lcs_str.empty()) {
            lcs_set.insert(lcs_str); // Insert the LCS found into the set
        }
        return;
    }

    // If characters match, add it to the LCS string and move diagonally
    if (X[i - 1] == Y[j - 1]) {
        lcs_str = X[i - 1] + lcs_str; // Prepend matching character
        printLCS(X, Y, dp, i - 1, j - 1, lcs_str, lcs_set);
    } else {
        // Move in the direction of the larger value in dp table
        if (dp[i - 1][j] >= dp[i][j - 1]) {
            printLCS(X, Y, dp, i - 1, j, lcs_str, lcs_set);
        }
        if (dp[i][j - 1] >= dp[i - 1][j]) {
            printLCS(X, Y, dp, i, j - 1, lcs_str, lcs_set);
        }
    }
}

int main() {
    string X, Y;

    // Taking user input for the two strings
    cout << "Enter first string (X): ";
    cin >> X;
    cout << "Enter second string (Y): ";
    cin >> Y;

    int m = X.length();
    int n = Y.length();
    
    // Create a 2D array to store lengths of longest common subsequence
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Calculate LCS length
    int length = lcs(X, Y, dp);
    
    // Output LCS length
    cout << "Length of LCS is: " << length << endl;

    // Set to hold unique LCS strings
    set<string> lcs_set;

    // Output the LCS itself
    printLCS(X, Y, dp, m, n, "", lcs_set);

    // Print all unique LCS found
    cout << "The Longest Common Subsequence(s) is/are:" << endl;
    for (const auto& seq : lcs_set) {
        cout << seq << endl;
    }

    return 0;
}






/*
Enhanced C++ Solution with Detailed Output


#include <iostream>
#include <vector>
#include <string>
#include <set> // Include set for storing unique LCS
using namespace std;

// Function to find the length of LCS of two strings
int lcs(string X, string Y, vector<vector<int>>& dp) {
    int m = X.length();
    int n = Y.length();

    // Fill the dp array according to LCS rules
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1; // If characters match
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // If characters do not match
            }
        }
    }

    return dp[m][n];
}

// Function to print all unique LCS
void printLCS(string X, string Y, vector<vector<int>>& dp, int i, int j, string lcs_str, set<string>& lcs_set) {
    // Base case: if we reach the end of either string
    if (i == 0 || j == 0) {
        if (!lcs_str.empty()) {
            lcs_set.insert(lcs_str); // Insert the LCS found into the set
        }
        return;
    }

    // If characters match, add it to the LCS string and move diagonally
    if (X[i - 1] == Y[j - 1]) {
        cout << "Matching characters: " << X[i - 1] << " (X[" << (i - 1) << "]) and Y[" << (j - 1) << "]" << endl;
        lcs_str = X[i - 1] + lcs_str; // Prepend matching character
        printLCS(X, Y, dp, i - 1, j - 1, lcs_str, lcs_set);
    } else {
        // Move in the direction of the larger value in dp table
        if (dp[i - 1][j] >= dp[i][j - 1]) {
            cout << "Comparing: X[" << (i - 1) << "] = " << X[i - 1] << " and Y[" << (j - 1) << "] = " << Y[j - 1] << " (X is greater or equal)" << endl;
            printLCS(X, Y, dp, i - 1, j, lcs_str, lcs_set);
        }
        if (dp[i][j - 1] >= dp[i - 1][j]) {
            cout << "Comparing: X[" << (i - 1) << "] = " << X[i - 1] << " and Y[" << (j - 1) << "] = " << Y[j - 1] << " (Y is greater)" << endl;
            printLCS(X, Y, dp, i, j - 1, lcs_str, lcs_set);
        }
    }
}

int main() {
    string X, Y;

    // Taking user input for the two strings
    cout << "Enter first string (X): ";
    cin >> X;
    cout << "Enter second string (Y): ";
    cin >> Y;

    int m = X.length();
    int n = Y.length();
    
    // Create a 2D array to store lengths of longest common subsequence
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Calculate LCS length
    int length = lcs(X, Y, dp);
    
    // Output LCS length
    cout << "\nLength of LCS is: " << length << endl;

    // Set to hold unique LCS strings
    set<string> lcs_set;

    // Output the LCS itself
    printLCS(X, Y, dp, m, n, "", lcs_set);

    // Print all unique LCS found
    cout << "\nThe Longest Common Subsequence(s) is/are:" << endl;
    for (const auto& seq : lcs_set) {
        cout << seq << " (Length: " << seq.length() << ")" << endl;
    }

    return 0;
}






*/

//Time Complexity: O(m×n)
//Space Complexity: O(m×n)