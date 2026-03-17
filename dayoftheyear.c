#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Helper to check for Gregorian leap years
bool isLeap(int year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

int dayOfYear(char* date) {
    // 1. Parse Year, Month, and Day using atoi or sscanf
    int y = atoi(date);       // First 4 chars
    int m = atoi(date + 5);   // Chars at index 5-6
    int d = atoi(date + 8);   // Chars at index 8-9

    // 2. Standard days in each month
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // 3. Adjust February for leap years
    if (isLeap(y)) {
        days[1] = 29;
    }

    // 4. Sum days of completed months and add current day
    int res = d;
    for (int i = 0; i < m - 1; i++) {
        res += days[i];
    }
    
    return res;
}
