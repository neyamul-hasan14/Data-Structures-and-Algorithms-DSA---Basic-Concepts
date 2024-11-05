#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Supply {
    int weight;
    int usefulness;
    double usefulnessToWeightRatio;
    
    Supply(int w, int u) : weight(w), usefulness(u), usefulnessToWeightRatio(static_cast<double>(u) / w) {}
};

bool compareByRatio(const Supply& a, const Supply& b) {

    return a.usefulnessToWeightRatio > b.usefulnessToWeightRatio;
}

int main() {

    int numberOfSupplies;
    
    cout << "Number of supplies: ";
    cin >> numberOfSupplies;
    
    vector<int> supplyWeights(numberOfSupplies);
    vector<int> supplyUsefulness(numberOfSupplies);
    vector<Supply> supplyList;

    cout << "Enter weights: ";
    for (int i = 0; i < numberOfSupplies; ++i) 
    {
        cin >> supplyWeights[i];
    }

    cout << "Enter usefulness values: ";
    for (int i = 0; i < numberOfSupplies; ++i) 
    {
        cin >> supplyUsefulness[i];
    }

    for (int i = 0; i < numberOfSupplies; ++i) 
    {

        supplyList.emplace_back(supplyWeights[i], supplyUsefulness[i]);
    }

    sort(supplyList.begin(), supplyList.end(), compareByRatio);

    vector<int> helicopterCapacities;

    int capacityInput;

    cout << "Enter helicopter capacities: ";

    while (cin >> capacityInput) 
    {
        helicopterCapacities.push_back(capacityInput);
        if (cin.peek() == '\n') 
        {
            break;
        }
    }
    sort(helicopterCapacities.rbegin(), helicopterCapacities.rend());

    double totalUsefulness = 0;
    int helicoptersUsedCount = 0;

    for (size_t i = 0; i < helicopterCapacities.size(); ++i)
     {
        if (supplyList.empty()) break; 
        int currentCapacity = helicopterCapacities[i];
        ++helicoptersUsedCount;

        while (currentCapacity > 0 && !supplyList.empty()) {
            Supply& currentSupply = supplyList.front();
            if (currentSupply.weight <= currentCapacity) {
                totalUsefulness += currentSupply.usefulness;
                currentCapacity -= currentSupply.weight;
                supplyList.erase(supplyList.begin());
            } else {
                totalUsefulness += currentSupply.usefulnessToWeightRatio * currentCapacity;
                currentSupply.weight -= currentCapacity;
                currentCapacity = 0; // Capacity is now full
            }
        }
    }


    cout << "Maximum usefulness: " << totalUsefulness << endl;

    cout << "Helicopters used: " << helicoptersUsedCount << endl;

    return 0;
    
}
