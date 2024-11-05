#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find and print the maximum number of activities
void activitySelectionDynamic(vector<pair<int, int>>& activities, int n) {
    // Sort activities based on finish time
    vector<int> indices(n);
    for (int i = 0; i < n; i++) {
        indices[i] = i + 1; // Store original index for printing
    }

    sort(indices.begin(), indices.end(), [&](int a, int b) {
        return activities[a - 1].second < activities[b - 1].second;
    });

    // Initialize a list to store selected activities
    vector<int> selectedActivities;
    
    // Select the first activity
    selectedActivities.push_back(indices[0]);

    // Keep track of the finish time of the last selected activity
    int lastFinishTime = activities[indices[0] - 1].second;

    // Iterate through the activities
    for (int i = 1; i < n; i++) {
        // If the start time of the current activity is greater than or equal to the finish time
        if (activities[indices[i] - 1].first >= lastFinishTime) {
            selectedActivities.push_back(indices[i]);
            lastFinishTime = activities[indices[i] - 1].second; // Update finish time
        }
    }

    // Output the selected activities and the count
    cout << "Selected activities: ";
    for (int i = 0; i < selectedActivities.size(); i++) {
        cout << "A" << selectedActivities[i] << " ";
    }
    cout << endl;
    cout << "Total number of selected activities: " << selectedActivities.size() << endl;
}

int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;

    vector<pair<int, int>> activities(n);

    // Input start and finish times
    cout << "Enter start and finish times of the activities (one per line):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> activities[i].first >> activities[i].second;
    }

    // Solve the activity selection problem and print the result
    activitySelectionDynamic(activities, n);

    return 0;
}
