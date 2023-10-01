#include <bits/stdc++.h>
using namespace std;

int findCeiling(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    int ceiling = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return arr[mid]; // Target found, return the target itself as the ceiling
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            ceiling = arr[mid];
            right = mid - 1;
        }
    }

    return ceiling;
}

// Function to find the floor of a target element in a sorted array
int findFloor(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    int floor = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return arr[mid]; // Target found, return the target itself as the floor
        } else if (arr[mid] < target) {
            floor = arr[mid];
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return floor;
}

int main() {
    vector<int> arr = {1, 2, 8, 10, 10, 12, 19};
    int target = 5;

    int ceiling = findCeiling(arr, target);
    int floor = findFloor(arr, target);

    cout << "Ceiling of " << target << " is: " << ceiling << endl;
    cout << "Floor of " << target << " is: " << floor << endl;

    return 0;
}
