// left will point to the Minimum value that satisfies our condition
while (left < right) {
    int mid = left + (right - left) / 2;
    if (isPossible()) {
        right = mid;
    } else {
        left = mid + 1;
    }
}

// left will point to the Maximum value that satisfies our condition
while (left < right) {
    int mid = left + (right - left + 1) / 2;
    if (isPossible()) {
        left = mid;
    } else {
        right = mid - 1;
    }
}
