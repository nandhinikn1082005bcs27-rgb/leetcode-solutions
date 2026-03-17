#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxPower(char* s) {
    int max_streak = 1;
    int current_streak = 1;
    
    // Start from the second character
    for (int i = 1; s[i] != '\0'; i++) {
        if (s[i] == s[i - 1]) {
            // Increment streak if character matches previous
            current_streak++;
        } else {
            // Reset streak on character change
            current_streak = 1;
        }
        // Always track the global maximum
        max_streak = MAX(max_streak, current_streak);
    }
    
    return max_streak;
}
