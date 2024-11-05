#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to perform activity selection
void activitySelection(vector<pair<int, int>>& activities) {
    // Sort activities based on finish time
    sort(activities.begin(), activities.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    });

    // Initialize the selected activities list
    vector<int> selectedActivities;
    
    // Select the first activity
    selectedActivities.push_back(0); // A1 is selected
    int lastFinishTime = activities[0].second; // Finish time of A1

    // Iterate through the remaining activities
    for (int i = 1; i < activities.size(); i++) {
        if (activities[i].first >= lastFinishTime) {
            selectedActivities.push_back(i); // Select this activity
            lastFinishTime = activities[i].second; // Update finish time
        }
    }

    // Output the selected activities
    cout << "Selected activities: ";
    for (int i : selectedActivities) {
        cout << "A" << (i + 1) << " "; // Print as 1-based index
    }
    cout << endl;
    cout << "Total number of selected activities: " << selectedActivities.size() << endl;
}

int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;

    // Define the activities with start and finish times
    vector<pair<int, int>> activities(n);

    // Input start and finish times for the activities
    cout << "Enter start and finish times of the activities (HH:MM format):" << endl;
    for (int i = 0; i < n; i++) {
        string startTime, finishTime;
        cout << "Activity " << (i + 1) << " (start and finish): ";
        cin >> startTime >> finishTime;

        // Convert HH:MM to minutes
        int startHour = stoi(startTime.substr(0, 2));
        int startMinute = stoi(startTime.substr(3, 2));
        int finishHour = stoi(finishTime.substr(0, 2));
        int finishMinute = stoi(finishTime.substr(3, 2));

        // Store in the activities vector
        activities[i] = {startHour * 60 + startMinute, finishHour * 60 + finishMinute};
    }

    // Solve the activity selection problem
    activitySelection(activities);

    return 0;
}
