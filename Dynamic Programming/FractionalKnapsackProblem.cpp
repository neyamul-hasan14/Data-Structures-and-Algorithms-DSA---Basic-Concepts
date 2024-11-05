#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip> // For std::setprecision

using namespace std;

// Structure to represent an item
struct Item {
    int weight;
    int value;
};

// Function to compare two items based on value/weight ratio
bool compare(Item a, Item b) {
    double ratioA = (double)a.value / a.weight;
    double ratioB = (double)b.value / b.weight;
    return ratioA > ratioB; // Sort in descending order
}

// Function to solve the fractional knapsack problem
void fractionalKnapsack(int W, vector<Item>& items) {
    // Sort items by value/weight ratio
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;
    vector<pair<int, double>> itemsIncluded; // To track included items (weight, value, fraction)

    for (const auto& item : items) {
        if (W == 0) {
            break; // Knapsack is full
        }

        // If the entire item can be added
        if (item.weight <= W) {
            W -= item.weight;
            totalValue += item.value;
            itemsIncluded.push_back({item.weight, item.value}); // Store the whole item
        } else {
            // Add the fraction of the remaining item
            totalValue += item.value * ((double)W / item.weight);
            itemsIncluded.push_back({W, item.value * ((double)W / item.weight)}); // Store the fraction
            W = 0; // Knapsack is full
        }
    }

    // Output the results
    cout << "Profit: " << totalValue << " taka\n";
    cout << "Items included:\n";
    for (int i = itemsIncluded.size() - 1; i >= 0; i--) {
        // Output in reverse to show the last item first
        cout << "item " << (i + 1) << ": " << itemsIncluded[i].first << " kg " 
             << itemsIncluded[i].second << " taka\n";
    }
}

int main() {
    int n, W;

    // Input number of items
    cout << "Enter number of items: ";
    cin >> n;

    vector<Item> items(n);

    // Input weights and values
    cout << "Enter weights and values (weight value):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> items[i].weight >> items[i].value;
    }

    // Input capacity of the knapsack
    cout << "Enter capacity of the knapsack: ";
    cin >> W;

    // Call fractional knapsack function
    fractionalKnapsack(W, items);

    return 0;
}

/*
Time Complexity: O(n log n) due to sorting.
Space Complexity: O(n) for storing items.
*/
