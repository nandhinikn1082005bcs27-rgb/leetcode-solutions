int firstMissingPositive(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        // While current number is in valid range [1, numsSize] 
        // and not already in its correct index (nums[i] should be at index nums[i]-1)
        while (nums[i] > 0 && nums[i] <= numsSize && nums[i] != nums[nums[i] - 1]) {
            // Swap nums[i] with the element at its target position
            int targetIndex = nums[i] - 1;
            int temp = nums[i];
            nums[i] = nums[targetIndex];
            nums[targetIndex] = temp;
        }
    }

    // Second pass: Find the first index where the value doesn't match the expectation
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }

    // If all numbers from 1 to numsSize are present, return n + 1
    return numsSize + 1;
}
