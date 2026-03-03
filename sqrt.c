int mySqrt(int x) {
    if (x < 2) return x; // Base cases for 0 and 1

    int left = 1, right = x / 2;
    int ans = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        long long square = (long long)mid * mid;

        if (square == x) {
            return mid; // Found exact square root
        } else if (square < x) {
            ans = mid;      // Current mid is a candidate (floor)
            left = mid + 1; // Look for a larger value
        } else {
            right = mid - 1; // Square is too large
        }
    }

    return ans;
}
