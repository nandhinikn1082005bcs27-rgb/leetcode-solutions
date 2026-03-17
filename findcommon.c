#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

char** commonChars(char** words, int wordsSize, int* returnSize) {
    int min_freq[26];
    for (int i = 0; i < 26; i++) min_freq[i] = INT_MAX;

    // 1. Calculate frequency for each word and update global minimum
    for (int i = 0; i < wordsSize; i++) {
        int current_freq[26] = {0};
        for (int j = 0; words[i][j] != '\0'; j++) {
            current_freq[words[i][j] - 'a']++;
        }
        for (int j = 0; j < 26; j++) {
            min_freq[j] = MIN(min_freq[j], current_freq[j]);
        }
    }

    // 2. Count total common characters to allocate memory
    int total = 0;
    for (int i = 0; i < 26; i++) total += min_freq[i];

    char** result = (char**)malloc(total * sizeof(char*));
    *returnSize = 0;

    // 3. Populate the result array
    for (int i = 0; i < 26; i++) {
        while (min_freq[i] > 0) {
            result[*returnSize] = (char*)malloc(2 * sizeof(char));
            result[*returnSize][0] = i + 'a';
            result[*returnSize][1] = '\0';
            (*returnSize)++;
            min_freq[i]--;
        }
    }
    return result;
}
